%{


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "palm/memory.h"
#include "palm/ctinfo.h"
#include "palm/dbug.h"
#include "palm/str.h"
#include "ccngen/ast.h"
#include "ccngen/enum.h"
#include "global/globals.h"

static node_st *parseresult = NULL;
extern int yylex();
static int yyerror( char *errname);
extern FILE *yyin;
void AddLocToNode(node_st *node, void *begin_loc, void *end_loc);


%}

%union {
 char               *id;
 int                 cint;
 float               cflt;
 enum binop_type     cbinop;
 node_st             *node;
 enum Types          ctypes;
 enum MonOpEnum      cmonops;
}

%locations

%token BRACKET_L BRACKET_R COMMA SEMICOLON CURLY_BRACKET_L CURLY_BRACKET_R
%token MINUS PLUS STAR SLASH PERCENT LE LT GE GT EQ NE OR AND 
%token TRUEVAL FALSEVAL LET CAST EXPRPREC FUNCALLPREC
%token INTTYPE FLOATTYPE BOOLTYPE
%token VOIDTYPE NEG
%token IF ELSE WHILE FOR RETURNTOKEN EXPORT EXTERN FORTOKEN DOTOKEN

%token <cint> NUM
%token <cflt> FLOAT
%token <id> ID

%type <node> decl decls fundef params funbody for dowhile vardecl exprs
%type <node> intval floatval boolval constant expr block return ifelse
%type <node> stmts stmt assign varlet program globdecl globdef while

%type <ctypes> types

%left OR
%left AND
%left EQ NE
%left LE LT GE GT 
%left PLUS MINUS
%left STAR SLASH PERCENT
%right NEGPREC NEG CAST
%left FUNCALLPREC

%precedence THEN
%precedence ELSE


%start program

%%

program: decls
         {
           parseresult = ASTprogram($1);
         }
         ;

decls: decl decls
       {
         $$ = ASTdecls($1, $2);
       }
     | decl
       {
         $$ = ASTdecls($1, NULL);
       }
       ;

decl: globdecl
      {
        $$ = $1;
      }
    | globdef
      {
        $$ = $1;
      }
    | fundef
      {
        $$ = $1;
      }
      ;

fundef: EXTERN types ID BRACKET_L BRACKET_R SEMICOLON 
         {
           $$ = ASTfundef(NULL, NULL, $2, $3, false);
         }
        | EXTERN types ID BRACKET_L params BRACKET_R SEMICOLON 
         {
           $$ = ASTfundef(NULL, $5, $2, $3, false);
         }
        | EXPORT types ID BRACKET_L BRACKET_R CURLY_BRACKET_L funbody CURLY_BRACKET_R
         {
           $$ = ASTfundef($7, NULL, $2, $3, true);
         }
        | EXPORT types ID BRACKET_L params BRACKET_R CURLY_BRACKET_L funbody CURLY_BRACKET_R
         {
           $$ = ASTfundef($8, $5, $2, $3, true);
         }
        | types ID BRACKET_L BRACKET_R CURLY_BRACKET_L funbody CURLY_BRACKET_R
         {
           $$ = ASTfundef($6, NULL, $1, $2, false);
         }
        | types ID BRACKET_L params BRACKET_R CURLY_BRACKET_L funbody CURLY_BRACKET_R
         {
           $$ = ASTfundef($7, $4, $1, $2, false);
         }
         ;

funbody:
         {
           $$ = ASTfunbody(NULL, NULL);
         }
        | vardecl
          {
            $$ = ASTfunbody($1, NULL);

          }
        | vardecl stmts 
          {
            $$ = ASTfunbody($1, $2);
          }
        | stmts
         {
           $$ = ASTfunbody(NULL, $1);
         }
         ;


vardecl: types ID SEMICOLON vardecl
          {
            $$ = ASTvardecl(NULL, $4, $2, $1);
          }
        | types ID SEMICOLON
          {
            $$ = ASTvardecl(NULL, NULL, $2, $1);
          }
        | types ID LET expr SEMICOLON vardecl
          {
            $$ = ASTvardecl($4, $6, $2, $1);
          }
        | types ID LET expr SEMICOLON
          {
            $$ = ASTvardecl($4, NULL, $2, $1);
          }
        ;


params: types ID COMMA params
        {
          $$ = ASTparam($4, $2, $1);
        }
      | types ID
        {
          $$ = ASTparam(NULL, $2, $1);
        }
        ;

globdef: types ID SEMICOLON
           {
             $$ = ASTglobdef(NULL, $1, $2, false);
           }
          |
          EXPORT types ID SEMICOLON
           {
             $$ = ASTglobdef(NULL, $2, $3, true);;
           }
          | types ID LET expr SEMICOLON
           {
             $$ = ASTglobdef($4, $1, $2, false);
           }
          |
          EXPORT types ID LET expr SEMICOLON
           {
             $$ = ASTglobdef($5, $2, $3, true);;
           }
           ;
 
globdecl: EXTERN types ID SEMICOLON
           {
             $$ = ASTglobdecl(NULL, $2, $3);
           }
          ;

stmts: stmt stmts
        {
          $$ = ASTstmts($1, $2);
        }
      | stmt
        {
          $$ = ASTstmts($1, NULL);
        }
        ;

stmt: assign
       {
         $$ = $1;
       }
      | while 
        {
          $$ = $1;
        }
      | for
        {
          $$ = $1;
        } 
      | dowhile
        {
          $$ = $1; 
        }
      | return
        {
          $$ = $1; 
        }
      | ifelse
        {
          $$ = $1;    
        }
      | expr SEMICOLON %prec EXPRPREC
        {
          $$ = ASTexprstmt($1); 
        }
       ;

ifelse: IF BRACKET_L expr BRACKET_R stmt ELSE block 
        {
          $$ = ASTifelse($3, ASTstmts($5, NULL), $7);
        }
      | IF BRACKET_L expr BRACKET_R stmt ELSE stmt
        {
          $$ = ASTifelse($3, ASTstmts($5, NULL), ASTstmts($7, NULL));
        }
      | IF BRACKET_L expr BRACKET_R stmt %prec THEN
        {
          $$ = ASTifelse($3, ASTstmts($5, NULL), NULL);
        }
      | IF BRACKET_L expr BRACKET_R block %prec THEN
        {
          $$ = ASTifelse($3, $5, NULL);
        }
      | IF BRACKET_L expr BRACKET_R block ELSE block
        {
          $$ = ASTifelse($3, $5, $7);
        }

assign: varlet LET expr SEMICOLON
        {
          $$ = ASTassign($1, $3);
        }
        ;

while: WHILE BRACKET_L expr BRACKET_R block
      {
        $$ = ASTwhile($3, $5);
      }
      ;

for: FORTOKEN BRACKET_L types ID LET expr COMMA expr COMMA expr BRACKET_R stmt
    {
      $$ = ASTfor($6, $8, $10, ASTstmts($12, NULL), $4);
    }
    | FORTOKEN BRACKET_L types ID LET expr COMMA expr BRACKET_R stmt
    {
      $$ = ASTfor($6, $8, NULL, ASTstmts($10, NULL), $4);
    }
    | FORTOKEN BRACKET_L types ID LET expr COMMA expr BRACKET_R block
      {
        $$ = ASTfor($6, $8, NULL, $10, $4);
      }
    | FORTOKEN BRACKET_L types ID LET expr COMMA expr COMMA expr BRACKET_R block
      {
        $$ = ASTfor($6, $8, $10, $12, $4);
      }
      ;

dowhile: DOTOKEN stmt WHILE BRACKET_L expr BRACKET_R SEMICOLON
      {
        $$ = ASTdowhile($5, ASTstmts($2, NULL));
      }
     | DOTOKEN block WHILE BRACKET_L expr BRACKET_R SEMICOLON
      {
        $$ = ASTdowhile($5, $2);        
      }

return: RETURNTOKEN expr SEMICOLON
      {
        $$ = ASTreturn($2);
      }
    | RETURNTOKEN SEMICOLON
      {
        $$ = ASTreturn(NULL);
      }

block: CURLY_BRACKET_L stmt CURLY_BRACKET_R
      {
        $$ = ASTstmts($2, NULL);
      }
    | CURLY_BRACKET_L stmts CURLY_BRACKET_R
      {
        $$ = $2;
      }
    | CURLY_BRACKET_L CURLY_BRACKET_R
      {
        $$ = NULL; 
      }
      ;


varlet: ID
        {
          $$ = ASTvarlet($1, NULL);
          AddLocToNode($$, &@1, &@1);
        }
        ;


expr: constant
      {
        $$ = $1;
      }
    | ID
      {
        $$ = ASTvar($1);
      }
    | expr[left] PLUS expr[right] 
      {
        $$ = ASTbinop($left, $right, BO_add);
        AddLocToNode($$, &@left, &@right);
      }
    | expr[left] MINUS expr[right]
      {
        $$ = ASTbinop($left, $right, BO_sub);
        AddLocToNode($$, &@left, &@right);
      }
    | expr[left] STAR expr[right]
      {
        $$ = ASTbinop($left, $right, BO_mul);
        AddLocToNode($$, &@left, &@right);
      }
    | expr[left] SLASH expr[right]
      {
        $$ = ASTbinop($left, $right, BO_div);
        AddLocToNode($$, &@left, &@right);
      }
    | expr[left] EQ expr[right]
      {
        $$ = ASTbinop($left, $right, BO_eq);
        AddLocToNode($$, &@left, &@right);
      }
    | expr[left] PERCENT expr[right]
      {
        $$ = ASTbinop($left, $right, BO_mod);
        AddLocToNode($$, &@left, &@right);
      }
    | expr[left] LT expr[right]
      {
        $$ = ASTbinop($left, $right, BO_lt);
        AddLocToNode($$, &@left, &@right);
      }
    | expr[left] GT expr[right]
      {
        $$ = ASTbinop($left, $right, BO_gt);
        AddLocToNode($$, &@left, &@right);
      }
    | expr[left] LE expr[right]
      {
        $$ = ASTbinop($left, $right, BO_le);
        AddLocToNode($$, &@left, &@right);
      }
    | expr[left] GE expr[right]
      {
        $$ = ASTbinop($left, $right, BO_ge);
        AddLocToNode($$, &@left, &@right);
      }
    | expr[left] OR expr[right]
      {
        $$ = ASTbinop($left, $right, BO_or);
        AddLocToNode($$, &@left, &@right);
      }
    | expr[left] NE expr[right]
      {
        $$ = ASTbinop($left, $right, BO_ne);
        AddLocToNode($$, &@left, &@right);
      }
    | expr[left] AND expr[right]
      {
        $$ = ASTbinop($left, $right, BO_and);
        AddLocToNode($$, &@left, &@right);
      }
    | MINUS expr %prec NEGPREC
      {
        $$ = ASTmonop($2, MO_neg);
      }
    |  NEG expr
      {
        $$ = ASTmonop($2, MO_not);
      }
    | BRACKET_L expr BRACKET_R
      {
        $$ = $2;
      }
    | BRACKET_L types BRACKET_R expr %prec CAST
      {
        $$ = ASTcast($4, $2);
      }
    | ID BRACKET_L exprs BRACKET_R %prec FUNCALLPREC
      {
        $$ = ASTfuncall($3, $1);
      }
    | ID BRACKET_L BRACKET_R %prec FUNCALLPREC
      {
        $$ = ASTfuncall(NULL, $1);
      }
    ;

/* TODO: CHECK THIS... */
exprs: expr COMMA exprs
      {
        $$ = ASTexprs($1, $3);
      }
      | expr
        {
          $$ = ASTexprs($1, NULL);
        }
      ;

constant: floatval
          {
            $$ = $1;
          }
        | intval
          {
            $$ = $1;
          }
        | boolval
          {
            $$ = $1;
          }
        ;

floatval: FLOAT
           {
             $$ = ASTfloat($1);
           }
         ;

intval: NUM
        {
          if ($1 > 2147483647 || $1 < 0) 
          {
            yyerror("INTEGER OVERFLOW");
          } 
          else 
          {
            $$ = ASTnum($1);
          }
        }
      ;

boolval: TRUEVAL
         {
           $$ = ASTbool(true);
         }
       | FALSEVAL
         {
           $$ = ASTbool(false);
         }
       ;

types: INTTYPE
       {
         $$ = CT_int;
       }
     | FLOATTYPE
       {
         $$ = CT_float;
       }
     | BOOLTYPE
       {
         $$ = CT_bool;
       }
      | VOIDTYPE
        {
          $$ = CT_void;
        }
      ;
%%

void AddLocToNode(node_st *node, void *begin_loc, void *end_loc)
{
    // Needed because YYLTYPE unpacks later than top-level decl.
    YYLTYPE *loc_b = (YYLTYPE*)begin_loc;
    YYLTYPE *loc_e = (YYLTYPE*)end_loc;
    NODE_BLINE(node) = loc_b->first_line;
    NODE_BCOL(node) = loc_b->first_column;
    NODE_ELINE(node) = loc_e->last_line;
    NODE_ECOL(node) = loc_e->last_column;
}

static int yyerror( char *error)
{
  CTI(CTI_ERROR, true, "line %d, col %d\nError parsing source code: %s\n",
            global.line, global.col, error);
  CTIabortOnError();
  return( 0);
}

node_st *SPdoScanParse(node_st *root)
{
    DBUG_ASSERT(root == NULL, "Started parsing with existing syntax tree.");
    yyin = fopen(global.input_file, "r");
    if (yyin == NULL) {
        CTI(CTI_ERROR, true, "Cannot open file '%s'.", global.input_file);
        CTIabortOnError();
    }
    yyparse();
    return parseresult;
}
