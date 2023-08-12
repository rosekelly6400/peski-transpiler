#include "param_list.h"
#include "scope.h"
#include "decl.h"
struct param_list * param_list_create( char *name, struct type *type, struct param_list *next )
{
    struct param_list *p = malloc(sizeof(struct param_list));
    p->name = name;
    p->type = type;
    p->symbol = 0;
    p->next = next;
    return p;
}


void param_list_translate( struct param_list *a )
{
    if(!a)
    {
        return;
    }
    type_translate(a->type);
    printf(a->name);
    

    if(a->next) {
    printf(", ");
    param_list_translate(a->next);
    }
}

void param_list_print( struct param_list *a )
{
    if(!a)
    {
	    return;
    }
    printf(a->name);
    printf(":");
    type_print(a->type);

    if(a->next) {
	printf(", ");
	param_list_print(a->next);
    }
}

void param_list_resolve( struct param_list *p ) 
{
	if(!p) {
		return;
	}
	
	params_plus();
	struct symbol *s = symbol_create(SYMBOL_PARAM, p->type, p->name, 0, get_num_params());
	if(scope_lookup_current(p->name)) {
		printf("resolver error: %s is already defined \n", p->name);
		num_errors_plus();
	}
	scope_bind(p->name, s);
	p->symbol = s;
	param_list_resolve(p->next);


}

int param_equals( struct param_list *a, struct param_list*b )
{
	if((!a && b) || (a && !b))
	{
		return 0;
	}
	if(type_equals(a->type, b->type)) {
		if(!a->next && !b->next) {
			return 1;
		}
		if(a->next && b->next && param_equals(a->next, b->next))
		{
			return 1;
		}
	}
	return 0;
}

struct param_list *param_copy(struct param_list* p)
{
	if(!p)
	{
		return 0;
	}
	struct param_list *c = malloc(sizeof(struct param_list));
	c->name = p->name;
	c->type = type_copy(p->type);
	c->symbol = p->symbol;
	c->next = param_copy(p->next);
	return p;
}

void param_delete( struct param_list* p )
{
	if(!p)
	{
		return;
	}
	if(p->next)
	{
		param_delete(p->next);
	}
	if(p->type)
	{
		type_delete(p->type);
	}
	if(p->name)
	{
		free(p->name);
	}
	if(p->symbol)
	{
		free(p->symbol);
	}
	free(p);
}
