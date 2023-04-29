/**
 * @file
 *
 * Traversal: TypeChecking
 * UID      : TC
 *
 * Authors: Ryan Brispat, Joshua Turpijn
 * Programme: Pre-Master Software Engineering
 * Date: 02 / 04 / 2023
 * 
 * This file checks all (inferred) types to their
 * declarations.
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "palm/hash_table.h"
#include "ccngen/enum.h"
#include "palm/ctinfo.h"
#include <stdio.h>
// 1: int
// 2: float
// 3: bool
// 4: void

int availbleTypesIntFloat[] = {1,2};
int availbleTypesIntFloatBool[] = {1,2,3};
int availbleTypesBool[] = {3};

struct ctinfo TCerrors[100];
int TCindexError = 0;

void TCprint(void* key, void* value) 
{
    int *type = value;
    printf("PRINT: key: %p, type: %d\n", key, *type);
}

void insertIntInTable(node_st *node, int type, htable_st *table) {
    struct data_tc *data = DATA_TC_GET();
    int *i = (int *) malloc(sizeof(int));
    *i = type;
    HTinsert(table, node, i);
}

int isValid(node_st *child, int types[]) {
    struct data_tc *data = DATA_TC_GET();
    int *type = HTlookup(data->TC_typetable, child);
    if (type == NULL) {
        printf("ERROR: Type not found in table\n");
        return -1;
    }
    for (int i = 0; i < sizeof(types); i++) {
        if (*type == types[i]) {
            return types[i];
        }
    }
    return -1;
}

void error(node_st *node, char message[]) {
        struct ctinfo error = {
            .first_line = NODE_BLINE(node),
            .first_column = NODE_BCOL(node),
            .last_line = NODE_ELINE(node),
            .last_column = NODE_ECOL(node),
            .filename = NODE_FILENAME(node),
            .line = message,
        };
        TCerrors[TCindexError] = error;
        TCindexError++;
}

void TCinit() { 
    struct data_tc *data = DATA_TC_GET();
    data->TC_errortable = HTnew_Ptr(8192);
    data->TC_typetable = HTnew_Ptr(8192);
    return; 
} 
void TCfini() { 
    return; 
}

/**
 * @fn TCprogram
 */
node_st *TCprogram(node_st *node)
{
    TRAVchildren(node);
    if(TCindexError > 0) {
        for(int i = 0; i < TCindexError; i++) {
            CTIobj(CTI_ERROR, true, TCerrors[i], "");
        }
        CCNerrorAction();
    }
    return node;
}

/**
 * @fn TCfloat
 * add pointer to tc_types_table
 */
node_st *TCfloat(node_st *node)
{
    insertIntInTable(node, 2, DATA_TC_GET()->TC_typetable);
    FLOAT_INFERREDTYPE(node) = CT_float;
    return node;
}

/**
 * @fn TCbool
 * add pointer to tc_types_table
 */
node_st *TCbool(node_st *node)
{
    insertIntInTable(node, 3, DATA_TC_GET()->TC_typetable);
    BOOL_INFERREDTYPE(node) = CT_bool;
    return node;
}

/**
 * @fn TCnum
 * add pointer to tc_types_table
 */
node_st *TCnum(node_st *node)
{
    if(NUM_VAL(node) >= 2147483647 || NUM_VAL(node) <= -2147483648) {
        CCNerrorPhase();
        error(node, "TYPE ERROR: IN NUM\n");
        return node;
    }
    insertIntInTable(node, 1, DATA_TC_GET()->TC_typetable);
    NUM_INFERREDTYPE(node) = CT_int;
    return node;
}

/**
 * @fn TCfundef
 */
node_st *TCfundef(node_st *node)
{
    insertIntInTable(node, FUNDEF_TYPE(node), DATA_TC_GET()->TC_typetable);
    TRAVchildren(node);
    return node;
}

/**
 * @fn TCglobdecl
 */
node_st *TCglobdecl(node_st *node)
{
    insertIntInTable(node, GLOBDECL_TYPE(node), DATA_TC_GET()->TC_typetable);
    TRAVchildren(node);
    return node;
}

// Operations
/**
 * @fn TCmonop
 */
node_st *TCmonop(node_st *node)
{
    TRAVchildren(node);
    int result = isValid(MONOP_OPERAND(node), availbleTypesIntFloatBool);
    if(result == -1) {
        error(node, "TYPE ERROR: IN MONOP\n");
        return node;
    }
    MONOP_INFERREDTYPE(node) = result;
    insertIntInTable(node, result, DATA_TC_GET()->TC_typetable);
    return node;
}

/**
 * @fn TCbinop
 */
node_st *TCbinop(node_st *node)
{
    TRAVchildren(node);

    int resultLEFT;
    int resultRIGHT;

    switch (BINOP_OP(node))
    {
    case BO_add:
    case BO_sub:
    case BO_mul:
    case BO_div:
    case BO_mod:
        resultLEFT = isValid(BINOP_LEFT(node), availbleTypesIntFloat);
        resultRIGHT = isValid(BINOP_RIGHT(node), availbleTypesIntFloat);
        if(resultLEFT == -1 || resultRIGHT == -1 || resultLEFT != resultRIGHT) {
            error(node, "TYPE ERROR: IN ARITHMETIC BINOP\n");
            return node;
        }
        BINOP_INFERREDTYPE(node) = resultLEFT;
        insertIntInTable(node, resultLEFT, DATA_TC_GET()->TC_typetable);
        break;
    case BO_lt:
    case BO_le:
    case BO_gt:
    case BO_ge:
        resultLEFT = isValid(BINOP_LEFT(node), availbleTypesIntFloat);
        resultRIGHT = isValid(BINOP_RIGHT(node), availbleTypesIntFloat);
        if(resultLEFT == -1 || resultRIGHT == -1 || resultLEFT != resultRIGHT) {
            error(node, "TYPE ERROR: IN COMPARISON BINOP\n");
            return node;
        }
        BINOP_INFERREDTYPE(node) = resultLEFT;
        insertIntInTable(node, 3, DATA_TC_GET()->TC_typetable);
        break;
    case BO_eq:
    case BO_ne:
    // CASES FOR NUMBERS, FLOATS AND BOOLS
        resultLEFT = isValid(BINOP_LEFT(node), availbleTypesIntFloatBool);
        resultRIGHT = isValid(BINOP_RIGHT(node), availbleTypesIntFloatBool);
        if(resultLEFT == -1 || resultRIGHT == -1 || resultLEFT != resultRIGHT) {
            error(node, "TYPE ERROR: IN EQUALITY BINOP\n");
            return node;
        }
        BINOP_INFERREDTYPE(node) = resultLEFT;
        insertIntInTable(node, 3, DATA_TC_GET()->TC_typetable);
        break;
    case BO_and:
    case BO_or:
    // CASES FOR BOOLS
        resultLEFT = isValid(BINOP_LEFT(node), availbleTypesBool);
        resultRIGHT = isValid(BINOP_RIGHT(node), availbleTypesBool);
        if(resultLEFT == -1 || resultRIGHT == -1 || resultLEFT != resultRIGHT) {
            error(node, "TYPE ERROR: IN BOOLEAN BINOP\n");
            return node;
        }
        BINOP_INFERREDTYPE(node) = resultLEFT;
        insertIntInTable(node, 3, DATA_TC_GET()->TC_typetable);
        break;
    default:
        error(node, "TYPE ERROR: BINOP NODE NOT FOUND\n");
        break;
    }
    return node;
}

// VARS
/**
 * @fn TCvar
 */
node_st *TCvar(node_st *node)
{
    TRAVchildren(node);
    if(VAR_DECL(node) == NULL) {
        error(node, "TYPE ERROR: VAR DECL NOT FOUND\n");
        return node;
    }
    int type = STE_TYPE(VAR_DECL(node));
    VAR_INFERREDTYPE(node) = type;
    insertIntInTable(node, type, DATA_TC_GET()->TC_typetable);
    return node;
}

/**
 * @fn TCvarlet
 */
node_st *TCvarlet(node_st *node)
{
    TRAVchildren(node);
    int type = STE_TYPE(VARLET_DECL(node));
    insertIntInTable(node, type, DATA_TC_GET()->TC_typetable);
    VARLET_INFERREDTYPE(node) = STE_TYPE(VARLET_DECL(node));
    return node;
}

/**
 * @fn TCvardecl
 * Vardecls should be type matched between identifier type and expression type
 */
node_st *TCvardecl(node_st *node)
{
    TRAVchildren(node);
    int typeLeft = VARDECL_TYPE(node);
    if(VARDECL_INIT(node) == NULL) {
        insertIntInTable(node, typeLeft, DATA_TC_GET()->TC_typetable);
        return node;
    }
    int typeRight = isValid(VARDECL_INIT(node), availbleTypesIntFloatBool);
    if(typeLeft != typeRight) {
        error(node, "TYPE ERROR: IN VARDECL\n");
        return node;
    }
    insertIntInTable(node, typeLeft, DATA_TC_GET()->TC_typetable);
    return node;
}

// Expressions
/**
 * @fn TCcast
 * Cast can only succeed if left and right are not equal and are both num (int or float)
 */
node_st *TCcast(node_st *node)
{
    TRAVchildren(node);
    int typeLeft = CAST_TYPE(node);
    int typeRight = isValid(CAST_EXPR(node), availbleTypesIntFloatBool);
    CAST_INFERREDTYPE(node) = typeRight;

    if(typeLeft == 4 || typeRight == 4 || typeLeft == typeRight) {
        // Insert Error
        error(node, "TYPE ERROR: IN CAST\n");
        return node;
    }
    insertIntInTable(node, typeLeft, DATA_TC_GET()->TC_typetable);
    return node;
}

/**
 * @fn TCfuncall
 */
node_st *TCfuncall(node_st *node)
{
    TRAVchildren(node);
    node_st* ParamTemp = STE_PARAMS(FUNCALL_DECL(node));
    node_st* funcallArgs = FUNCALL_ARGS(node);

    if(ParamTemp == NULL && funcallArgs == NULL) {
        int typeLeft = STE_TYPE(FUNCALL_DECL(node));
        FUNCALL_INFERREDTYPE(node) = STE_TYPE(FUNCALL_DECL(node));
        insertIntInTable(node, typeLeft, DATA_TC_GET()->TC_typetable);
        return node;
    }

    if((ParamTemp == NULL && funcallArgs != NULL) || (ParamTemp != NULL && funcallArgs == NULL)) {
        // We expect to have the same amount of arguments as parameters
        char Errormessage[100];
        sprintf(Errormessage, "TYPE ERROR: %s IN FUNCALL PSYCH THAT'S THE WRONG ARITY\n", FUNCALL_NAME(node));
        error(node, Errormessage);
        return node;
    }
    
    while(ParamTemp != NULL) {
        if(funcallArgs == NULL) {
            char Errormessage[100];
            sprintf(Errormessage, "TYPE ERROR: %s IN FUNCALL NOT ENOUGH ARGUMENTS GIVEN\n", FUNCALL_NAME(node));
            error(node, Errormessage);
            return node;
        }
        int typeLeft = PARAM_TYPE(ParamTemp);
        int typeRight = isValid(EXPRS_EXPR(funcallArgs), availbleTypesIntFloatBool);
        if(typeLeft != typeRight) {
            char Errormessage[100];
            sprintf(Errormessage, "TYPE ERROR: %s IN FUNCALL NOT RIGHT ARGUMENT GIVEN\n", FUNCALL_NAME(node));
            error(node, Errormessage);
            return node;
        }
        ParamTemp = PARAM_NEXT(ParamTemp);
        funcallArgs = EXPRS_NEXT(funcallArgs);
    }
    if(funcallArgs!= NULL) {
        char Errormessage[100];
        sprintf(Errormessage, "TYPE ERROR: %s IN FUNCALL TO MANY ARGUMENTS GIVEN\n", FUNCALL_NAME(node));
        error(node, Errormessage);
        return node;
    } 
    // Add itself with its own return type to the typetable
    int typeLeft = STE_TYPE(FUNCALL_DECL(node));
    FUNCALL_INFERREDTYPE(node) = STE_TYPE(FUNCALL_DECL(node));
    insertIntInTable(node, typeLeft, DATA_TC_GET()->TC_typetable);
    return node;
}

/**
 * @fn TCarrexpr
 */
node_st *TCarrexpr(node_st *node)
{
    TRAVchildren(node);
    return node;
}

// Statements
/**
 * @fn TCassign
 */
node_st *TCassign(node_st *node)
{
    TRAVchildren(node);
    int typeLeft = STE_TYPE(VARLET_DECL(ASSIGN_LET(node)));
    int typeRight = isValid(ASSIGN_EXPR(node), availbleTypesIntFloatBool);
    if(typeLeft != typeRight) {
        error(node, "TYPE ERROR: IN ASSIGN\n");
        return node;
    }
    insertIntInTable(node, typeLeft, DATA_TC_GET()->TC_typetable);
    return node;
}

/**
 * @fn TCdowhile
 */
node_st *TCdowhile(node_st *node)
{
    TRAVchildren(node);
    if(!isValid(DOWHILE_COND(node), availbleTypesBool)) {
        // Insert Error
        error(node, "TYPE ERROR: IN DOWHILE CONDITION NOT A BOOLEAN\n");
        return node;
    }
    return node;
}

/**
 * @fn TCfor
 */
node_st *TCfor(node_st *node)
{  
    TRAVchildren(node);
    int starttype = isValid(FOR_START_EXPR(node), availbleTypesIntFloat);
    int stoptype = isValid(FOR_STOP(node), availbleTypesIntFloat);
    int steptype; 
    if(FOR_STEP(node) != NULL) {
        steptype = isValid(FOR_STEP(node), availbleTypesIntFloat);
    } else {
        steptype = 1;
    }
    if(starttype != 1 || stoptype != 1 || steptype != 1) {
        error(node, "TYPE ERROR: IN FOR START, STOP OR STEP NOT A NUM\n");
        return node;
    }
    return node;
}

/**
 * @fn TCifelse
 */
node_st *TCifelse(node_st *node)
{
    TRAVchildren(node);
    if(!isValid(IFELSE_COND(node), availbleTypesBool)) {
        error(node, "TYPE ERROR: IN IF-ELSE CONDITION NOT A BOOLEAN\n");
        return node;
    }
    return node;
}

/**
 * @fn TCwhile
 */
node_st *TCwhile(node_st *node)
{
    TRAVchildren(node);
    if(!isValid(WHILE_COND(node), availbleTypesBool)) {
        error(node, "TYPE ERROR: IN WHILE CONDITION NOT A BOOLEAN\n");
        return node;
    }
    return node;
}

/**
 * @fn TCreturn
 */
node_st *TCreturn(node_st *node)
{
    TRAVchildren(node);
    int returnType =  RETURN_TYPE(node);
    // return type of expression 
    int returnExpr = isValid(RETURN_EXPR(node), availbleTypesIntFloatBool);
    if(returnExpr >= 0) {
        if (!returnExpr || returnType != returnExpr) {   
            error(node, "TYPE ERROR: IN RETURN MUST MATCH FUNCTION TYPE\n");
            return node;
        }
        insertIntInTable(node, returnExpr, DATA_TC_GET()->TC_typetable);
        return node;
    }

    // if not void, has return type
    if(returnType != 4) {
        error(node, "TYPE ERROR: EXPECTED A RETURN TYPE\n");
        return node;
    }
    return node;
}
