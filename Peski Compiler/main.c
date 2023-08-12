/*
 Main program of calculator example.
 Validate whether the input matches the grammar.
 */
#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decl.h"
#include "scope.h"

/* Clunky: Declare the parse function generated from parser.bison */
extern int yyparse();
extern FILE *yyin;
extern int yylex();
extern char *yytext;
extern struct decl * parser_result;
int yydebug;

int main(int argc, char *argv[])
{
    int argind = 1;
    int parse = 0;
    int print = 0;
    int scan = 0;
    int resolve = 0;
    int typecheck = 0;
    int compile = 0;
    int execute = 0;
    
    /* Parse command line arguments */
    if(argc < 2) {
        exit(0);
    }
    while (argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-') {
        char *arg = argv[argind++];
        switch (arg[1]) {
            case 'h':
                exit(0);
                break;
            case 'p':
                if (arg[2] == 'a')  parse = 1;
                if (arg[2] == 'r')  print = 1;
                break;
            case 's':
                scan = 1;
                break;
            case 'r':
                resolve = 1;
                break;
            case 't':
                typecheck = 1;
                break;
            case 'c':
                compile = 1;
                break;
            case 'e':
                execute = 1;
                compile = 1;
                break;
            default:
                exit(0);
                break;
        }
    }
    char * filename = argv[argind++];
    
    if (scan) {
        yyin = fopen(filename,"r");
        if(!yyin) {
            printf("could not open file!\n");
            return 1;
        }
        
        while(1) {
            token_t t = yylex();
            if(t==0) break;
            char editedText1[256] = "";
            char editedText2[256] = "";
            switch (t-258) {
                case TOKEN_WHILEA:
                    printf(" WHILEA  %s \n",yytext);
                    break;
                case TOKEN_WHILEB:
                    printf(" WHILEB  %s \n",yytext);
                    break;
                case TOKEN_WHILE_END:
                    printf(" WHILE_END  %s \n",yytext);
                    break;
                case TOKEN_PLUS:
                    printf(" ADD  %s \n",yytext);
                    break;
                case TOKEN_IDENT:
                    printf(" IDENT  %s \n",yytext);
                    break;
                case TOKEN_EXPONENT:
                    printf(" EXPONENT  %s \n",yytext);
                    break;
                case TOKEN_ERROR:
                    printf(" ERROR  %s \n",yytext);
                    exit(-1);
                    break;
                case TOKEN_MINUS:
                    printf(" SUBTRACT  %s \n",yytext);
                    break;
                case TOKEN_MUL:
                    printf(" MULTIPLY  %s \n",yytext);
                    break;
                case TOKEN_HEART:
                    printf( " HEART %s \n",yytext);
                    break;
                case TOKEN_DIV:
                    printf(" DIVIDE  %s \n",yytext);
                    break;
                case TOKEN_STRING:
                    strcpy(editedText1, &yytext[1]);
                    strncpy(editedText2,editedText1,strlen(editedText1)-1);
                    if (strlen(editedText2) > 255) {
                        printf(" ERROR  %s \n",yytext);
                        exit(-1);
                    }
                    else{
                        printf(" STRING  %s \n",editedText2);
                    }
                    break;
                case TOKEN_CHAR:
                    printf(" CHAR  %s \n",yytext);
                    break;
                case TOKEN_NUMBER:
                    printf(" NUMBER  %s \n",yytext);
                    break;
                case TOKEN_FALSE:
                    printf(" FALSE  %s \n",yytext);
                    break;
                case TOKEN_DECREMENT:
                    printf(" DECREMENT  %s \n",yytext);
                    break;
                case TOKEN_INCREMENT:
                    printf(" INCREMENT  %s \n",yytext);
                    break;
                case TOKEN_ASSIGN:
                    printf(" ASSIGN  %s \n",yytext);
                    break;
                case TOKEN_EQUALITY:
                    printf(" EQUALITY  %s \n",yytext);
                    break;
                case TOKEN_LT:
                    printf(" LT  %s \n",yytext);
                    break;
                case TOKEN_LE:
                    printf(" LE  %s \n",yytext);
                    break;
                case TOKEN_GT:
                    printf(" GT  %s \n",yytext);
                    break;
                case TOKEN_GE:
                    printf(" GE  %s \n",yytext);
                    break;
                case TOKEN_NOTEQUALS:
                    printf(" NOT_EQUALS  %s \n",yytext);
                    break;
                case TOKEN_NEGATION:
                    printf(" NEGATION  %s \n",yytext);
                    break;
                case TOKEN_MODULO:
                    printf(" MODULO  %s \n",yytext);
                    break;
                case TOKEN_AND:
                    printf(" AND  %s \n",yytext);
                    break;
                case TOKEN_OR:
                    printf(" OR  %s \n",yytext);
                    break;
                case TOKEN_RIGHTPARAN:
                    printf(" RIGHTPARAN  %s \n",yytext);
                    break;
                case TOKEN_LEFTPARAN:
                    printf(" LEFTPARAN  %s \n",yytext);
                    break;
                case TOKEN_RIGHTBRACKET:
                    printf(" RIGHTBRACKET  %s \n",yytext);
                    break;
                case TOKEN_LEFTBRACKET:
                    printf(" LEFTBRACKET  %s \n",yytext);
                    break;
                case TOKEN_CCOMMENT:
                    printf(" CCOMMENT  %s \n",yytext);
                    break;
                case TOKEN_CPPCOMMENT:
                    printf(" CPPCOMMENT  %s \n",yytext);
                    break;
                case TOKEN_TRUE:
                    printf(" TRUE  %s \n",yytext);
                    break;
                case TOKEN_ARRAY:
                    printf(" ARRAY  %s \n",yytext);
                    break;
                case TOKEN_BOOLEAN:
                    printf(" BOOLEAN  %s \n",yytext);
                    break;
                case TOKEN_CHARKEY:
                    printf(" CHARKEY  %s \n",yytext);
                    break;
                case TOKEN_ELSE:
                    printf(" ELSE  %s \n",yytext);
                    break;
                case TOKEN_FOR:
                    printf(" FOR  %s \n",yytext);
                    break;
                case TOKEN_FUNCTIONA:
                    printf(" FUNCTION A  %s \n",yytext);
                    break;
                case TOKEN_FUNCTIONB:
                    printf(" FUNCTION B  %s \n",yytext);
                    break;
                case TOKEN_FUNCTIONC:
                    printf(" FUNCTION C  %s \n",yytext);
                    break;
                case TOKEN_FUNCTION_END:
                    printf(" FUNCTION END  %s \n",yytext);
                    break;
                case TOKEN_IF:
                    printf(" IF  %s \n",yytext);
                    break;
                case TOKEN_IF_END:
                    printf(" IF_END  %s \n",yytext);
                    break;
                case TOKEN_INTEGER:
                    printf(" INTEGER  %s \n",yytext);
                    break;
                case TOKEN_PRINT:
                    printf(" PRINT  %s \n",yytext);
                    break;
                case TOKEN_RETURN:
                    printf(" RETURN  %s \n",yytext);
                    break;
                case TOKEN_STRINGKEY:
                    printf(" STRINGKEY  %s \n",yytext);
                    break;
                case TOKEN_VOID:
                    printf(" VOID  %s \n",yytext);
                    break;
                case TOKEN_SEMICOLON:
                    printf(" SEMICOLON  %s \n",yytext);
                    break;
                case TOKEN_COLON:
                    printf(" COLON  %s \n",yytext);
                    break;
                case TOKEN_LEFTCURLYBRACE:
                    printf(" LEFTCURLYBRACE  %s \n",yytext);
                    break;
                case TOKEN_RIGHTCURLYBRACE:
                    printf(" RIGHTCURLYBRACE  %s \n",yytext);
                    break;
                case TOKEN_TILDE:
                    printf(" TILDE  %s \n",yytext);
                    break;
                case TOKEN_COMMA:
                    printf(" COMMA  %s \n",yytext);
                    break;
                default:
                    printf(" %d  %s\n",t,yytext);
                    break;
            }
        }
        return 0;
    }
    
    
    
    if(parse) {
    printf("Parsing!\n");
    yyin = fopen(filename,"r");
    if(!yyin) {
        printf("could not open file!\n");
        return 1;
    }
    
        if(yyparse()==0) {
            printf("Parse successful!\n");
            return 0;
        } else {
            printf("Parse failed.\n");
            return 1;
        }
    }
    
    if (print) {
        printf("Printing!\n");
        yyin = fopen(filename,"r");
        if(!yyin) {
            printf("could not open file!\n");
            return 1;
        }
        
        if(yyparse()==0) {
            printf("Parse successful!\n");
            decl_print(parser_result, 0);
            return 0;
        } else {
            printf("Parse failed.\n");
            return 1;
        }
    }
    
    if(compile) {
        if(!execute) printf("Typechecking!\n");
        
        yyin =  fopen(filename,"r");
        if(!yyin) {
            if(!execute) printf("could not open file!\n");
            return 1;
        }
        if(yyparse()==0) {
            if(!execute) {
	    printf("Parse successful!\n");
            scope_enter();
            decl_resolve(parser_result);
            scope_exit();
            int rval = get_num_errors();
            if(rval)
            {
                if(!execute) printf("%d Type Resolution Errors Found, Will NOT begin Typechecking.\n", rval);
                return 1;
            }
            printf("No Type Resolution Errors Found.\n");
            clear_errors();
            decl_typecheck(parser_result);
            rval = get_num_errors();
            if(rval)
            {
                if(!execute) printf("%d Type Checking Errors Found.\n", rval);
                return 1;
            }
	   }
            if(!execute) printf("No Type Checking Errors Found.\n");
            if(!execute) printf("Compiling!\n");
            if(execute) {
                printf("#include <stdio.h>\n#include <stdlib.h> \n#include <string.h>\n#include <stdbool.h> \n");
                decl_translate(parser_result, 0);
            }
	    return 0;
	}
        else {
            if(!execute) printf("Parse failed. \n");
            return 1;
        }
    }
    if (resolve) {
        printf("Resolving!\n");
        yyin =  fopen(filename,"r");
        if(!yyin) {
            printf("could not open file!\n");
            return 1;
        }
        
        if(yyparse()==0) {
            printf("Parse successful!\n");
            scope_enter();
            decl_resolve(parser_result);
            scope_exit();
            int rval = get_num_errors();
            if(rval)
            {
                printf("%d Type Resolution Errors Found.\n", rval);
                return 1;
            }
            printf("No Type Resolution Errors Found.\n");
            return 0;
        } else {
            printf("Parse failed. \n");
            return 1;
        }
    }
    
    if(typecheck) {
        printf("Typechecking!\n");
        yyin =  fopen(filename,"r");
        if(!yyin) {
            printf("could not open file!\n");
            return 1;
        }
        if(yyparse()==0) {
            printf("Parse successful!\n");
            scope_enter();
            decl_resolve(parser_result);
            scope_exit();
            int rval = get_num_errors();
            if(rval)
            {
                printf("%d Type Resolution Errors Found, Will NOT begin Typechecking.\n", rval);
                return 1;
            }
            printf("No Type Resolution Errors Found.\n");
            clear_errors();
            decl_typecheck(parser_result);
            rval = get_num_errors();
            if(rval)
            {
                printf("%d Type Checking Errors Found.\n", rval);
                return 1;
            }
            printf("No Type Checking Errors Found.\n");
            return 0;
        }
        else {
            printf("Parse failed. \n");
            return 1;
        }
    }
    
    return 0;
}
    


