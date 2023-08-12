#include "type.h"

struct type *
type_create (type_t kind, struct type *subtype, struct param_list *params)
{
  struct type *t = malloc (sizeof (struct type));
  t->kind = kind;
  t->subtype = subtype;
  t->params = params;
  t->hasLength = 0;
  return t;
}

void          type_translate( struct type *t )
{
  switch (t->kind)
    {
    case TYPE_BOOLEAN:
      printf ("bool ");
      break;
    case TYPE_VOID:
      printf("void ");
      break;
    case TYPE_CHARACTER:
      printf ("char ");
      break;
    case TYPE_INTEGER:
      printf ("int ");
      break;
    case TYPE_STRING:
      printf ("string ");
      break;
    case TYPE_ARRAY:
      printf ("array [] ");
      break;
    case TYPE_FUNCTION:
      type_translate(t->subtype);
      return;
      break;
    }
  if(t->subtype) {
    type_print(t->subtype);
  }
}

void type_print (struct type *t)
{
  switch (t->kind)
    {
    case TYPE_BOOLEAN:
      printf (" ($) ");
      break;
    case TYPE_VOID:
      printf(" void ");
      break;
    case TYPE_CHARACTER:
      printf (" =^. .^= ");
      break;
    case TYPE_INTEGER:
      printf (" ><((@> ");
      break;
    case TYPE_STRING:
      printf (" (-(-_-)_-) ");
      break;
    case TYPE_ARRAY:
      printf ("array [] ");
      break;
    case TYPE_FUNCTION:
      type_print(t->subtype);
      printf("/, , , , ,\\ ");
      if(t->params) {
	param_list_print(t->params);
      }
      printf("/, , , ,");
      return;
      break;
    }
  if(t->subtype) {
	type_print(t->subtype);
  }
}

int type_equals( struct type *a, struct type *b )
{
	if((!a && b) || (a && !b))
	{
		return 0;
	}
	if( a->kind == b->kind ) {
		if(!a->subtype && !b->subtype){
			return 1;
		} else if ( a->kind == TYPE_ARRAY ) {
			if(a->subtype && b->subtype && type_equals(a->subtype, b->subtype)) {
				return 1;
			}
			else
			{
				return 0;
			}
		} else if ( a->kind == TYPE_FUNCTION) {
			if(a->subtype && b->subtype && type_equals(a->subtype, b->subtype))  {
				return 1;
			}
			//Return true if both subtype and params
			//	are recursively equal
			else {
				return 0;
			}
		}
	} else {
		return 0;
	}
	return 0;
}

struct type * type_copy( struct type *t )
{
	if(!t)
	{
		return 0;
	}
	//struct type *c = malloc (sizeof (struct type));
	//c->kind = t->kind;
	//c->subtype = type_copy(t->subtype);
	//c->params = param_copy(t->params);
	//return c;
	struct type *c = type_create(t->kind, type_copy(t->subtype), t->params);
	c->hasLength = t->hasLength;
	//return type_create(t->kind, type_copy(t->subtype), t->params);
	return c;
	//Return a duplicate copy of t, making sure
	//	to duplicate subtype and params recursively.
}


void type_delete( struct type *t )
{
	if(!t)
	{
		return;
	}
	if(t->subtype)
	{
		type_delete(t->subtype);
	}
	if(t->params) {
		param_delete(t->params);
	}
	free(t);
	//Free all the elements of t recursively.
}


