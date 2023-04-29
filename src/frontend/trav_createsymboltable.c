/**
 * @file
 *
 * Traversal: CreateSymbolTable
 * UID      : CST
 *
 * Authors: Ryan Brispat, Joshua Turpijn
 * Programme: Pre-Master Software Engineering
 * Date: 02 / 04 / 2023
 * 
 * This file creates the symbolTable in a 
 * node tree data structure.
 *
 */

#include <stddef.h>
#include "ccn/ccn.h"
#include "ccngen/trav.h"
#include "ccngen/ast.h"
#include "ccngen/enum.h"
#include "palm/ctinfo.h"

#include <stdio.h>
#include <string.h>

struct ctinfo errors[100];
int indexError = 0;

node_st* symboltablesRoot[1000];
int indexSymbolTableNode = 0;

node_st* GetSTENode(char name[], node_st* currentNode) {
    node_st* STENode = NULL;
    node_st* TempSteNode = symboltablesRoot[indexSymbolTableNode];
    // Loop trough the temp nodes to find the main code
    while(TempSteNode) {
        if(TempSteNode == NULL) {
            break;
        }
        
        if(strcmp(name, STE_NAME(TempSteNode)) == 0) {
            STENode = TempSteNode;
            break;
        }
        TempSteNode = STE_NEXT(TempSteNode);
    }
    if(!STENode) {
        TempSteNode = symboltablesRoot[0];
        while(TempSteNode)
        {
            if(strcmp(name, STE_NAME(TempSteNode)) == 0) {
                STENode = TempSteNode;
                break;
            }
            TempSteNode = STE_NEXT(TempSteNode);
        }
    }
    
    if(!STENode) {
        struct ctinfo error = {
            .first_line = NODE_BLINE(currentNode),
            .first_column = NODE_BCOL(currentNode),
            .last_line = NODE_ELINE(currentNode),
            .last_column = NODE_ECOL(currentNode),
            .filename = NODE_FILENAME(currentNode),
            .line = "The entry is not found in the context. Please check the name of the variable",
        };
        errors[indexError] = error;
        indexError++;
    }
    return STENode;

}

node_st* AddToAst(int scope, int type, char name[], node_st* params) { // TODO TEST FUNCTION

    node_st * newNode = ASTste(type, name, scope, 0, params);
    node_st * tempValue = symboltablesRoot[scope];

    if(tempValue == NULL) {
        symboltablesRoot[scope] = CCNcopy(newNode);
        return newNode;
    }
    int counter = 1;
    while(STE_NEXT(tempValue) != NULL) {
        counter++;
        tempValue = STE_NEXT(tempValue);
    }
    STE_ID(newNode) = counter;
    STE_NEXT(tempValue) = CCNcopy(newNode);
    return newNode;
}


/**
 * @fn CSTprogram
 */
node_st *CSTprogram(node_st *node)
{
    TRAVchildren(node);
    // printf("ERROR COUNT %d", indexError);
    if(indexError > 0) {
        for(int i = 0; i < indexError; i++) {
            CTIobj(CTI_ERROR, true, errors[i], "");
        }
        CCNerrorAction();
    }
    
    PROGRAM_SYMBOL_TABLE(node) = symboltablesRoot[0];
    return node;
}

/**
 * @fn CSTglobdef
 */
node_st *CSTglobdef(node_st *node)
{
    node_st* STE = AddToAst(0, GLOBDEF_TYPE(node), GLOBDEF_NAME(node), 0x0);
    GLOBDEF_DECL(node) = STE;
    TRAVchildren(node);
    return node;
}

/**
 * @fn CSTglobdecl
 */
node_st *CSTglobdecl(node_st *node)
{
    AddToAst(0, GLOBDECL_TYPE(node), GLOBDECL_NAME(node), 0x0);
    TRAVchildren(node);
    return node;
}

/**
 * @fn CSTfundef
 */
node_st *CSTfundef(node_st *node)
{
    AddToAst(0, FUNDEF_TYPE(node), FUNDEF_NAME(node), FUNDEF_PARAMS(node));
    indexSymbolTableNode++;
    TRAVparams(node);
    TRAVbody(node);
    FUNDEF_SYMBOL_TABLE(node) = symboltablesRoot[indexSymbolTableNode]; 
    return node;
}

/**
 * @fn CSTvardecl
 */
node_st *CSTvardecl(node_st *node)
{
    TRAVinit(node);
    node_st* entre = AddToAst(indexSymbolTableNode, VARDECL_TYPE(node), VARDECL_NAME(node), 0x0);
    VARDECL_DECL(node) = entre;
    TRAVnext(node);
    return node;
}

/**
 * @fn CSTparam
 */
node_st *CSTparam(node_st *node)
{
    AddToAst(indexSymbolTableNode, PARAM_TYPE(node), PARAM_NAME(node), 0x0);
    TRAVchildren(node);
    return node;
}

/**
 * @fn CSTvar
 */
node_st *CSTvar(node_st *node)
{
    node_st* STEnode = GetSTENode(VAR_NAME(node), node);
    VAR_DECL(node) = STEnode;
    TRAVchildren(node);
    return node;
}

/**
 * @fn CSTfuncall
 */
node_st *CSTfuncall(node_st *node)
{
    node_st* STEnode = GetSTENode(FUNCALL_NAME(node), node);
    // printf("THIS IS INSIDE CST PARAMS:%p, NAME: %s\n", STE_PARAMS(STEnode), FUNCALL_NAME(node));
    FUNCALL_DECL(node) = STEnode;
    TRAVchildren(node);
    return node;
}

/**
 * @fn CSTfunbody
 */
node_st *CSTfunbody(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn CSTvarlet
 */
node_st *CSTvarlet(node_st *node)
{
    node_st* STEnode = GetSTENode(VARLET_NAME(node), node);
    VARLET_DECL(node) = STEnode;
    return node;
}

/**
 * @fn CSTreturn
 */
node_st *CSTreturn(node_st *node)
{
    node_st* tempNode = symboltablesRoot[0];
    while(STE_NEXT(tempNode) != NULL) {
        tempNode = STE_NEXT(tempNode);
    }
    RETURN_TYPE(node) = STE_TYPE(tempNode);
    TRAVchildren(node);
    return node;
}
