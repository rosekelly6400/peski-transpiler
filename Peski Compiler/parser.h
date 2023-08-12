/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 180 "parser.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

