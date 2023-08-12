#include "stmt.h"
#include "type.h"
#include "scope.h"

struct stmt * stmt_create (stmt_t kind, struct decl *decl, struct expr *init_expr,
	     struct expr *expr, struct expr *next_expr, struct stmt *body,
	     struct stmt *else_body, struct stmt *next)
{
  struct stmt *s = malloc (sizeof (struct stmt));
  s->kind = kind;
  s->decl = decl;
  s->init_expr = init_expr;
  s->expr = expr;
  s->next_expr = next_expr;
  s->body = body;
  s->else_body = else_body;
  s->next = next;
  return s;
}

void stmt_resolve( struct stmt *s ) 
{
	if(!s) {
		return;
	}
	switch (s->kind)
	{
		case STMT_EXPR:
			expr_resolve(s->expr);
			break;
		case STMT_DECL:
			decl_resolve(s->decl);
			break;
		case STMT_RETURN:
			expr_resolve(s->expr);
			break;
		case STMT_WHILE:
			expr_resolve(s->expr);
			scope_enter();
			stmt_resolve(s->body);
			scope_exit();
			break;
		case STMT_BLOCK:
			scope_enter();
			stmt_resolve(s->body);
			scope_exit();
			break;
		case STMT_PRINT:
			expr_resolve(s->expr);
			break;
		case STMT_FOR:
			expr_resolve(s->expr);
			scope_enter();
			stmt_resolve(s->body);
			scope_exit();
			break;
		case STMT_IF_ELSE:
			expr_resolve(s->expr);
			scope_enter();
			stmt_resolve(s->body);
			scope_exit();
			scope_enter();
			stmt_resolve(s->else_body);
			scope_exit();
			break;
		default:
			break;
	}
	stmt_resolve(s->next);
}

void stmt_typecheck( struct stmt *s, struct decl *d )
{
	if(!s)
	{
		return;
	}
	struct type *t;
	switch(s->kind) {
		case STMT_EXPR:
			t = expr_typecheck(s->expr);
			type_delete(t);
			break;
		case STMT_IF_ELSE:
			t = expr_typecheck(s->expr);
			if(t->kind!=TYPE_BOOLEAN) {
				if(!type_equals(expr_typecheck(s->expr),type_create (TYPE_BOOLEAN, 0, 0))) {
					num_errors_plus();
					printf("typechecking error: you cannot use a non-boolean, ");
					type_print(expr_typecheck(s->expr));
					printf("expression (");
					expr_print(s->expr);
					printf(") to evaluate an if statement. Use a boolean expression!\n");
				}

			}
			type_delete(t);
			stmt_typecheck(s->body, d);
			stmt_typecheck(s->else_body, d);
			break;
		case STMT_DECL:
			decl_typecheck(s->decl);
			break;
		case STMT_WHILE:
			if(!type_equals(expr_typecheck(s->expr),type_create (TYPE_BOOLEAN, 0, 0))) {
				num_errors_plus();
				printf("typechecking error: you cannot use a non-boolean, ");
				type_print(expr_typecheck(s->expr));
				printf("expression (");
				expr_print(s->expr);
				printf(") to evaluate a while loop. Use a boolean expression!\n");
			}
			expr_typecheck(s->expr);
			stmt_typecheck(s->body, d);
			break;
		case STMT_FOR:
			if(s->expr->right && !type_equals(expr_typecheck(s->expr->right),type_create (TYPE_BOOLEAN, 0, 0))) {
				num_errors_plus();
				printf("typechecking error: you cannot use a non-boolean, ");
				type_print(expr_typecheck(s->expr->right));
				printf("expression (");
				expr_print(s->expr->right->left);
				printf(") to evaluate a for loop. Use a boolean expression!\n");
			}
			expr_typecheck(s->expr);
			if(s->expr->right) {
				expr_typecheck(s->expr->right->right);
			}
			stmt_typecheck(s->body, d);
			break;
		case STMT_RETURN:
			t = expr_typecheck(s->expr);
	                if(!type_equals(t,d->type->subtype)) {
	                	num_errors_plus();
				printf("type error: you cannot return ");
                        	type_print(t);
                      		printf("value (");
                        	expr_print(s->expr);
                        	printf(") in function with return type ");
     				type_print(d->symbol->type->subtype);
				printf(" (%s)\n", d->name);
			}
			break;

			/* more cases here */
	}
	stmt_typecheck(s->next, d);
}

void stmt_translate(struct stmt *s, int indent )
{
  if(!s) {
    return;
  }
  int i = 0;
  while (i < indent)
    {
      printf ("        ");
      i++;
    }

  switch (s->kind)
    {
    case STMT_EXPR:
      expr_translate(s->expr);
      printf(";\n");
      break;
    case STMT_DECL:
      decl_translate(s->decl, 0);
      break;
    case STMT_IF_ELSE:
      printf ("if(");
      expr_translate(s->expr);
      printf (")\n");
      printf("{\n");
      stmt_translate(s->body, indent + 1);
      printf("}\n");
      if (s->else_body)
     {
      int j = 0;
      while (j < indent)
        {
          printf ("        ");
          j++;
        }
      printf ("else\n");
      printf("{\n");
      stmt_translate (s->else_body, indent);
      printf("}\n");
    }
      break;
    case STMT_FOR:
      printf ("for(");
      expr_translate(s->expr);
      printf (")\n");
      stmt_translate(s->body, indent);
      break;
    case STMT_WHILE:
      printf ("while(");
      expr_translate(s->expr);
      printf (")\n");
      printf("{\n");
      stmt_translate(s->body, indent);
      printf("}\n");
      break;
    case STMT_PRINT:
      printf ("printf(");
       if(!type_equals(expr_typecheck(s->expr),type_create(TYPE_STRING, 0, 0)))
       {
		printf("\"");
        	expr_translate(s->expr);
		printf("\"");
      }
      else
	{
		expr_translate(s->expr);
	}
      printf (");\n");
      break;
    case STMT_RETURN:
      printf ("return ");
      expr_translate(s->expr);
      printf (";\n");
      break;
    case STMT_BLOCK:
      printf ("{\n");
      stmt_translate(s->body, indent + 1);
      int j = 0;
      while (j < indent)
    {
      printf ("        ");
      j++;
    }
      printf ("}\n");
      break;
    }

  if (s->next)
    {
      stmt_translate(s->next, indent);
    }
}


void stmt_print (struct stmt *s, int indent)
{
  if(!s) {
	return;
  }
  int i = 0;
  while (i < indent)
    {
      printf ("        ");
      i++;
    }

  switch (s->kind)
    {
    case STMT_EXPR:
      expr_print(s->expr);
      printf("\n");
      break;
    case STMT_DECL:
      decl_print(s->decl, 0);
      break;
    case STMT_WHILE_EMPTY:
      printf("~				        ~");
      break;
    case STMT_IF_ELSE:
      printf ("   /\\_/\\\n              >(0 x 0)<   - ");
      expr_print (s->expr);
      printf ("\n");
      stmt_print (s->body, indent + 1);
      if (s->else_body)
	{
	  int j = 0;
	  while (j < indent)
	    {
	      printf ("        ");
	      j++;
	    }
	  printf ("{ ");
	  stmt_print (s->else_body, indent);
	  printf (" }\n");
	}
      break;
    case STMT_FOR:
      printf ("for(");
      expr_print (s->expr);
      printf (")\n");
      stmt_print (s->body, indent);
      break;
    case STMT_WHILE:
      printf ("  __(.)<                        __(.)=\n         \\____) ~~~~~~ ");
      expr_print (s->expr);
      printf (" ~~~~~ \\____)\n");
      stmt_print (s->body, indent);
      printf("      ~~~^~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~\n");
      break;
    case STMT_PRINT:
      printf ("(/`'o')/` ... (");
      expr_print (s->expr);
      printf (");\n");
      break;
    case STMT_RETURN:
      printf ("     [ ");
      expr_print (s->expr);
      printf (" ]\n             (\\(*w*)/)\n              (     )\n               L  L\n");
      break;
    case STMT_BLOCK:
      printf ("{\n");
      stmt_print (s->body, indent + 1);
      int j = 0;
      while (j < indent)
	{
	  printf ("        ");
	  j++;
	}
      printf ("}\n");
      break;
    }

  if (s->next)
    {
      stmt_print (s->next, indent);
    }
}
