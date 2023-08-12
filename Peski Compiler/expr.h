#ifndef EXPR_H
#define EXPR_H

#include <stdlib.h>
#include "symbol.h"

typedef enum
{
  EXPR_ADD,
  EXPR_SUB,
  EXPR_MUL,
  EXPR_DIV,
  EXPR_MOD,
  EXPR_EXPONENT,
  EXPR_AND,
  EXPR_OR,
  EXPR_GE,
  EXPR_GT,
  EXPR_LE,
  EXPR_LT,
  EXPR_EQUALS,
  EXPR_FCALL,
  EXPR_INCREMENT,
  EXPR_DECREMENT,
  EXPR_ASSIGN,
  EXPR_BLOCK,
  EXPR_BRACE_GRP,
  EXPR_NOT_EQUALS,
  EXPR_VALUE,
  EXPR_SUBSCRIPT,
  EXPR_FOR_BLOCK,
  EXPR_ARG,
  EXPR_NAME,
  EXPR_INTEGER,
  EXPR_BRACKET_LIST,
  EXPR_BOOLEAN,
  EXPR_CHAR,
  EXPR_STRING,
  EXPR_ARRAY,
  EXPR_NEGATIVE,
  EXPR_NOT,
  EXPR_INTEGER_LITERAL,
  EXPR_STRING_LITERAL,
  EXPR_BOOLEAN_LITERAL,
  EXPR_CHAR_LITERAL
    /* many more kinds of exprs to add here */
} expr_t;

struct expr
{
  /* used by all kinds of exprs */
  expr_t kind;
  struct expr *left;
  struct expr *right;

  /* used by various leaf exprs */
  char *name;
  int literal_value;
  char *string_literal;
  struct symbol *symbol;
};

struct expr *expr_create (expr_t kind, struct expr *left, struct expr *right);

struct expr *expr_create_name (char *n);
struct expr *expr_create_integer_literal (int c);
struct expr *expr_create_boolean_literal (int c);
struct expr *expr_create_char_literal (char *c);
struct expr *expr_create_string_literal (char *str);
void expr_resolve( struct expr *e );
void expr_translate(struct expr *e);
void expr_print (struct expr *e);
struct type * expr_typecheck( struct expr *e );


#endif
