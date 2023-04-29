/**
 * @file
 *
 * Traversal: indexeren
 * UID      : CGI
 *
 *
 */
#include <stdio.h>

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/enum.h"

node_st* constTableNode;
int constTableIndex = 0;

node_st* globTableNode;
int globTableIndex = 0;

node_st* cgeeNode;
int cgeeIndex = 0;

node_st* cgieNode;
int cgieIndex = 0;


void CGIinit() { return; }
void CGIfini() { return; }

int counter = 0;

// This returns a index of the constant table
int AddToConstantTable(node_st* table, int type, bool valueb, int valuei, float valuef) {
    node_st* newNode;
    switch (type) {
        case CT_int:
            newNode = ASTcgc(constTableIndex, type, valuei, NULL, 0.0);
            break;
        case CT_float:
            newNode = ASTcgc(constTableIndex, type, NULL, NULL, valuef);
            break;
        case CT_bool:
            newNode = ASTcgc(constTableIndex, type, NULL, valueb, 0.0);
            break;
        default:
            printf("ERROR HANDLING");
    }

    // printf("Adding to constant table %d %d %d %f. Number: %d\n", type, valueb, valuei, valuef, counter);
    if(constTableNode == NULL) {
        constTableNode = newNode;
        constTableIndex++;
        return 0; 
    }

    node_st * tempNode = constTableNode;
    while(CGC_NEXT(tempNode) != NULL) {
        // THIS IS A OPTIMIZATION THAT DOES NOT WORK
        // switch (CGC_TYPE(tempNode))
        // {
        //     case CT_int:
        //         if(CGC_VALUEI(tempNode) == CGC_VALUEI(newNode)) {
        //             return CGC_INDEX(tempNode);
        //         }
        //         break;
        //     case CT_bool:
        //         if(CGC_VALUEB(tempNode) == CGC_VALUEB(newNode)) {
        //             return CGC_INDEX(tempNode);
        //         }
        //         break;
        //     case CT_float:
        //         if(CGC_VALUEF(tempNode) == CGC_VALUEF(newNode)) {
        //             return CGC_INDEX(tempNode);
        //         }
        //         break;
        // }
        tempNode = CGC_NEXT(tempNode);
    }

    CGC_NEXT(tempNode) = newNode;
    return constTableIndex++;
}

/**
 * @fn CGIprogram
 */
node_st *CGIprogram(node_st *node)
{
    TRAVchildren(node);
    PROGRAM_CG_CONST_TABLE(node) = constTableNode;
    PROGRAM_CG_GLOBAL_TABLE(node) = globTableNode;
    PROGRAM_CG_EXPORT_TABLE(node) = cgeeNode;
    PROGRAM_CG_IMPORT_TABLE(node) = cgieNode;
    return node;
}

/**
 * @fn CGIfloat
 */
node_st *CGIfloat(node_st *node)
{
    int constant = AddToConstantTable(constTableNode, CT_float, NULL, NULL, FLOAT_VAL(node));
    FLOAT_CONSTID(node) = constant;
    TRAVchildren(node);
    return node;
}

/**
 * @fn CGIbool
 */
node_st *CGIbool(node_st *node)
{
    bool value = BOOL_VAL(node);
    int constant = AddToConstantTable(constTableNode, CT_bool, value, NULL, 0x0);
    BOOL_CONSTID(node) = constant;
    TRAVchildren(node);
    return node;
}

/**
 * @fn CGIassign
 */
node_st *CGIassign(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn CGInum
 */
node_st *CGInum(node_st *node)
{
    int constant = AddToConstantTable(constTableNode, CT_int, NULL, NUM_VAL(node), 0x0);
    NUM_CONSTID(node) = constant;
    TRAVchildren(node);
    return node;
}

/**
 * @fn CGIglobdecl
 */
node_st *CGIglobdecl(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn CGIglobdecl
 */
node_st *CGIglobdef(node_st *node)
{
    node_st *temp = globTableNode;
    if(temp == NULL) {
        globTableNode = CCNcopy(ASTcgg(0, GLOBDEF_TYPE(node), GLOBDEF_NAME(node)));
        globTableIndex++;
        return node;
    }

    while (CGG_NEXT(temp) != NULL) {
        temp = CGG_NEXT(temp);
    }
    
    CGG_NEXT(temp) = CCNcopy(ASTcgg(globTableIndex, GLOBDEF_TYPE(node), GLOBDEF_NAME(node)));
    globTableIndex++;

    TRAVchildren(node);
    return node;
}


/**
 * @fn CGIvardecl
 */
node_st *CGIvardecl(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn CGIfundef
 */
node_st *CGIfundef(node_st *node)
{
    if(FUNDEF_EXPORT(node)) {
        node_st *NewNode = ASTcgee(FUNDEF_NAME(node), FUNDEF_TYPE(node), FUNDEF_NAME(node), FUNDEF_PARAMS(node));
        node_st *temp = cgeeNode;
        if(temp == NULL) {
            cgeeNode = CCNcopy(NewNode);
            cgeeIndex++;
            TRAVchildren(node);
            return node;
        }
        while (CGEE_NEXT(temp) != NULL) {
            temp = CGEE_NEXT(temp);
        }
        CGEE_NEXT(temp) = CCNcopy(NewNode);
        cgeeIndex++;
        TRAVchildren(node);
        return node;
    }
    if(FUNDEF_BODY(node) == NULL) {
        node_st* NewNode = ASTcgie(FUNDEF_NAME(node), FUNDEF_TYPE(node), FUNDEF_PARAMS(node), cgieIndex);
        node_st *temp = cgieNode;
        if(temp == NULL) {
            cgieNode = CCNcopy(NewNode);
            cgieIndex++;
            TRAVchildren(node);
            return node;
        }
        while(CGIE_NEXT(temp) != NULL) {
            temp = CGIE_NEXT(temp);
        }
        CGIE_NEXT(temp) = CCNcopy(NewNode);
        cgieIndex++;
        TRAVchildren(node);
        return node;
    }
    TRAVchildren(node);
    return node;
}