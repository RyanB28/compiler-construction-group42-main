/**
 * @file
 *
 * This file contains the code for the Print traversal.
 * The traversal has the uid: PRT
 *
 * Authors: Ryan Brispat, Joshua Turpijn
 * Programme: Pre-Master Software Engineering
 * Date: 02 / 04 / 2023
 * 
 * This file prints all the data.
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include "palm/dbug.h"

#include <stdio.h>
// Helper function
/** 
 * @fn 
*/
char* getTypeString(int number) {
    char * str = NULL;
    switch (number)
    {
    case 1:
        str = "int";
        break;
    case 2:
        str = "float";
        break;
    case 3:
        str = "bool";
        break;
    case 4:
        str = "void";
        break;
    default:
        str = "ERROR";
        break;
    }
}

/**
 * @fn PRTstmts
 */
node_st *PRTstmts(node_st *node)
{
    TRAVstmt(node);
    TRAVnext(node);
    return node;
}

/**
 * @fn PRTassign
 */
node_st *PRTassign(node_st *node)
{

    if (ASSIGN_LET(node) != NULL) {
        TRAVlet(node);
        printf( " = ");
    }
    
    TRAVexpr(node);
    printf( ";\n");
  

    return node;
}

/**
 * @fn PRTbinop
 */
node_st *PRTbinop(node_st *node)
{
    char *tmp = NULL;
    printf( "( ");

    TRAVleft(node);

    switch (BINOP_OP(node)) {
        case BO_add:
        tmp = "+";
        break;
        case BO_sub:
        tmp = "-";
        break;
        case BO_mul:
        tmp = "*";
        break;
        case BO_div:
        tmp = "/";
        break;
        case BO_mod:
        tmp = "%";
        break;
        case BO_lt:
        tmp = "<";
        break;
        case BO_le:
        tmp = "<=";
        break;
        case BO_gt:
        tmp = ">";
        break;
        case BO_ge:
        tmp = ">=";
        break;
        case BO_eq:
        tmp = "==";
        break;
        case BO_ne:
        tmp = "!=";
        break;
        case BO_or:
        tmp = "||";
        break;
        case BO_and:
        tmp = "&&";
        break;
        case BO_NULL:
        DBUG_ASSERT(false, "unknown binop detected!");
    }

    printf( " %s ", tmp);
    
    TRAVright(node);

    printf( ")(%d:%d-%d)", NODE_BLINE(node), NODE_BCOL(node), NODE_ECOL(node));

    return node;
}

/**
 * @fn PRTvarlet
 */
node_st *PRTvarlet(node_st *node)
{
    printf("%s(%d:%d)", VARLET_NAME(node), NODE_BLINE(node), NODE_BCOL(node));
    TRAVchildren(node);
    return node;
}

/**
 * @fn PRTvar
 */
node_st *PRTvar(node_st *node)
{
    printf( "%s", VAR_NAME(node));
    return node;
}

/**
 * @fn PRTnum
 */
node_st *PRTnum(node_st *node)
{
    printf("%d", NUM_VAL(node));
    return node;
}

/**
 * @fn PRTfloat
 */
node_st *PRTfloat(node_st *node)
{
    printf( "%f", FLOAT_VAL(node));
    return node;
}

/**
 * @fn PRTbool
 */
node_st *PRTbool(node_st *node)
{
    char *bool_str = BOOL_VAL(node) ? "true" : "false";
    printf("%s", bool_str);
    return node;
}

/**
 * @fn PRTprogram
 */
node_st *PRTprogram(node_st *node)
{
    printf( "START OF PROGRAM\n");
    TRAVchildren(node);
    return node;
}

/**
 * @fn PRTdecls
 */
node_st *PRTdecls(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn PRTexprs
 */
node_st *PRTexprs(node_st *node)
{
    return node;
}

/**
 * @fn PRTarrexpr
 */
node_st *PRTarrexpr(node_st *node)
{
    return node;
}

/**
 * @fn PRTids
 */
node_st *PRTids(node_st *node)
{
    return node;
}

/**
 * @fn PRTexprstmt
 */
node_st *PRTexprstmt(node_st *node)
{
    return node;
}

/**
 * @fn PRTreturn
 */
node_st *PRTreturn(node_st *node)
{
    printf("return ");
    TRAVexpr(node);
    printf("\n");
    return node;
}

/**
 * @fn PRTfuncall
 */
node_st *PRTfuncall(node_st *node)
{
    printf("%s(", FUNCALL_NAME(node));
    TRAVchildren(node);
    printf(")");
    return node;
}

/**
 * @fn PRTcast
 */
node_st *PRTcast(node_st *node)
{
    return node;
}

/**
 * @fn PRTfundefs
 */
node_st *PRTfundefs(node_st *node)
{
    return node;
}

/**
 * @fn PRTfundef
 */
node_st *PRTfundef(node_st *node)
{
    if(FUNDEF_BODY(node) == NULL) {
        printf("EXTERN ");
    }
    if(FUNDEF_EXPORT(node)) {
        printf("EXPORT ");
    }
    printf("%s %s(", getTypeString(FUNDEF_TYPE(node)), FUNDEF_NAME(node));
    TRAVparams(node);
    printf(") {\n");
    TRAVbody(node);
    printf("}\n");
    return node;
}

/**
 * @fn PRTfunbody
 */
node_st *PRTfunbody(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn PRTifelse
 */
node_st *PRTifelse(node_st *node)
{
    printf("if(");
    TRAVcond(node);
    printf(") {\n");
    TRAVthen(node);
    printf("} else {\n");
    TRAVelse_block(node);
    printf("}\n");
    return node;
}

/**
 * @fn PRTwhile
 */
node_st *PRTwhile(node_st *node)
{
    printf("while(");
    TRAVcond(node);
    printf(") { \n");
    TRAVblock(node);
    printf("} \n");
    return node;
}

/**
 * @fn PRTdowhile
 */
node_st *PRTdowhile(node_st *node)
{
    printf("do {\n");
    TRAVblock(node);
    printf("} while (");
    TRAVcond(node);
    printf(");\n");
    return node;
}

/**
 * @fn PRTfor
 */
node_st *PRTfor(node_st *node)
{
    printf("for(int %s = ", FOR_VAR(node));
    TRAVstart_expr(node);
    printf(", ");
    TRAVstop(node);
    printf(", ");
    TRAVstep(node);
    printf(") {");
    TRAVblock(node);
    printf("}\n");
    return node;
}

/**
 * @fn PRTglobdecl
 */
node_st *PRTglobdecl(node_st *node)
{
    printf("globdecl: %i %s (%d:%d)\n", GLOBDECL_TYPE(node), GLOBDECL_NAME(node), NODE_BLINE(node), NODE_BCOL(node));
    TRAVchildren(node);
    return node;
}

/**
 * @fn PRTglobdef
 */
node_st *PRTglobdef(node_st *node)
{
    if(GLOBDEF_EXPORT(node)) {
        printf("export ");
    }
    printf("globdef: %s %s = ", getTypeString(GLOBDEF_TYPE(node)), GLOBDEF_NAME(node));
    TRAVinit(node);
    printf("; (%d:%d)\n", NODE_BLINE(node), NODE_BCOL(node));
    return node;
}

/**
 * @fn PRTparam
 */
node_st *PRTparam(node_st *node)
{
    printf("%s %s", getTypeString(PARAM_TYPE(node)), PARAM_NAME(node));
    if(PARAM_NEXT(node) != NULL) {
        printf(", ");
    }
    TRAVnext(node);
    return node;
}

/**
 * @fn PRTvardecl
 */
node_st *PRTvardecl(node_st *node)
{
    printf("%s %s = ",getTypeString(VARDECL_TYPE(node)), VARDECL_NAME(node));
    if(VARDECL_INIT(node) != NULL) {
        TRAVinit(node);
    }
    else {
        printf("NULL");
    }
    printf("\n");
    TRAVnext(node);
    return node;
}

/**
 * @fn PRTmonop
 */
node_st *PRTmonop(node_st *node)
{
    printf("-");
    TRAVchildren(node);
    return node;
}

/**
 * @fn PRTste
 */
node_st *PRTste(node_st *node)
{
    printf("SYMBOL TABLE ENTRY: %s, %d, \n", STE_NAME(node), STE_SCOPE(node));
    TRAVchildren(node);
    return node;
}

/**
 * @fn PRTste
 */
node_st *PRTcgg(node_st *node)
{
    printf("CGG: ID: %d, TYPE: %d\n", CGG_ID(node), CGG_TYPE(node));
    TRAVchildren(node);
    return node;
}

/**
 * @fn PRTste
 */
node_st *PRTcge(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn PRTste
 */
node_st *PRTcgc(node_st *node)
{
    TRAVchildren(node);
    printf("TYPE: %d, VALUEB %d, VALUEF %f VALUEINT %d\n", CGC_TYPE(node), CGC_VALUEB(node), CGC_VALUEF(node), CGC_VALUEI(node));
    return node;
}


node_st *PRTconditionalexpression(node_st *node)
{
    TRAVpredexpr(node);
    printf(" ? ");
    TRAVtrueexpr(node);
    printf(" : ");
    TRAVelseexpr(node);
    printf("\n");
    return node;
}

node_st *PRTcgee(node_st* node) {
    TRAVchildren(node);
    return node;
}

node_st *PRTcgie(node_st* node) {
    TRAVchildren(node);
    return node;
}

