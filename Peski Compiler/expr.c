#include "expr.h"
#include "decl.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "symbol.h"
#include "scope.h"
#include "param_list.h"

struct type *bool_bool_ops (struct type *lt, struct type *rt,
			    struct expr *eleft, struct expr *eright,
			    char *op);
struct type *int_bool_ops (struct type *lt, struct type *rt,
			   struct expr *eleft, struct expr *eright, char *op);
struct type *equality_ops (struct type *lt, struct type *rt,
			   struct expr *eleft, struct expr *eright, char *op);

struct expr *
expr_create (expr_t kind, struct expr *left, struct expr *right)
{
  struct expr *e = malloc (sizeof (struct expr));

  if (!e)
    return 0;

  e->kind = kind;
  e->left = left;
  e->right = right;
  e->name = 0;
  e->literal_value = 0;
  e->string_literal = 0;
  e->symbol = 0;

  return e;
}

struct expr *
expr_create_name (char *n)
{
  struct expr *e = expr_create (EXPR_NAME, 0, 0);
  int i = 0;
  while (isalnum (n[i]))
    {
      i++;
    }
  char *copy = malloc (sizeof (char) * (i));
  int j = 0;
  while (j < i)
    {
      copy[j] = n[j];
      j++;
    }
  e->name = copy;
  return e;
}

struct expr *
expr_create_integer_literal (int c)
{
  struct expr *e = expr_create (EXPR_INTEGER, 0, 0);
  e->literal_value = c;
  return e;
}

struct expr *
expr_create_boolean_literal (int c)
{
  struct expr *e = expr_create (EXPR_BOOLEAN, 0, 0);
  e->literal_value = c;
  return e;
}

struct expr *
expr_create_char_literal (char *c)
{
  struct expr *e = expr_create (EXPR_CHAR, 0, 0);
  char *copy = malloc (sizeof (char) * 2);
  copy[0] = c[1];
  e->string_literal = copy;
  return e;
}

struct expr *
expr_create_string_literal (char *str)
{
  struct expr *e = expr_create (EXPR_STRING, 0, 0);
  int i = 1;
  while (str[i] != '\"')
    {
      i++;
    }
  char *copy = malloc (sizeof (char) * (i));
  int j = 0;
  while (j < i)
    {
      copy[j] = str[j];
      j++;
    }
  e->string_literal = copy;
  return e;
}

void
expr_resolve (struct expr *e)
{
  if (!e)
    return;
  if (e->kind == EXPR_NAME)
    {
      e->symbol = scope_lookup (e->name);
      if (e->symbol)
	{
	  printf ("%s resolves to ", e->symbol->name);
	  switch (e->symbol->kind)
	    {
	    case SYMBOL_LOCAL:
	      printf ("local %d\n", e->symbol->which);
	      break;
	    case SYMBOL_PARAM:
	      printf ("param %d\n", e->symbol->which);

	      break;
	    case SYMBOL_GLOBAL:
	      printf ("global ");
	      printf ("%s\n", e->symbol->name);
	      break;
	    }
	}
      else
	{
	  printf ("resolver error: %s is not defined\n", e->name);
	  num_errors_plus ();
	}
    }
       if (e->left)
	expr_resolve (e->left);
      if (e->right)
	expr_resolve (e->right);
  
}

struct type *
expr_typecheck (struct expr *e)
{
  if (!e)
    {
      return 0;
    }
  struct param_list *paramCheck;
  struct expr *continuing;
  struct type *lt = expr_typecheck (e->left);
  struct type *rt = 0;
  if (e->kind != EXPR_FOR_BLOCK)
    {
      rt = expr_typecheck (e->right);
    }
  struct type *result = 0;
  switch (e->kind)
    {
    case EXPR_INTEGER:
      result = type_create (TYPE_INTEGER, 0, 0);
      break;
    case EXPR_STRING:
      result = type_create (TYPE_STRING, 0, 0);
      break;
    case EXPR_CHAR:
      result = type_create (TYPE_CHARACTER, 0, 0);
      break;
    case EXPR_BOOLEAN:
      result = type_create (TYPE_BOOLEAN, 0, 0);
      break;
    case EXPR_NAME:
      result = e->symbol->type;
      if (result && result->kind == TYPE_ARRAY && e->right
	  && e->right->kind == EXPR_BRACKET_LIST)
	{
	  result = result->subtype;
	}
      break;
    case EXPR_BRACE_GRP:
      result = type_create (TYPE_ARRAY, expr_typecheck (e->right), 0);
      break;
    case EXPR_SUB:
      if (!type_equals (lt, type_create (TYPE_INTEGER, 0, 0))
	  && !type_equals (rt, type_create (TYPE_INTEGER, 0, 0)))
	{
	 num_errors_plus();
	       	printf
	    ("typechecking error: you cannot subtract using a non-integer ");
	  type_print (lt);
	  printf ("value (");
	  expr_print (e->left);
	  printf (") and a ");
	  type_print (rt);
	  expr_print (e->right);
	  printf (") \n");
	}
      else if (!type_equals (lt, type_create (TYPE_INTEGER, 0, 0)))
	{
	  num_errors_plus();
		printf
	    ("typechecking error: you cannot subtract using a non-integer ");
	  type_print (lt);
	  printf ("value (");
	  expr_print (e->left);
	  printf (") \n");
	}
      else if (!type_equals (rt, type_create (TYPE_INTEGER, 0, 0)))
	{
	  num_errors_plus();
		printf
	    ("typechecking error: you cannot subtract using a non-integer ");
	  type_print (rt);
	  printf ("value (");
	  expr_print (e->right);
	  printf (") \n");
	}
      result = type_create (TYPE_INTEGER, 0, 0);
      break;
    case EXPR_ADD:
      if (!type_equals (lt, type_create (TYPE_INTEGER, 0, 0))
	  && !type_equals (rt, type_create (TYPE_INTEGER, 0, 0)))
	{
	  num_errors_plus();
	  printf ("typechecking error: you cannot add a non-integer ");
	  type_print (lt);
	  printf ("value (");
	  expr_print (e->left);
	  printf (") and a ");
	  type_print (rt);
	  expr_print (e->right);
	  printf (") \n");
	}
      else if (!type_equals (lt, type_create (TYPE_INTEGER, 0, 0)))
	{
	num_errors_plus();
	  printf ("typechecking error: you cannot add a non-integer ");
	  type_print (lt);
	  printf ("value (");
	  expr_print (e->left);
	  printf (") \n");
	}
      else if (!type_equals (rt, type_create (TYPE_INTEGER, 0, 0)))
	{
		num_errors_plus();
	  printf ("typechecking error: you cannot add a non-integer ");
	  type_print (rt);
	  printf ("value (");
	  expr_print (e->right);
	  printf (") \n");
	}
      result = type_create (TYPE_INTEGER, 0, 0);
      break;
    case EXPR_DIV:
      if (!type_equals (lt, type_create (TYPE_INTEGER, 0, 0))
	  && !type_equals (rt, type_create (TYPE_INTEGER, 0, 0)))
	{
		num_errors_plus();
	  printf
	    ("typechecking error: you cannot divide using a non-integer ");
	  type_print (lt);
	  printf ("value (");
	  expr_print (e->left);
	  printf (") and a ");
	  type_print (rt);
	  expr_print (e->right);
	  printf (") \n");
	}
      else if (!type_equals (lt, type_create (TYPE_INTEGER, 0, 0)))
	{
		num_errors_plus();
	  printf
	    ("typechecking error: you cannot divide using a non-integer ");
	  type_print (lt);
	  printf ("value (");
	  expr_print (e->left);
	  printf (") \n");
	}
      else if (!type_equals (rt, type_create (TYPE_INTEGER, 0, 0)))
	{
		num_errors_plus();
	  printf
	    ("typechecking error: you cannot divide using a non-integer ");
	  type_print (rt);
	  printf ("value (");
	  expr_print (e->right);
	  printf (") \n");
	}
      result = type_create (TYPE_INTEGER, 0, 0);
      break;
    case EXPR_MUL:
      if (!type_equals (lt, type_create (TYPE_INTEGER, 0, 0))
	  && !type_equals (rt, type_create (TYPE_INTEGER, 0, 0)))
	{
		num_errors_plus();
	  printf ("typechecking error: you cannot multiply a non-integer ");
	  type_print (lt);
	  printf ("value (");
	  expr_print (e->left);
	  printf (") and a ");
	  type_print (rt);
	  expr_print (e->right);
	  printf (") \n");
	}
      else if (!type_equals (lt, type_create (TYPE_INTEGER, 0, 0)))
	{
		num_errors_plus();
	  printf ("typechecking error: you cannot multiply a non-integer ");
	  type_print (lt);
	  printf ("value (");
	  expr_print (e->left);
	  printf (") \n");
	}
      else if (!type_equals (rt, type_create (TYPE_INTEGER, 0, 0)))
	{
		num_errors_plus();
	  printf ("typechecking error: you cannot multiply a non-integer ");
	  type_print (rt);
	  printf ("value (");
	  expr_print (e->right);
	  printf (") \n");
	}
      result = type_create (TYPE_INTEGER, 0, 0);
      break;

    case EXPR_MOD:
      if (!type_equals (lt, type_create (TYPE_INTEGER, 0, 0))
	  && !type_equals (rt, type_create (TYPE_INTEGER, 0, 0)))
	{
		num_errors_plus();
	  printf
	    ("typechecking error: you cannot modulo using a non-integer ");
	  type_print (lt);
	  printf ("value (");
	  expr_print (e->left);
	  printf (") and a ");
	  type_print (rt);
	  expr_print (e->right);
	  printf (") \n");
	}
      else if (!type_equals (lt, type_create (TYPE_INTEGER, 0, 0)))
	{
		num_errors_plus();
	  printf
	    ("typechecking error: you cannot modulo using a non-integer ");
	  type_print (lt);
	  printf ("value (");
	  expr_print (e->left);
	  printf (") \n");
	}
      else if (!type_equals (rt, type_create (TYPE_INTEGER, 0, 0)))
	{
		num_errors_plus();
	  printf
	    ("typechecking error: you cannot modulo using a non-integer ");
	  type_print (rt);
	  printf ("value (");
	  expr_print (e->right);
	  printf (") \n");
	}
      result = type_create (TYPE_INTEGER, 0, 0);
      break;
    case EXPR_EXPONENT:
      if (!type_equals (lt, type_create (TYPE_INTEGER, 0, 0))
	  && !type_equals (rt, type_create (TYPE_INTEGER, 0, 0)))
	{
		num_errors_plus();
	  printf
	    ("typechecking error: you cannot exponentiate a non-integer ");
	  type_print (lt);
	  printf ("value (");
	  expr_print (e->left);
	  printf (") and a ");
	  type_print (rt);
	  expr_print (e->right);
	  printf (") \n");
	}
      else if (!type_equals (lt, type_create (TYPE_INTEGER, 0, 0)))
	{
		num_errors_plus();
	  printf
	    ("typechecking error: you cannot exponentiate a non-integer ");
	  type_print (lt);
	  printf ("value (");
	  expr_print (e->left);
	  printf (") \n");
	}
      else if (!type_equals (rt, type_create (TYPE_INTEGER, 0, 0)))
	{
		num_errors_plus();
	  printf
	    ("typechecking error: you cannot exponentiate a non-integer ");
	  type_print (rt);
	  printf ("value (");
	  expr_print (e->right);
	  printf (") \n");
	}
      result = type_create (TYPE_INTEGER, 0, 0);
      break;
    case EXPR_INCREMENT:
      if (!type_equals (lt, type_create (TYPE_INTEGER, 0, 0)))
	{
		num_errors_plus();
	  printf ("typechecking error: you cannot increment a non-integer ");
	  type_print (lt);
	  printf ("value (");
	  expr_print (e->left);
	  printf (") \n");
	}
      result = type_create (TYPE_INTEGER, 0, 0);
      break;
    case EXPR_DECREMENT:
      if (!type_equals (lt, type_create (TYPE_INTEGER, 0, 0)))
	{
		num_errors_plus();
	  printf ("typechecking error: you cannot decrement a non-integer ");
	  type_print (lt);
	  printf ("value (");
	  expr_print (e->left);
	  printf (") \n");
	}
      result = type_create (TYPE_INTEGER, 0, 0);
      break;
    case EXPR_AND:
      result = bool_bool_ops (lt, rt, e->left, e->right, "and operator (&&)");
      break;
    case EXPR_OR:
      result = bool_bool_ops (lt, rt, e->left, e->right, "or operator (||)");
      break;
    case EXPR_GT:
      result =
	int_bool_ops (lt, rt, e->left, e->right, "greater than operator (>)");
      break;
    case EXPR_GE:
      result =
	int_bool_ops (lt, rt, e->left, e->right,
		      "greater than or equalto operator (>=)");
      break;
    case EXPR_LT:
      result =
	int_bool_ops (lt, rt, e->left, e->right, "less than operator (<)");
      break;
    case EXPR_LE:
      result =
	int_bool_ops (lt, rt, e->left, e->right,
		      "less than or equalto operator (<=)");
      break;
    case EXPR_EQUALS:
      result =
	equality_ops (lt, rt, e->left, e->right, "equality operator (==)");
      break;
    case EXPR_NOT_EQUALS:
      result =
	equality_ops (lt, rt, e->left, e->right,
		      "non-equality operator (!=)");
      break;
    case EXPR_NOT:
      if (!type_equals (rt, type_create (TYPE_BOOLEAN, 0, 0)))
	{
		num_errors_plus();
	  printf
	    ("typechecking error: you cannot use not operator (!) on a non-integer ");
	  type_print (rt);
	  printf ("value (");
	  expr_print (e->right);
	  printf (") \n");
	}
      result = type_create (TYPE_BOOLEAN, 0, 0);
      break;
    case EXPR_ARG:
      result = expr_typecheck (e->left);
      break;
    case EXPR_BLOCK:
      result = type_copy (rt);
      break;
    case EXPR_FOR_BLOCK:
      result = type_copy (lt);;
      break;
    case EXPR_ASSIGN:
      if (!type_equals (lt, rt))
	{
		num_errors_plus();
	  printf ("type error: you cannot set variable of type ");
	  type_print (lt);
	  printf ("(");
	  expr_print (e->left);
	  printf (") to value of type ");
	  type_print (rt);
	  printf ("(");
	  expr_print (e->right);
	  printf (")\n");
	}
      result = 0;
      break;
    case EXPR_FCALL:
      result = type_copy (lt);
      if (e->right)
	{
	  if (e->right->kind != EXPR_ARG)
	    {
	      if (result->params && result->params->type
		  && !type_equals (rt, result->params->type))
		{
			num_errors_plus();
		  printf
		    ("typechecking error: you are trying to call the function ");
		  expr_print (e->left);
		  printf (" with a parameter of type ");
		  type_print (rt);
		  printf ("(");
		  expr_print (e->right);
		  printf
		    ("), when that function should be taking a parameter of type ");
		  type_print (result->params->type);
		  printf ("in that position\n");
		}
	      else if (!result->params)
		{
			num_errors_plus();
		  printf
		    ("typechecking error: you are trying to call the function ");
		  expr_print (e->left);
		  printf
		    (" with too many parameters. The parameter of type ");
		  type_print (rt);
		  printf ("(");
		  expr_print (e->right);
		  printf
		    (") is excessive; reduce the number of parameters in this function call\n");
		}
	    }
	  else
	    {
	      paramCheck = result->params;
	      continuing = e->right;
	      while (continuing || paramCheck)
		{
		  if (continuing && paramCheck && paramCheck->type
		      && !type_equals (expr_typecheck (continuing),
				       paramCheck->type))
		    {
			    num_errors_plus();
		      printf
			("typechecking error: you are trying to call the function ");
		      expr_print (e->left);
		      printf (" with a parameter of type ");
		      type_print (expr_typecheck (continuing));
		      printf ("(");
		      expr_print (continuing);
		      printf
			("), when that function should be taking a parameter of type ");
		      type_print (paramCheck->type);
		      printf ("in that position\n");
		    }
		  else if (continuing && !paramCheck)
		    {
			    num_errors_plus();
		      printf
			("typechecking error: you are trying to call the function ");
		      expr_print (e->left);
		      printf
			(" with too many parameters. The parameter of type ");
		      type_print (expr_typecheck (continuing));
		      printf ("(");
		      if(continuing->kind != EXPR_ARG) {expr_print (continuing);}
		      else {expr_print (continuing->left);}
		      printf
			(") is excessive; reduce the number of parameters in this function call\n");
		    }
		  else if (!continuing && paramCheck)
		  {
			  num_errors_plus();
			  printf("typechecking error: you are trying to call the function ");
			  expr_print (e->left);
			  printf(" with not enough parameters. You need another parameter of type ");
			  type_print (paramCheck->type);
			  printf("in your function call.\n");
		  }
		  if (paramCheck)
		    {
		      paramCheck = paramCheck->next;
		    }
		  else
		    {
		      paramCheck = 0;
		    }
		  if (continuing)
		    {
		      continuing = continuing->right;
		    }
		  else
		    {
		      continuing = 0;
		    }
		}
	    }

	}
      else if (result->params && result->params->type) {
       	  num_errors_plus();
	      printf("typechecking error: you are trying to call the function ");
	  expr_print (e->left);
	  printf(" with not enough parameters. You need these parameters: ");
	  param_list_print(result->params);
	  printf("in your function call.\n");
      }
      result = result->subtype;
      break;
    case EXPR_ARRAY:
      result = type_copy (lt);
      result = result->subtype;
      break;
    }
  return result;
}

struct type *
bool_bool_ops (struct type *lt, struct type *rt, struct expr *eleft,
	       struct expr *eright, char *op)
{
  if (!type_equals (lt, type_create (TYPE_BOOLEAN, 0, 0))
      && !type_equals (rt, type_create (TYPE_BOOLEAN, 0, 0)))
    {
	    num_errors_plus();
      printf ("typechecking error: you cannot use %s using a non-boolean ",
	      op);
      type_print (lt);
      printf ("value (");
      expr_print (eleft);
      printf (") and a ");
      type_print (rt);
      expr_print (eright);
      printf (") \n");
    }
  else if (!type_equals (lt, type_create (TYPE_BOOLEAN, 0, 0)))
    {
	    num_errors_plus();
      printf ("typechecking error: you cannot use %s using a non-boolean ",
	      op);
      type_print (lt);
      printf ("value (");
      expr_print (eleft);
      printf (") \n");
    }
  else if (!type_equals (rt, type_create (TYPE_BOOLEAN, 0, 0)))
    {
	    num_errors_plus();
      printf ("typechecking error: you cannot use %s using a non-boolean ",
	      op);
      type_print (rt);
      printf ("value (");
      expr_print (eright);
      printf (") \n");
    }
  return type_create (TYPE_BOOLEAN, 0, 0);

}

struct type *
equality_ops (struct type *lt, struct type *rt, struct expr *eleft,
	      struct expr *eright, char *op)
{
  if (!type_equals (lt, rt))
    {
	    num_errors_plus();
      printf
	("typechecking error: you cannot compare types of different values; value ");
      expr_print (eleft);
      printf (" is of type ");
      type_print (lt);
      printf (" but ");
      expr_print (eright);
      printf (" is of opposing type ");
      type_print (rt);
      printf (" \n");
    }
  if (!
      (type_equals (lt, type_create (TYPE_INTEGER, 0, 0))
       || type_equals (lt, type_create (TYPE_BOOLEAN, 0, 0))
       || type_equals (lt, type_create (TYPE_STRING, 0, 0))
       || type_equals (lt, type_create (TYPE_CHARACTER, 0, 0))))
    {
	    num_errors_plus();
      printf ("typechecking error: you cannot use %s on values of type ", op);
      type_print (lt);
      printf (" and value ");
      expr_print (eleft);
      printf (" is of type ");
      type_print (lt);
      printf ("\n");
    }
  if (!
      (type_equals (rt, type_create (TYPE_INTEGER, 0, 0))
       || type_equals (rt, type_create (TYPE_BOOLEAN, 0, 0))
       || type_equals (rt, type_create (TYPE_STRING, 0, 0))
       || type_equals (rt, type_create (TYPE_CHARACTER, 0, 0))))
    {
	    num_errors_plus();
      printf ("typechecking error: you cannot use %s on values of type ", op);
      type_print (rt);
      printf (" and value ");
      expr_print (eright);
      printf (" is of type ");
      type_print (rt);
      printf ("\n");
    }
  return type_create (TYPE_BOOLEAN, 0, 0);
}

struct type *
int_bool_ops (struct type *lt, struct type *rt, struct expr *eleft,
	      struct expr *eright, char *op)
{
  if (!type_equals (lt, type_create (TYPE_INTEGER, 0, 0))
      && !type_equals (rt, type_create (TYPE_INTEGER, 0, 0)))
    {
	    num_errors_plus();
      printf ("typechecking error: you cannot use %s using a non-integer ",
	      op);
      type_print (lt);
      printf ("value (");
      expr_print (eleft);
      printf (") and a ");
      type_print (rt);
      expr_print (eright);
      printf (") \n");
    }
  else if (!type_equals (lt, type_create (TYPE_INTEGER, 0, 0)))
    {
	    num_errors_plus();
      printf ("typechecking error: you cannot use %s using a non-integer ",
	      op);
      type_print (lt);
      printf ("value (");
      expr_print (eleft);
      printf (") \n");
    }
  else if (!type_equals (rt, type_create (TYPE_INTEGER, 0, 0)))
    {
	    num_errors_plus();
      printf ("typechecking error: you cannot use %s using a non-integer ",
	      op);
      type_print (rt);
      printf ("value (");
      expr_print (eright);
      printf (") \n");
    }
  return type_create (TYPE_BOOLEAN, 0, 0);

}

void expr_translate(struct expr *e)
{
  if (!e)
    {
      return;
    }

  if (e->left)
    {
      expr_translate (e->left);
    }
  switch (e->kind)
    {
    case EXPR_ADD:
      printf ("+");
      break;
    case EXPR_SUB:
      printf ("-");
      break;
    case EXPR_NEGATIVE:
      printf ("-");
      break;
    case EXPR_MOD:
      printf ("%%");
      break;
    case EXPR_MUL:
      printf ("*");
      break;
    case EXPR_DIV:
      printf ("/");
      break;
    case EXPR_EXPONENT:
      printf ("^");
      break;
    case EXPR_AND:
      printf ("&&");
      break;
    case EXPR_OR:
      printf ("||");
      break;
    case EXPR_GE:
      printf (">=");
      break;
    case EXPR_FCALL:
      printf ("(");
      if (e->right)
    {
      expr_translate (e->right);
    }
      printf (")");
      return;
      break;
    case EXPR_FOR_BLOCK:
      if (e->right)
    {
      printf (";");
    }
      break;
    case EXPR_GT:
      printf (">");
      break;
    case EXPR_LT:
      printf ("<");
      break;
    case EXPR_LE:
      printf ("<=");
      break;
    case EXPR_EQUALS:
      printf ("==");
      break;
    case EXPR_INCREMENT:
      printf ("++");
      break;
    case EXPR_DECREMENT:
      printf ("--");
      break;
    case EXPR_ASSIGN:
      printf ("=");
      break;
    case EXPR_NOT_EQUALS:
      printf ("!=");
      break;
    case EXPR_ARG:
      printf (",");
      break;
    case EXPR_NOT:
      printf ("!");
      break;
    case EXPR_BLOCK:
      printf ("(");
      if (e->right)
    {
      expr_translate (e->right);
    }
      printf (")");
      return;
      break;
    case EXPR_BRACE_GRP:
      printf ("{");
      if (e->right)
    {
      expr_translate (e->right);
    }
      printf ("}");
      return;
      break;
    case EXPR_BRACKET_LIST:
      printf ("[");
      if (e->right)
    {
      expr_translate (e->right);
    }
      printf ("]");
      return;
      break;
    case EXPR_INTEGER:
      printf ("%d", e->literal_value);
      break;
    case EXPR_STRING:
      printf (e->string_literal);
      printf ("\"");
      break;
    case EXPR_CHAR:
      printf ("\'");
      printf (e->string_literal);
      printf ("\'");
      break;
    case EXPR_NAME:
      printf (e->name);
      break;
    case EXPR_BOOLEAN:
      if (e->literal_value == 1)
    {
      printf ("true");
    }
      else
    {
      printf ("false");
    }
      break;
    }
  if (e->right)
    {
      expr_translate (e->right);
    }
}

void
expr_print (struct expr *e)
{
  if (!e)
    {
      return;
    }

  if (e->left)
    {
      expr_print (e->left);
    }
  switch (e->kind)
    {
    case EXPR_ADD:
      printf ("+");
      break;
    case EXPR_SUB:
      printf ("-");
      break;
    case EXPR_NEGATIVE:
      printf ("-");
      break;
    case EXPR_MOD:
      printf ("%%");
      break;
    case EXPR_MUL:
      printf ("*");
      break;
    case EXPR_DIV:
      printf ("/");
      break;
    case EXPR_EXPONENT:
      printf ("^");
      break;
    case EXPR_AND:
      printf ("&&");
      break;
    case EXPR_OR:
      printf ("||");
      break;
    case EXPR_GE:
      printf (">=");
      break;
    case EXPR_FCALL:
      printf ("<3");
      if (e->right)
	{
	  expr_print (e->right);
	}
      printf ("<3");
      return;
      break;
    case EXPR_FOR_BLOCK:
      if (e->right)
	{
	  printf (";");
	}
      break;
    case EXPR_GT:
      printf (">");
      break;
    case EXPR_LT:
      printf ("<");
      break;
    case EXPR_LE:
      printf ("<=");
      break;
    case EXPR_EQUALS:
      printf ("==");
      break;
    case EXPR_INCREMENT:
      printf ("++");
      break;
    case EXPR_DECREMENT:
      printf ("--");
      break;
    case EXPR_ASSIGN:
      printf ("=");
      break;
    case EXPR_NOT_EQUALS:
      printf ("!=");
      break;
    case EXPR_ARG:
      printf (",");
      break;
    case EXPR_NOT:
      printf ("!");
      break;
    case EXPR_BLOCK:
      printf ("(");
      if (e->right)
	{
	  expr_print (e->right);
	}
      printf (")");
      return;
      break;
    case EXPR_BRACE_GRP:
      printf ("{");
      if (e->right)
	{
	  expr_print (e->right);
	}
      printf ("}");
      return;
      break;
    case EXPR_BRACKET_LIST:
      printf ("[");
      if (e->right)
	{
	  expr_print (e->right);
	}
      printf ("]");
      return;
      break;
    case EXPR_INTEGER:
      printf ("%d", e->literal_value);
      break;
    case EXPR_STRING:
      printf (e->string_literal);
      printf ("\"");
      break;
    case EXPR_CHAR:
      printf ("\'");
      printf (e->string_literal);
      printf ("\'");
      break;
    case EXPR_NAME:
      printf (e->name);
      break;
    case EXPR_BOOLEAN:
      if (e->literal_value == 1)
	{
	  printf ("true");
	}
      else
	{
	  printf ("false");
	}
      break;
    }
  if (e->right)
    {
      expr_print (e->right);
    }
}
