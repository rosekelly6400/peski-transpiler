#include "symbol.h"

struct symbol * symbol_create( symbol_t kind, struct type *type, char *name, struct expr *value, int which)
{
	struct symbol* s = malloc(sizeof(struct symbol));
	s->kind = kind;
	s->type = type;
	s->name = name;
	s->value = value;
	s->which = which;
	return s;
}

