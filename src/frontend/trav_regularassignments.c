/**
 * @file
 *
 * Traversal: RegularAssignments
 * UID      : RS
 *
 * Authors: Ryan Brispat, Joshua Turpijn
 * Programme: Pre-Master Software Engineering
 * Date: 02 / 04 / 2023
 * 
 * This file splits all declarations into 
 * definitions and assignments.
 *
 */

#include <stdio.h>

#include "ccn/ccn.h"
#include "ccngen/ast.h"

node_st* NewDeclsArray[100];
int NewDeclsArrayCount = 0;

node_st* NewStmtsArray[100];
int NewStmtsArrayCount = 0;

node_st *OldGlobDef[100];
int OldGlobDefCount = 0;

node_st *FunVarDecls[100]; // This array  in a function
int FunVarDeclsCount = 0;

/**
 * @fn RSprogram
 * In the program node we need to add a new function called '__init'
 * This new function all the NewStmsArray nodes as its body
 * The new function will be the started decl of the program
 */
node_st *RSprogram(node_st *node)
{
    TRAVchildren(node);
    if(NewStmtsArrayCount > 0) {
        node_st *NewInitFunction = ASTdecls(
            ASTfundef(
                ASTfunbody(
                    NULL,
                    NewStmtsArray[0]
                ),
                NULL, // No params
                CT_void, // Return type
                "__init", // Name
                true // Export
            ),
            CCNcopy(PROGRAM_DECLS(node))
        );
        PROGRAM_DECLS(node) = CCNcopy(NewInitFunction);
        return node;
    }
    return node;
}

/**
 * @fn RSdecls
 */
node_st *RSdecls(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn RSglobdef
 * A global def is a 'types ID LET expr SEMICOLON'
 * This needs to be changed to a globdecl 'types ID SEMICOLON'
 * So we need to remove the LET expr part. This is done by
 * 1. Creating a Stmts node with the expr as its only child DONE
 * 2. Removing the expr from the globdef
 * 3. Saving the Stmts node in the GlobalDeclArray
 */
node_st *RSglobdef(node_st *node)
{
    if(GLOBDEF_INIT(node) != NULL) {
        // // Need to create a assign
        if(NewStmtsArrayCount == 0) {
            node_st *newAssign = ASTstmts(
                    ASTassign(
                        ASTvarlet(
                            GLOBDEF_NAME(node),
                            GLOBDEF_DECL(node)
                        ),
                        GLOBDEF_INIT(node)
                    ),
                    NULL
                );
            NewStmtsArray[NewStmtsArrayCount] = newAssign;
            NewStmtsArrayCount++;
        }
        else {
            node_st* temp = NewStmtsArray[0];
            int counter = 0;
            while (STMTS_NEXT(temp) != NULL) {
                temp = STMTS_NEXT(temp);
                counter++;
            }
            STMTS_NEXT(temp) = ASTstmts(
                    ASTassign(
                        ASTvarlet(
                            GLOBDEF_NAME(node),
                            GLOBDEF_DECL(node)
                        ),
                        GLOBDEF_INIT(node)
                    ),
                    NULL
                );
        }
        GLOBDEF_INIT(node) = NULL;
    }
    TRAVchildren(node);
    return node;
}

/**
 * @fn RSfunbody
 */
node_st *RSfunbody(node_st *node)
{
    // Clear the array
    for(int i = 0;i< 100; i++){
        FunVarDecls[i]=NULL;
    }
    FunVarDeclsCount = 0;
    TRAVchildren(node);
    // Now the FunVarDecls array contains all the vardecls
    if(FunVarDeclsCount > 0) {
        int counter = 0;
        node_st* temp = FunVarDecls[0];
        while (STMTS_NEXT(temp) != NULL) {
            temp = STMTS_NEXT(temp);
        }
        STMTS_NEXT(temp) = FUNBODY_STMTS(node);
        FUNBODY_STMTS(node) = CCNcopy(FunVarDecls[0]);
    }
    return node;
}

/**
 * @fn RSvardecl
 */
node_st *RSvardecl(node_st *node)
{
    if(VARDECL_INIT(node) != NULL) {
        node_st *newVarlet = ASTvarlet(VARDECL_NAME(node), VARDECL_DECL(node));
        VARLET_DECL(newVarlet) = VARDECL_DECL(node);
        node_st *newAssign = ASTstmts(
                ASTassign(
                    newVarlet, 
                    CCNcopy(VARDECL_INIT(node))
                ),
                NULL
            );
        
        if(FunVarDeclsCount == 0) {
            FunVarDecls[FunVarDeclsCount] = newAssign;
            FunVarDeclsCount++;
        }
        else {
            node_st* temp = FunVarDecls[0];
            int counter = 0;
            while (STMTS_NEXT(temp) != NULL) {
                temp = STMTS_NEXT(temp);
            }
            STMTS_NEXT(temp) = newAssign;
            FunVarDeclsCount++;
        }
        VARDECL_INIT(node) = NULL;
    }
    TRAVchildren(node);
    return node;
}
