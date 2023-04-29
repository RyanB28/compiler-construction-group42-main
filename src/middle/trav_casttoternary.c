/**
 * @file
 *
 * Traversal: CastToTernary
 * UID      : CTT
 *
 * Authors: Ryan Brispat, Joshua Turpijn
 * Programme: Pre-Master Software Engineering
 * Date: 02 / 04 / 2023
 * 
 * This file should replaces cast operators with ternary expressions.
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/enum.h"

/**
 * @fn CTTcast
 */
node_st *CTTcast(node_st *node)
{
    node_st *newNode = NULL;
    switch (CAST_TYPE(node))
    {
    case CT_int:
        if(CAST_INFERREDTYPE(node) == CT_bool) {
            return ASTconditionalexpression(CAST_EXPR(node), ASTnum(1), ASTnum(0));
            break;
        }
        break;
    case CT_float:
        if(CAST_INFERREDTYPE(node) == CT_bool) {
            return ASTconditionalexpression(CAST_EXPR(node), ASTfloat(1.0), ASTfloat(0.0));
            break;
        }
    case CT_bool:
        if(CAST_INFERREDTYPE(node) == CT_int) {
            node_st* binop = ASTbinop(CAST_EXPR(node), ASTnum(0), BO_ne);
            BINOP_INFERREDTYPE(binop) = CT_int;
            return ASTconditionalexpression(binop, ASTbool(true), ASTbool(false));
            break;
        }
        else { 
            node_st* binop = ASTbinop(CAST_EXPR(node), ASTfloat(0.0), BO_ne);
            BINOP_INFERREDTYPE(binop) = CT_float;
            return ASTconditionalexpression(binop, ASTbool(true), ASTbool(false));
            break;
        }
        break;
    default:
        break;
    }

    return node;
}

