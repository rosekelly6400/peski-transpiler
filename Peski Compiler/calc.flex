%{
#include "parser.h"
%}

%option nounput
%option noinput

DIGIT  [0-9]
LETTER [a-zA-Z]
%%
(" "|\t|\n)  /* skip whitespace */
(\"((\\\\|[^\"\\\r\n]|\\\"|\\\'|" "|\\.)*)\")		{ return TOKEN_STRING; }
 '([^'\\\n]|\\.)?'	{ return TOKEN_CHAR; }
\/\*((.|\n|\r)*)\*\/				{ return TOKEN_CCOMMENT; }
\/\*([^(*/)]|\n|\r)*  			{ return TOKEN_ERROR; }
 \/\/.*(\n|\r)?			{ return TOKEN_CPPCOMMENT; } 
[+-]?{DIGIT}+ 				{ return TOKEN_NUMBER; }
 \-\-					{ return TOKEN_DECREMENT; }
 \+\+					{ return TOKEN_INCREMENT; }
 ==						{ return TOKEN_EQUALITY; }
 !=						{ return TOKEN_NOTEQUALS; }
 \|\|					{ return TOKEN_OR; }
 &&						{ return TOKEN_AND; }
 \(\^\._\.\)\^(" "|\t)*\(>\._\.\)>		{ return TOKEN_ASSIGN; }
 !						{ return TOKEN_NEGATION; }
;						{ return TOKEN_SEMICOLON; }
\->						{ return TOKEN_COLON; }
 __\(\.\)\<(" "|\t)*__\(\.\)=(" "|\t)*\n(" "|\t)*\\____\)(" "|\t|~)*      { return TOKEN_WHILEA; }
 (" "|\t|~)*\\____\)                                { return TOKEN_WHILEB; }
 (" "|\t|~)*\^(" "|\t|~)*~(" "|\t|~)*\^(" "|\t|~)*                                   { return TOKEN_WHILE_END; }
array					{ return TOKEN_ARRAY; }
\(\$\)					{ return TOKEN_BOOLEAN; }
=\^\." "\.\^= 				{ return TOKEN_CHARKEY; }
O" "\|(" "|\t)*\|" "O			{ return TOKEN_ELSE; }
\(\\" "\/\)(" "|\t)*\n(" "|\t)*\(\." "\.\)(" "|\t)*\n(" "|\t)*o\(\“\)\(\“\)(" "|,)*\\		{ return TOKEN_FUNCTIONA; }
!(!|" "|\t)*\n\(\\" "\/\)(" "|\t)*\n(" "|\t)*\(\+" "\+\)(" "|\t)*\n(" "|\t)*Q\(\“\)\(\“\)(" "|,)*        { return TOKEN_FUNCTION_MAIN; }
\/" "*,(" "|,)*\\					{ return TOKEN_FUNCTIONB; }
\/" "*,(" "|,)*						{ return TOKEN_FUNCTIONC; }
___+					{ return TOKEN_FUNCTION_END; }
\/\\_\/\\(" "|\t)*\n(" "|\t)*\>\(0" "x" "0\)\<(" "|\t)*\-	{ return TOKEN_IF; }
~+\^(" "|\t)*\n(" "|\t)*_\(" "*\)(" "|\t)*\(" "*\)_	{ return TOKEN_IF_END; }
 ><\(\(@>					{ return TOKEN_INTEGER; }
 \(\/`'o'\)\/`" "\.\.\.					{ return TOKEN_PRINT; }
\(\\\(\*w\*\)\/\)(" "|\t)*\n(" "|\t)*\((" "|\t)*\)(" "|\t)*\n(" "|\t)*L(" "|\t)*L			{ return TOKEN_RETURN; }
\(\-_\(\-_\-\)_\-\)					{ return TOKEN_STRINGKEY; }
void						{ return TOKEN_VOID; }
 \%						{ return TOKEN_MODULO; }
 \+        				{ return TOKEN_PLUS; }
 \-	   					{ return TOKEN_MINUS; }
 \*        				{ return TOKEN_MUL; }
 \<3					{return TOKEN_HEART;}
 \/	   					{ return TOKEN_DIV; }
 \^	   					{ return TOKEN_EXPONENT; }
 \<\=					{ return TOKEN_LE; }
 \<						{ return TOKEN_LT; }
 \>\=					{ return TOKEN_GE; }
 \>						{ return TOKEN_GT; }
O						{ return TOKEN_TRUE; }
X					{ return TOKEN_FALSE; }
 \(						{ return TOKEN_LEFTPARAN; }
 \)						{ return TOKEN_RIGHTPARAN; }
 \[						{ return TOKEN_LEFTBRACKET; }
 \]						{ return TOKEN_RIGHTBRACKET; }
\{ 						{ return TOKEN_LEFTCURLYBRACE; }
\} 						{ return TOKEN_RIGHTCURLYBRACE; }
,						{ return TOKEN_COMMA; }
~						{ return TOKEN_TILDE; }
([a-zA-N]|[P-W]|Z|_)(({LETTER}|{DIGIT}|_){0,255})		{ return TOKEN_IDENT; }
.          				{ return TOKEN_ERROR; }
%%

/*
flex calls yywrap() whenever it reaches the end of the current file.
If yywrap returns false to indicate the end of the program.
It could alternatively open up another file and return true,
so that flex would keep going.
*/

int yywrap()
{
	return 1;
}
