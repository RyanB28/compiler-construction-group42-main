/**
 * @file
 *
 * Traversal: ReplaceLoops
 * UID      : RL
 *
 * Authors: Ryan Brispat, Joshua Turpijn
 * Programme: Pre-Master Software Engineering
 * Date: 02 / 04 / 2023
 * 
 * This file should replace loops, but inner loopes
 * remain to be reset before entering.
 *
 */
#include <stdio.h>

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/enum.h"
#include "palm/ctinfo.h"

char NamesToChange[256][256];
int NamesToChangeCounter = 0;
bool insideFor = false;
node_st* latestFunbody;
int Counter = 0;

/**
 * @fn RLfundef
 */
node_st *RLfunbody(node_st *node)
{
    latestFunbody = node;
    TRAVchildren(node);
    return node;
}

/**
 * @fn RLStmts
 * This function should reset after looping
 * but there's a flaw in this logic.
*/
node_st *RLstmts(node_st *node) {
    TRAVchildren(node);
    // if (NODE_TYPE(STMTS_STMT(node)) == NT_FOR){
    //     size_t newSize = strlen(FOR_VAR(STMTS_STMT(node))) + 8;
    //     char newVarNameStart[newSize];
    //     sprintf(newVarNameStart, "%s_for_%d", FOR_VAR(STMTS_STMT(node)), Counter);

    //     STMTS_NEXT(node) = CCNcopy(ASTstmts(ASTassign(
    //         ASTvarlet(newVarNameStart, NULL),
    //         ASTbinop(
    //             ASTvar(newVarNameStart),
    //             STMTS_STMT(node),
    //             BO_add
    //         )
    //     ), NULL));
    //     return node;
    // }

    return node;
}

/**
 * @fn RLfor
 */
node_st *RLfor(node_st *node)
{
    if(latestFunbody == NULL){
        struct ctinfo error = {
            .first_line = NODE_BLINE(node),
            .first_column = NODE_BCOL(node),
            .last_line = NODE_ELINE(node),
            .last_column = NODE_ECOL(node),
            .filename = NODE_FILENAME(node),
            .line = "For loops are not allowed in the global scope",
        };
        CTIobj(CTI_ERROR, true, error, "");
        CCNerrorAction();
    }

    size_t newSize = strlen(FOR_VAR(node)) + 8;
    char initVarNameStart[newSize];
    char newVarNameStart[newSize];
    sprintf(initVarNameStart, "%s_for_%d", FOR_VAR(node), Counter);
    sprintf(newVarNameStart, "%s_for_%d", FOR_VAR(node), Counter);

    // Allocate memory for the new names and copy the new names into it
    char *newVarNameStartCopy = malloc(newSize);
    strcpy(newVarNameStartCopy, newVarNameStart);

    node_st* startVarDecl = ASTvardecl(
        FOR_START_EXPR(node), // Init expression
        CCNcopy(FUNBODY_DECLS(latestFunbody)), // Vardecl Next
        newVarNameStartCopy, // Name
        CT_int // Type
    );

    // Add new VarDecl to the fundef
    FUNBODY_DECLS(latestFunbody) = startVarDecl;

    // Change the for loop to a while loop
    node_st* whileCond;
    if(FOR_STEP(node) == NULL || NUM_VAL(FOR_STEP(node)) == 0) {
        whileCond = ASTbinop(
            ASTvar(newVarNameStartCopy),
            FOR_STOP(node),
            BO_lt
        );
    } else {
        // for step not null BINOP(FOR_STEP(node))
        if(NUM_VAL(FOR_STEP(node)) > 0) {
            whileCond = ASTbinop(
                ASTvar(newVarNameStartCopy),
                FOR_STOP(node),
                BO_lt
            );
        } else {
            whileCond = ASTbinop(
                ASTvar(newVarNameStartCopy),
                FOR_STOP(node),
                BO_gt
            );
        }            
    }
    
    node_st* whileNode = ASTwhile(
        whileCond,
        FOR_BLOCK(node)
    );

    node_st* temp = FOR_BLOCK(node);
    while (STMTS_NEXT(temp) != NULL)
    {
        temp = STMTS_NEXT(temp);
    }
    
    // hier moet nog het forcl
    if(FOR_STEP(node) == NULL) {
        STMTS_NEXT(temp) = CCNcopy(ASTstmts(ASTassign(
            ASTvarlet(newVarNameStart, NULL), // This is before symbol table. So no STE
            ASTbinop(
                ASTvar(newVarNameStart),
                ASTnum(1),
                BO_add
            )
        ), NULL));
    } else {
        STMTS_NEXT(temp) = CCNcopy(ASTstmts(ASTassign(
            ASTvarlet(newVarNameStart, NULL), // This is before symbol table. So no STE
            ASTbinop(
                ASTvar(newVarNameStart),
                FOR_STEP(node),
                BO_add
            )
        ), NULL));
    }

    // Change the inner variable names to the new ones
    insideFor = true;
    strcpy(NamesToChange[NamesToChangeCounter], FOR_VAR(node));
    NamesToChangeCounter++;
    TRAVblock(node);
    insideFor = false; 
    Counter++;
    return whileNode;
}

/**
 * @fn RLdowhile
 */
node_st *RLdowhile(node_st *node)
{
    // // Search for the do while loop in the funbody
    // node_st* temp = FUNBODY_STMTS(latestFunbody);
    // while (temp != NULL)
    // {
    //     if(STMTS_STMT(temp) == node) {
    //         break;
    //     }
    //     temp = STMTS_NEXT(temp);
    // }
    // if(temp == NULL) {
    //     // HANDLE ERROR
    // }
    // STMTS_STMT(node) = DOWHILE_BLOCK(node);

    // // Get last item of the block
    // temp = DOWHILE_BLOCK(node);
    // while (STMTS_NEXT(temp) != NULL)
    // {
    //     temp = STMTS_NEXT(temp);
    // }
    // // Replace the do while loop with the block of the do while loop

    // // Search last element in the block and add the while loop
    TRAVchildren(node);
    return node;
}

/**
 * @fn RLvar
 */
node_st *RLvar(node_st *node)
{
    if(insideFor) {
        for (int i = 0; i < NamesToChangeCounter; i++)
        {
            if(strcmp(NamesToChange[i], VAR_NAME(node)) == 0) {
                size_t newNameSize = strlen(VAR_NAME(node)) + 8;
                char newName[newNameSize];
                sprintf(newName, "%s_for_%d", VAR_NAME(node), Counter);

                // Allocate memory for the new name and copy the new name into it
                VAR_NAME(node) = malloc(newNameSize);
                strcpy(VAR_NAME(node), newName);
                break;
            }
        }
    }
    
    TRAVchildren(node);
    return node;
}
/**
 * @fn RLvarlet
 */
node_st *RLvarlet(node_st *node)
{
    if(insideFor) {
        for (int i = 0; i < NamesToChangeCounter; i++)
        {
            if(strcmp(NamesToChange[i], VARLET_NAME(node)) == 0) {
                size_t newNameSize = strlen(VARLET_NAME(node)) + 8;
                char newName[newNameSize];
                sprintf(newName, "%s_for_%d", VARLET_NAME(node), Counter);

                // Allocate memory for the new name and copy the new name into it
                VARLET_NAME(node) = malloc(newNameSize);
                strcpy(VARLET_NAME(node), newName);
                break;
            }
        }
    }
    
    TRAVchildren(node);
    return node;
}