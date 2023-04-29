/**
 * @file
 *
 * Traversal: BoolJunction
 * UID      : BJ
 *
 * Authors: Ryan Brispat, Joshua Turpijn
 * Programme: Pre-Master Software Engineering
 * Date: 02 / 04 / 2023
 * 
 * This file should replaces booleans with ternary expressions.
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"

/**
 * @fn BJbinop
 */
node_st *BJbinop(node_st *node)
{
    TRAVchildren(node);
    if(BINOP_OP(node) == BO_or) {
        node_st* newNode = ASTconditionalexpression(BINOP_LEFT(node), ASTbool(true), BINOP_RIGHT(node));
        return newNode;
    }
    else if(BINOP_OP(node) == BO_and) {
        node_st* newNode = ASTconditionalexpression(BINOP_LEFT(node), BINOP_RIGHT(node), ASTbool(false));
        return newNode;
    }
    return node;
}

