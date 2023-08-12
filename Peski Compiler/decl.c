#include "decl.h"
#include "symbol.h"
#include "scope.h"
#include <stdio.h>
#include <string.h>
//#include "type.h"
//#include "stmt.h"

static int num_errors = 0;

struct decl *
decl_create (char *name, struct type *type, struct expr *value,
	     struct stmt *code, struct decl *next)
{
  struct decl *d = malloc (sizeof (struct decl));
  d->name = name;
  d->type = type;
  d->value = value;
  d->code = code;
  d->next = next;
  d->symbol = 0;
  return d;
}

void decl_translate(struct decl *d, int indent )
{
  if (!d)
    {
      return;
    }
  int i = 0;
  while (i < indent)
    {
      printf ("        ");
      i++;
    }
  type_translate (d->type);
  printf (d->name);
    
  if (d->value)
    {
      printf (" = ");
      expr_translate (d->value);
      printf (";\n");
    }
  else if (d->code || d->type->kind == TYPE_FUNCTION)
    {
        if(strcmp(d->name, "main")) {
            //print out params if present
            printf("( ");
            if(d->type->params) {
                param_list_translate(d->type->params);
            }
            printf(" )");
        }
        else{
            printf("(int argc, char *argv[])");
        }
        
          printf ("\n");
          i = 0;
          while (i < indent)
        {
          printf ("        ");
          i++;
        }
          printf ("{\n");
          stmt_translate (d->code, indent + 1);
          i = 0;
          while (i < indent)
        {
          printf ("        ");
          i++;
        }
          printf ("}\n");
    }
  else
    {
      printf (";\n");
    }
  if (d->next)
    {
      decl_translate (d->next, indent);
    }
}

void
decl_print (struct decl *d, int indent)
{
  if (!d)
    {
      return;
    }
  int i = 0;
  while (i < indent)
    {
      printf ("        ");
      i++;
    }
  if (d->code || d->type->kind == TYPE_FUNCTION)
    {
      printf (d->name);
      printf ("\n(\\ /) \n(. .) \no(“)(“) , , , , \\");
      type_print (d->type);
      printf ("\n");
      i = 0;
      while (i < indent)
	{
	  printf ("        ");
	  i++;
	}
      printf ("{\n");
      stmt_print (d->code, indent + 1);
      i = 0;
      while (i < indent)
	{
	  printf ("        ");
	  i++;
	}
      printf ("}\n");
    }
   else {
    type_print (d->type);
    printf (" -> ");
    printf (d->name);
     if (d->value)
     {
        printf (" \n       (^._.)^            (>._.)>  ");
        expr_print (d->value);
      }
     printf ("\n");
   }
  if (d->next)
    {
      decl_print (d->next, indent);
    }
}

int
get_num_errors ()
{
  return num_errors;
}

void
num_errors_plus ()
{
  num_errors++;
}

void
clear_errors ()
{
  num_errors = 0;
}

void
decl_resolve (struct decl *d)
{
  struct symbol *s;
  if (!d)
    {
      return;
    }

  if (scope_level () > 1)
    {
      locals_plus ();
      s =
	symbol_create (SYMBOL_LOCAL, d->type, d->name, d->value,
		       get_num_locals ());
    }
  else
    {
      if (d->type && d->type->kind == TYPE_FUNCTION && !d->code)
	{
	  s =
	    symbol_create (SYMBOL_GLOBAL, d->type, d->name,
			   expr_create (EXPR_NOT, 0, 0), 0);
	}
      else
	{
	  s = symbol_create (SYMBOL_GLOBAL, d->type, d->name, d->value, 0);
	}
    }

  if (scope_lookup_current (d->name))
    {
      struct symbol *exists = scope_lookup_current (d->name);
      if (exists->type && exists->type->kind == TYPE_FUNCTION && exists->value
	  && exists->value->kind == EXPR_NOT)
	{
	  exists->value = 0;
	}
      else
	{
	  printf ("resolver error: %s is already defined\n", d->name);
	  num_errors_plus ();
	}
      d->symbol = exists;
    }
  else{

 	 scope_bind (d->name, s);
  	d->symbol = s;
  }
  if (d->value)
    {
      expr_resolve (d->value);
    }

  if (d->code)
    {
      scope_enter ();
      param_list_resolve (d->type->params);
      stmt_resolve (d->code);
      scope_exit ();
    }
  decl_resolve (d->next);
}

void
decl_typecheck (struct decl *d)
{
  if (!d)
    {
      return;
    }
  struct param_list *arrSearch;
  //type_print(d->type);
  //printf(" \n");

  if (d->value)
    {
      struct type *t;
      t = expr_typecheck (d->value);
      if (!type_equals (t, d->symbol->type))
	{
	  num_errors_plus ();
	  printf ("type error: you cannot assign ");
	  type_print (t);
	  printf ("value (");
	  expr_print (d->value);
	  printf (") to declaration type ");
	  type_print (d->type);
	  printf (" (%s)\n", d->name);
	}
      if (d->symbol->type->kind == TYPE_ARRAY)
	{
	  if (!d->symbol->type->hasLength)
	    {
	      num_errors_plus ();
	      printf
		("typechecking error: you are attempting to declare the array %s without assigning it a length.\n",
		 d->name);
	    }
	  else if (d->symbol->type->hasLength
		   && d->symbol->type->hasLength->kind != EXPR_INTEGER)
	    {
	      num_errors_plus ();
	      printf
		("typechecking error: you are attempting to declare the length of array %s as a non-integer expression (",
		 d->name);
	      expr_print (d->symbol->type->hasLength);
	      printf
		(") Arrays can only be declared with lengths of integers. \n");
	    }
	}
    }
  if (d->code)
    {
      if (d->symbol && d->symbol->type && d->symbol->type->kind
	  && d->symbol->type->kind == TYPE_FUNCTION)
	{
	  if(!type_equals(d->symbol->type, d->type)) {
		  num_errors_plus ();
		  printf("typechecking error: you are incorrectly declaring an existing prototype of the function %s. The Prototype has the type: ", d->name);
		type_print(d->symbol->type);
		printf("\n but the fully declared function has the type: ");
		  type_print(d->type);
		 printf("\n");
	  }
	  arrSearch = d->symbol->type->params;
	  while (arrSearch)
	    {
	      if (arrSearch->type->kind == TYPE_ARRAY
		  && arrSearch->type->hasLength)
		{
		  num_errors_plus ();
		  printf
		    ("typechecking error: you are attempting to declare the parameter of type array %s by assigning it a length. Parameters of type array should not have a length declared.\n",
		     d->name);
		}
	      arrSearch = arrSearch->next;
	    }
	}
      stmt_typecheck (d->code, d);
    }
  decl_typecheck (d->next);
}
