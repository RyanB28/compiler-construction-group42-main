%{

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "ccngen/ast.h"
#include "ccngen/enum.h"
#include "parser.h"
#include "palm/str.h"
#include "global/globals.h"
#include "palm/ctinfo.h"


#define FILTER(token) \
  global.col += yyleng;  \
  return( token);

#define LINEBUF_SIZE 256
#define YY_NO_UNPUT
#define YY_NO_INPUT

static inline void token_action();

int yycolumn = 1;
#define YY_USER_ACTION token_action();


%}

%p 6000 /* set positions to 6000 */
%e 2000 /* set nodes to 1100 */
%option noyywrap
%option nounput
%option yylineno

%%
"/*"([^*]|(\*+[^*/]))*\*+\/ { /* Multiline */}
"//".*                     { /* Single line */}

"extern"                   { FILTER( EXTERN); }
"export"                   { FILTER( EXPORT); }

"return"                   { FILTER( RETURNTOKEN); }

"void"                     { FILTER( VOIDTYPE); }
"float"                    { FILTER( FLOATTYPE); }
"int"                      { FILTER( INTTYPE); }
"bool"                     { FILTER( BOOLTYPE); }

"if"                       { FILTER( IF); }
"else"                     { FILTER( ELSE); }
"while"                    { FILTER( WHILE); }
"for"                      { FILTER( FORTOKEN) }
"do"                       { FILTER( DOTOKEN) }

"("                        { FILTER( BRACKET_L); }
")"                        { FILTER( BRACKET_R); }
"{"                        { FILTER( CURLY_BRACKET_L); }
"}"                        { FILTER( CURLY_BRACKET_R); }
","                        { FILTER( COMMA); }
";"                        { FILTER( SEMICOLON); }

"-"                        { FILTER( MINUS); }
"+"                        { FILTER( PLUS);  }
"*"                        { FILTER( STAR);  } 
"/"                        { FILTER( SLASH);  } 
"%"                        { FILTER( PERCENT);  } 

"!"                        { FILTER( NEG);    }
"<="                       { FILTER( LE);    }
"<"                        { FILTER( LT);    } 
">="                       { FILTER( GE);    }
">"                        { FILTER( GT);    }
"=="                       { FILTER( EQ);    }
"!="                       { FILTER( NE);    }
"&&"                       { FILTER( AND);    }
"||"                       { FILTER( OR);    }

"="                        { FILTER( LET);    }

"true"                     { FILTER( TRUEVAL); }
"false"                    { FILTER( FALSEVAL); }

[A-Za-z][A-Za-z0-9_]*      { yylval.id = STRcpy(yytext);
                             FILTER( ID);
                           }

[0-9]+                     { int i = atoi(yytext);
                             if(i < 0) {
                                printf("Number to large or to small\n");
                                exit(1);
                             }
                             yylval.cint = i;
                             FILTER( NUM);
                           }

[0-9]+\.[0-9]+             { yylval.cflt=atof(yytext);
                             FILTER( FLOAT);
                           }

\n.*                       { 
                             yycolumn = 1;
                             global.line += 1;
                             global.col = 0;
                             yyless(1);
                           }   

[ \t]                      { global.col += yyleng;
                           } 
%%

static inline void token_action() {
    yylloc.first_line = yylloc.last_line = yylineno;
    yylloc.first_column = yycolumn;
    yylloc.last_column = yycolumn + yyleng - 1;
    yycolumn += yyleng;
}

