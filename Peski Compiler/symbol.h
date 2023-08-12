#ifndef SYMBOL_H
#define SYMBOL_H

#include "type.h"
#include "expr.h"

typedef enum
{
  SYMBOL_LOCAL,
  SYMBOL_PARAM,
  SYMBOL_GLOBAL
} symbol_t;

struct symbol
{
  symbol_t kind;
  struct type *type;
  char *name;
  struct expr *value;
  int which;
};

struct symbol *symbol_create (symbol_t kind, struct type *type, char *name, struct expr *value, int which);

#endif
