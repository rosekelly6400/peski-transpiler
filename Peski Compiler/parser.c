/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_EOF = 258,
     TOKEN_WHILEA = 259,
     TOKEN_WHILEB = 260,
     TOKEN_WHILE_END = 261,
     TOKEN_PLUS = 262,
     TOKEN_IDENT = 263,
     TOKEN_EXPONENT = 264,
     TOKEN_ERROR = 265,
     TOKEN_MINUS = 266,
     TOKEN_MUL = 267,
     TOKEN_DIV = 268,
     TOKEN_STRING = 269,
     TOKEN_CHAR = 270,
     TOKEN_NUMBER = 271,
     TOKEN_FALSE = 272,
     TOKEN_DECREMENT = 273,
     TOKEN_INCREMENT = 274,
     TOKEN_ASSIGN = 275,
     TOKEN_EQUALITY = 276,
     TOKEN_HEART = 277,
     TOKEN_LT = 278,
     TOKEN_LE = 279,
     TOKEN_GT = 280,
     TOKEN_GE = 281,
     TOKEN_NOTEQUALS = 282,
     TOKEN_NEGATION = 283,
     TOKEN_MODULO = 284,
     TOKEN_AND = 285,
     TOKEN_OR = 286,
     TOKEN_LEFTPARAN = 287,
     TOKEN_RIGHTPARAN = 288,
     TOKEN_LEFTBRACKET = 289,
     TOKEN_RIGHTBRACKET = 290,
     TOKEN_CCOMMENT = 291,
     TOKEN_CPPCOMMENT = 292,
     TOKEN_TRUE = 293,
     TOKEN_ARRAY = 294,
     TOKEN_BOOLEAN = 295,
     TOKEN_CHARKEY = 296,
     TOKEN_ELSE = 297,
     TOKEN_FOR = 298,
     TOKEN_FUNCTIONA = 299,
     TOKEN_FUNCTION_MAIN = 300,
     TOKEN_FUNCTIONB = 301,
     TOKEN_FUNCTIONC = 302,
     TOKEN_FUNCTION_END = 303,
     TOKEN_IF = 304,
     TOKEN_IF_END = 305,
     TOKEN_INTEGER = 306,
     TOKEN_PRINT = 307,
     TOKEN_RETURN = 308,
     TOKEN_STRINGKEY = 309,
     TOKEN_VOID = 310,
     TOKEN_SEMICOLON = 311,
     TOKEN_COLON = 312,
     TOKEN_TILDE = 313,
     TOKEN_LEFTCURLYBRACE = 314,
     TOKEN_RIGHTCURLYBRACE = 315,
     TOKEN_COMMA = 316
   };
#endif
/* Tokens.  */
#define TOKEN_EOF 258
#define TOKEN_WHILEA 259
#define TOKEN_WHILEB 260
#define TOKEN_WHILE_END 261
#define TOKEN_PLUS 262
#define TOKEN_IDENT 263
#define TOKEN_EXPONENT 264
#define TOKEN_ERROR 265
#define TOKEN_MINUS 266
#define TOKEN_MUL 267
#define TOKEN_DIV 268
#define TOKEN_STRING 269
#define TOKEN_CHAR 270
#define TOKEN_NUMBER 271
#define TOKEN_FALSE 272
#define TOKEN_DECREMENT 273
#define TOKEN_INCREMENT 274
#define TOKEN_ASSIGN 275
#define TOKEN_EQUALITY 276
#define TOKEN_HEART 277
#define TOKEN_LT 278
#define TOKEN_LE 279
#define TOKEN_GT 280
#define TOKEN_GE 281
#define TOKEN_NOTEQUALS 282
#define TOKEN_NEGATION 283
#define TOKEN_MODULO 284
#define TOKEN_AND 285
#define TOKEN_OR 286
#define TOKEN_LEFTPARAN 287
#define TOKEN_RIGHTPARAN 288
#define TOKEN_LEFTBRACKET 289
#define TOKEN_RIGHTBRACKET 290
#define TOKEN_CCOMMENT 291
#define TOKEN_CPPCOMMENT 292
#define TOKEN_TRUE 293
#define TOKEN_ARRAY 294
#define TOKEN_BOOLEAN 295
#define TOKEN_CHARKEY 296
#define TOKEN_ELSE 297
#define TOKEN_FOR 298
#define TOKEN_FUNCTIONA 299
#define TOKEN_FUNCTION_MAIN 300
#define TOKEN_FUNCTIONB 301
#define TOKEN_FUNCTIONC 302
#define TOKEN_FUNCTION_END 303
#define TOKEN_IF 304
#define TOKEN_IF_END 305
#define TOKEN_INTEGER 306
#define TOKEN_PRINT 307
#define TOKEN_RETURN 308
#define TOKEN_STRINGKEY 309
#define TOKEN_VOID 310
#define TOKEN_SEMICOLON 311
#define TOKEN_COLON 312
#define TOKEN_TILDE 313
#define TOKEN_LEFTCURLYBRACE 314
#define TOKEN_RIGHTCURLYBRACE 315
#define TOKEN_COMMA 316




/* Copy the first part of user declarations.  */


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 2 "calc.bison"
{
	struct decl *decl;
	struct stmt *stmt;
	struct expr *expr;
	struct type *type;
	struct param_list *param_list;
	char *name;
}
/* Line 193 of yacc.c.  */
#line 228 "parser.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 85 "calc.bison"


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "decl.h"
#include "expr.h"
#include "type.h"
#include "stmt.h"
#include "param_list.h"
#include <ctype.h>
#include <string.h>

/*
Clunky: Manually declare the interface to the scanner generated by flex. 
*/

extern char *yytext;
extern int yylex();
extern int yyerror( char *str );

struct decl * parser_result = 0;



/* Line 216 of yacc.c.  */
#line 265 "parser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     8,     9,    12,    14,    23,    27,    28,
      30,    32,    36,    40,    41,    44,    49,    54,    60,    65,
      72,    77,    80,    83,    87,    89,    90,    92,    94,    98,
      99,   104,   108,   109,   114,   118,   124,   128,   130,   132,
     134,   136,   138,   142,   144,   148,   150,   154,   158,   162,
     166,   170,   174,   176,   180,   184,   186,   190,   194,   198,
     200,   204,   206,   209,   212,   214,   218,   220,   222,   224,
     226,   228,   230,   232
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    64,    22,    22,    22,    -1,    -1,    65,
      64,    -1,    75,    -1,    86,    44,    76,    46,    66,    47,
      69,    48,    -1,    45,    69,    48,    -1,    -1,    67,    -1,
      68,    -1,    68,    61,    67,    -1,    76,    57,    86,    -1,
      -1,    70,    69,    -1,    34,    77,    35,    53,    -1,    52,
      32,    77,    33,    -1,     4,    77,     5,    74,     6,    -1,
      49,    77,    73,    50,    -1,    49,    77,    73,    42,    73,
      50,    -1,    86,    22,    71,    22,    -1,    86,    19,    -1,
      86,    18,    -1,    86,    20,    77,    -1,    75,    -1,    -1,
      72,    -1,    77,    -1,    77,    61,    72,    -1,    -1,    59,
      70,    60,    73,    -1,    59,    60,    73,    -1,    -1,    58,
      70,    58,    74,    -1,    58,    58,    74,    -1,    76,    57,
      86,    20,    77,    -1,    76,    57,    86,    -1,    41,    -1,
      40,    -1,    51,    -1,    54,    -1,    55,    -1,    77,    31,
      78,    -1,    78,    -1,    78,    30,    79,    -1,    79,    -1,
      79,    25,    80,    -1,    79,    23,    80,    -1,    79,    26,
      80,    -1,    79,    24,    80,    -1,    79,    27,    80,    -1,
      79,    21,    80,    -1,    80,    -1,    80,     7,    81,    -1,
      80,    11,    81,    -1,    81,    -1,    81,    12,    82,    -1,
      81,    13,    82,    -1,    81,    29,    82,    -1,    82,    -1,
      82,     9,    83,    -1,    83,    -1,    11,    84,    -1,    28,
      84,    -1,    84,    -1,    32,    77,    33,    -1,    85,    -1,
      16,    -1,    86,    -1,    15,    -1,    14,    -1,    38,    -1,
      17,    -1,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   114,   114,   117,   118,   121,   122,   123,   126,   127,
     130,   131,   135,   138,   139,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   154,   155,   158,   159,   162,
     163,   164,   167,   168,   169,   172,   173,   176,   177,   178,
     179,   180,   183,   184,   187,   188,   191,   192,   193,   194,
     195,   196,   197,   201,   202,   203,   206,   207,   208,   209,
     212,   213,   216,   217,   218,   221,   222,   225,   226,   227,
     228,   229,   230,   233
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_EOF", "TOKEN_WHILEA",
  "TOKEN_WHILEB", "TOKEN_WHILE_END", "TOKEN_PLUS", "TOKEN_IDENT",
  "TOKEN_EXPONENT", "TOKEN_ERROR", "TOKEN_MINUS", "TOKEN_MUL", "TOKEN_DIV",
  "TOKEN_STRING", "TOKEN_CHAR", "TOKEN_NUMBER", "TOKEN_FALSE",
  "TOKEN_DECREMENT", "TOKEN_INCREMENT", "TOKEN_ASSIGN", "TOKEN_EQUALITY",
  "TOKEN_HEART", "TOKEN_LT", "TOKEN_LE", "TOKEN_GT", "TOKEN_GE",
  "TOKEN_NOTEQUALS", "TOKEN_NEGATION", "TOKEN_MODULO", "TOKEN_AND",
  "TOKEN_OR", "TOKEN_LEFTPARAN", "TOKEN_RIGHTPARAN", "TOKEN_LEFTBRACKET",
  "TOKEN_RIGHTBRACKET", "TOKEN_CCOMMENT", "TOKEN_CPPCOMMENT", "TOKEN_TRUE",
  "TOKEN_ARRAY", "TOKEN_BOOLEAN", "TOKEN_CHARKEY", "TOKEN_ELSE",
  "TOKEN_FOR", "TOKEN_FUNCTIONA", "TOKEN_FUNCTION_MAIN", "TOKEN_FUNCTIONB",
  "TOKEN_FUNCTIONC", "TOKEN_FUNCTION_END", "TOKEN_IF", "TOKEN_IF_END",
  "TOKEN_INTEGER", "TOKEN_PRINT", "TOKEN_RETURN", "TOKEN_STRINGKEY",
  "TOKEN_VOID", "TOKEN_SEMICOLON", "TOKEN_COLON", "TOKEN_TILDE",
  "TOKEN_LEFTCURLYBRACE", "TOKEN_RIGHTCURLYBRACE", "TOKEN_COMMA",
  "$accept", "program", "decl_list", "decl", "opt_param_list",
  "param_list", "param", "stmt_list", "stmt", "opt_fcall_list",
  "fcall_list", "if_stmt_list", "while_stmt_list", "var_assgn", "type",
  "expr", "expr_bcomp_a", "expr_icomp", "expr_as", "expr_mmd", "expr_e",
  "expr_negate", "expr_par", "factor", "name", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    65,    66,    66,
      67,    67,    68,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    71,    71,    72,    72,    73,
      73,    73,    74,    74,    74,    75,    75,    76,    76,    76,
      76,    76,    77,    77,    78,    78,    79,    79,    79,    79,
      79,    79,    79,    80,    80,    80,    81,    81,    81,    81,
      82,    82,    83,    83,    83,    84,    84,    85,    85,    85,
      85,    85,    85,    86
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     0,     2,     1,     8,     3,     0,     1,
       1,     3,     3,     0,     2,     4,     4,     5,     4,     6,
       4,     2,     2,     3,     1,     0,     1,     1,     3,     0,
       4,     3,     0,     4,     3,     5,     3,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       3,     1,     2,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    73,    38,    37,    13,    39,    40,    41,     0,     0,
       3,     5,     0,     0,     0,     0,     0,     0,     0,    13,
      24,     0,     1,     0,     4,     0,     0,     0,    70,    69,
      67,    72,     0,     0,    71,     0,    43,    45,    52,    55,
      59,    61,    64,    66,    68,     0,    29,     0,     7,    14,
      22,    21,     0,    25,     0,    36,     0,    62,    63,     0,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
       0,    26,    27,     2,     0,     8,    65,     0,     0,    42,
      44,    51,    47,    49,    46,    48,    50,    53,    54,    56,
      57,    58,    60,    15,    29,     0,    29,    18,    16,    20,
       0,    35,     0,     9,    10,     0,    32,     0,    17,    31,
      29,     0,    28,    13,     0,     0,    34,    32,    30,    19,
       0,    11,    12,    33,     6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     8,     9,    10,   112,   113,   114,    18,    19,    80,
      81,    77,    88,    20,    12,    82,    36,    37,    38,    39,
      40,    41,    42,    43,    44
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int16 yypact[] =
{
      62,   -70,   -70,   -70,    44,   -70,   -70,   -70,    21,    -4,
      62,   -70,    -2,    14,    12,    12,    12,    34,    33,    44,
     -70,    70,   -70,    69,   -70,   103,    86,   104,   -70,   -70,
     -70,   -70,   104,    12,   -70,     3,    64,   107,    60,    18,
     105,   -70,   -70,   -70,   -70,    66,   -17,    12,   -70,   -70,
     -70,   -70,    12,    12,    93,   102,    78,   -70,   -70,    41,
      71,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    82,     5,    -1,    73,   108,
     116,   -70,   -28,   -70,    12,    86,   -70,    28,   143,    64,
     107,    60,    60,    60,    60,    60,    60,    18,    18,   105,
     105,   105,   -70,   -70,    91,    92,    91,   -70,   -70,   -70,
      12,   108,   106,   -70,    90,    97,    71,    98,   -70,   -70,
      91,   109,   -70,    44,    86,   103,   -70,    71,   -70,   -70,
     110,   -70,   -70,   -70,   -70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,   145,   -70,   -70,    36,   -70,   -18,   -65,   -70,
      47,   -69,   -63,    63,   -24,    -9,   100,   101,    80,   -54,
      37,    88,   -15,   -70,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      13,    49,    56,    61,    21,    35,    45,    46,    60,    14,
      13,   105,    57,     1,    61,    97,    98,    58,    23,    21,
       1,    22,   117,    27,    59,    55,    28,    29,    30,    31,
      71,    72,    14,   110,    61,   119,     1,   121,    78,    15,
      32,   106,    76,    79,    33,     2,     3,    73,    14,   107,
      34,   128,     1,   126,    16,    25,     5,    17,    26,     6,
       7,   115,    15,    11,   133,   104,    47,    69,     2,     3,
       1,    70,    61,    11,    86,   111,    21,    16,    15,     5,
      17,    48,     6,     7,     2,     3,   116,    21,    50,    51,
      52,    54,    53,    16,    62,     5,    17,    61,     6,     7,
     115,    75,     2,     3,    61,   130,   108,     4,    99,   100,
     101,     1,     1,     5,    74,    83,     6,     7,    28,    29,
      30,    31,    84,    21,    85,   132,     2,     3,    63,    87,
      64,    65,    66,    67,    68,   103,    33,     5,   109,    61,
       6,     7,    34,    91,    92,    93,    94,    95,    96,   118,
      76,   124,   120,   123,   125,    24,   127,   122,   134,   129,
     131,    89,   102,    90
};

static const yytype_uint8 yycheck[] =
{
       0,    19,    26,    31,     4,    14,    15,    16,     5,     4,
      10,    76,    27,     8,    31,    69,    70,    32,    22,    19,
       8,     0,    87,    11,    33,    25,    14,    15,    16,    17,
      12,    13,     4,    61,    31,   104,     8,   106,    47,    34,
      28,    42,    59,    52,    32,    40,    41,    29,     4,    50,
      38,   120,     8,   116,    49,    57,    51,    52,    44,    54,
      55,    85,    34,     0,   127,    60,    32,     7,    40,    41,
       8,    11,    31,    10,    33,    84,    76,    49,    34,    51,
      52,    48,    54,    55,    40,    41,    58,    87,    18,    19,
      20,    22,    22,    49,    30,    51,    52,    31,    54,    55,
     124,    35,    40,    41,    31,   123,    33,    45,    71,    72,
      73,     8,     8,    51,     9,    22,    54,    55,    14,    15,
      16,    17,    20,   123,    46,   125,    40,    41,    21,    58,
      23,    24,    25,    26,    27,    53,    32,    51,    22,    31,
      54,    55,    38,    63,    64,    65,    66,    67,    68,     6,
      59,    61,    60,    47,    57,    10,    58,   110,    48,    50,
     124,    61,    74,    62
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    40,    41,    45,    51,    54,    55,    63,    64,
      65,    75,    76,    86,     4,    34,    49,    52,    69,    70,
      75,    86,     0,    22,    64,    57,    44,    11,    14,    15,
      16,    17,    28,    32,    38,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    77,    77,    32,    48,    69,
      18,    19,    20,    22,    22,    86,    76,    84,    84,    77,
       5,    31,    30,    21,    23,    24,    25,    26,    27,     7,
      11,    12,    13,    29,     9,    35,    59,    73,    77,    77,
      71,    72,    77,    22,    20,    46,    33,    58,    74,    78,
      79,    80,    80,    80,    80,    80,    80,    81,    81,    82,
      82,    82,    83,    53,    60,    70,    42,    50,    33,    22,
      61,    77,    66,    67,    68,    76,    58,    70,     6,    73,
      60,    73,    72,    47,    61,    57,    74,    58,    73,    50,
      69,    67,    86,    74,    48
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 114 "calc.bison"
    {parser_result = (yyvsp[(1) - (4)].decl); return 0;;}
    break;

  case 3:
#line 117 "calc.bison"
    { (yyval.decl) = 0; ;}
    break;

  case 4:
#line 118 "calc.bison"
    { (yyval.decl) = (yyvsp[(1) - (2)].decl); (yyvsp[(1) - (2)].decl)->next = (yyvsp[(2) - (2)].decl); ;}
    break;

  case 5:
#line 121 "calc.bison"
    {  (yyval.decl) = (yyvsp[(1) - (1)].decl); ;}
    break;

  case 6:
#line 122 "calc.bison"
    { (yyval.decl) = decl_create( (yyvsp[(1) - (8)].expr)->name, type_create(TYPE_FUNCTION,(yyvsp[(3) - (8)].type), (yyvsp[(5) - (8)].param_list)), 0, (yyvsp[(7) - (8)].stmt), 0 ); ;}
    break;

  case 7:
#line 123 "calc.bison"
    { (yyval.decl) = decl_create( "main", type_create(TYPE_FUNCTION, type_create( TYPE_INTEGER, 0, 0 ), 0), 0, (yyvsp[(2) - (3)].stmt), 0 ); ;}
    break;

  case 8:
#line 126 "calc.bison"
    { (yyval.param_list) = 0; ;}
    break;

  case 9:
#line 127 "calc.bison"
    { (yyval.param_list) = (yyvsp[(1) - (1)].param_list); ;}
    break;

  case 10:
#line 130 "calc.bison"
    { (yyval.param_list) = (yyvsp[(1) - (1)].param_list); ;}
    break;

  case 11:
#line 131 "calc.bison"
    { (yyval.param_list) = (yyvsp[(1) - (3)].param_list); (yyvsp[(1) - (3)].param_list)->next = (yyvsp[(3) - (3)].param_list); ;}
    break;

  case 12:
#line 135 "calc.bison"
    { (yyval.param_list) = param_list_create( (yyvsp[(3) - (3)].expr)->name, (yyvsp[(1) - (3)].type), 0 ); ;}
    break;

  case 13:
#line 138 "calc.bison"
    { (yyval.stmt) = 0; ;}
    break;

  case 14:
#line 139 "calc.bison"
    { (yyval.stmt) = (yyvsp[(1) - (2)].stmt); (yyvsp[(1) - (2)].stmt)->next = (yyvsp[(2) - (2)].stmt); ;}
    break;

  case 15:
#line 142 "calc.bison"
    { (yyval.stmt) = stmt_create( STMT_RETURN, 0, 0, (yyvsp[(2) - (4)].expr), 0, 0, 0, 0 ); ;}
    break;

  case 16:
#line 143 "calc.bison"
    { (yyval.stmt) = stmt_create( STMT_PRINT, 0, 0, (yyvsp[(3) - (4)].expr), 0, 0, 0, 0 ); ;}
    break;

  case 17:
#line 144 "calc.bison"
    { (yyval.stmt) = stmt_create( STMT_WHILE, 0, 0, (yyvsp[(2) - (5)].expr), 0, (yyvsp[(4) - (5)].stmt), 0, 0 ); ;}
    break;

  case 18:
#line 145 "calc.bison"
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE,0,0,(yyvsp[(2) - (4)].expr),0,(yyvsp[(3) - (4)].stmt),0,0); ;}
    break;

  case 19:
#line 146 "calc.bison"
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE,0,0,(yyvsp[(2) - (6)].expr),0,(yyvsp[(3) - (6)].stmt),(yyvsp[(5) - (6)].stmt), 0); ;}
    break;

  case 20:
#line 147 "calc.bison"
    { (yyval.stmt) = stmt_create( STMT_EXPR, 0, 0, expr_create( EXPR_FCALL, (yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr)), 0, 0, 0, 0 ); ;}
    break;

  case 21:
#line 148 "calc.bison"
    { (yyval.stmt) = stmt_create( STMT_EXPR, 0, 0, expr_create( EXPR_INCREMENT, (yyvsp[(1) - (2)].expr), 0 ), 0, 0, 0, 0 ); ;}
    break;

  case 22:
#line 149 "calc.bison"
    { (yyval.stmt) = stmt_create( STMT_EXPR, 0, 0, expr_create( EXPR_DECREMENT, (yyvsp[(1) - (2)].expr), 0 ), 0, 0, 0, 0 ); ;}
    break;

  case 23:
#line 150 "calc.bison"
    { (yyval.stmt) = stmt_create( STMT_EXPR, 0, 0, expr_create( EXPR_ASSIGN, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr) ), 0, 0, 0, 0 ); ;}
    break;

  case 24:
#line 151 "calc.bison"
    { (yyval.stmt) = stmt_create( STMT_DECL, (yyvsp[(1) - (1)].decl), 0, 0, 0, 0, 0, 0 );;}
    break;

  case 25:
#line 154 "calc.bison"
    { (yyval.expr) = 0; ;}
    break;

  case 26:
#line 155 "calc.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 27:
#line 158 "calc.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 28:
#line 159 "calc.bison"
    { (yyval.expr) = expr_create( EXPR_ARG, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 29:
#line 162 "calc.bison"
    { (yyval.stmt) = 0; ;}
    break;

  case 30:
#line 163 "calc.bison"
    { (yyval.stmt) = (yyvsp[(2) - (4)].stmt); (yyvsp[(2) - (4)].stmt)->next = (yyvsp[(4) - (4)].stmt); ;}
    break;

  case 31:
#line 164 "calc.bison"
    { (yyval.stmt) = (yyvsp[(3) - (3)].stmt); ;}
    break;

  case 32:
#line 167 "calc.bison"
    { (yyval.stmt) = 0; ;}
    break;

  case 33:
#line 168 "calc.bison"
    { (yyval.stmt) = (yyvsp[(2) - (4)].stmt); (yyvsp[(2) - (4)].stmt)->next = (yyvsp[(4) - (4)].stmt); ;}
    break;

  case 34:
#line 169 "calc.bison"
    { (yyval.stmt) = (yyvsp[(3) - (3)].stmt); ;}
    break;

  case 35:
#line 172 "calc.bison"
    { (yyval.decl) = decl_create((yyvsp[(3) - (5)].expr)->name,(yyvsp[(1) - (5)].type),(yyvsp[(5) - (5)].expr),0,0); ;}
    break;

  case 36:
#line 173 "calc.bison"
    { (yyval.decl) = decl_create((yyvsp[(3) - (3)].expr)->name,(yyvsp[(1) - (3)].type),0,0,0); ;}
    break;

  case 37:
#line 176 "calc.bison"
    { (yyval.type) = type_create( TYPE_CHARACTER, 0, 0 ); ;}
    break;

  case 38:
#line 177 "calc.bison"
    { (yyval.type) = type_create( TYPE_BOOLEAN, 0, 0 ); ;}
    break;

  case 39:
#line 178 "calc.bison"
    { (yyval.type) = type_create( TYPE_INTEGER, 0, 0 ); ;}
    break;

  case 40:
#line 179 "calc.bison"
    { (yyval.type) = type_create( TYPE_STRING, 0, 0 ); ;}
    break;

  case 41:
#line 180 "calc.bison"
    { (yyval.type) = type_create( TYPE_VOID, 0, 0 ); ;}
    break;

  case 42:
#line 183 "calc.bison"
    { (yyval.expr) = expr_create( EXPR_OR, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 43:
#line 184 "calc.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 44:
#line 187 "calc.bison"
    { (yyval.expr) = expr_create( EXPR_AND, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 45:
#line 188 "calc.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 46:
#line 191 "calc.bison"
    { (yyval.expr) = expr_create( EXPR_GT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 47:
#line 192 "calc.bison"
    { (yyval.expr) = expr_create( EXPR_LT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 48:
#line 193 "calc.bison"
    { (yyval.expr) = expr_create( EXPR_GE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 49:
#line 194 "calc.bison"
    { (yyval.expr) = expr_create( EXPR_LE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 50:
#line 195 "calc.bison"
    { (yyval.expr) = expr_create( EXPR_NOT_EQUALS, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 51:
#line 196 "calc.bison"
    { (yyval.expr) = expr_create( EXPR_EQUALS, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 52:
#line 197 "calc.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 53:
#line 201 "calc.bison"
    { (yyval.expr) = expr_create( EXPR_ADD, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 54:
#line 202 "calc.bison"
    { (yyval.expr) = expr_create( EXPR_SUB, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 55:
#line 203 "calc.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 56:
#line 206 "calc.bison"
    { (yyval.expr) = expr_create( EXPR_MUL, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 57:
#line 207 "calc.bison"
    { (yyval.expr) = expr_create( EXPR_DIV, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 58:
#line 208 "calc.bison"
    { (yyval.expr) = expr_create( EXPR_MOD, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 59:
#line 209 "calc.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 60:
#line 212 "calc.bison"
    { (yyval.expr) = expr_create( EXPR_EXPONENT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 61:
#line 213 "calc.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 62:
#line 216 "calc.bison"
    { (yyval.expr) = expr_create( EXPR_NOT, 0, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 63:
#line 217 "calc.bison"
    { (yyval.expr) = (yyvsp[(2) - (2)].expr); ;}
    break;

  case 64:
#line 218 "calc.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 65:
#line 221 "calc.bison"
    { (yyval.expr) = expr_create( EXPR_BLOCK, 0, (yyvsp[(2) - (3)].expr) ); ;}
    break;

  case 66:
#line 222 "calc.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 67:
#line 225 "calc.bison"
    { (yyval.expr) = expr_create_integer_literal(atoi(yytext)); ;}
    break;

  case 68:
#line 226 "calc.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 69:
#line 227 "calc.bison"
    { (yyval.expr) = expr_create_char_literal(yytext); ;}
    break;

  case 70:
#line 228 "calc.bison"
    { (yyval.expr) = expr_create_string_literal(yytext); ;}
    break;

  case 71:
#line 229 "calc.bison"
    { (yyval.expr) = expr_create_boolean_literal(1) ; ;}
    break;

  case 72:
#line 230 "calc.bison"
    { (yyval.expr) = expr_create_boolean_literal(0) ; ;}
    break;

  case 73:
#line 233 "calc.bison"
    { (yyval.expr) = expr_create_name(yytext); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1960 "parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 237 "calc.bison"


/*
This function will be called by bison if the parse should
encounter an error.  In principle, "str" will contain something
useful.  In practice, it often does not.
*/

int yyerror( char *str )
{
	printf("parse error: %s\n",str);
	return 0;
}

