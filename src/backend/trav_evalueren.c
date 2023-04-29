/**
 * @file
 *
 * Traversal: evalueren
 * UID      : CG
 *
 *
 */

#include <stddef.h>
#include "ccn/ccn.h"
#include "ccngen/trav.h"
#include "ccngen/ast.h"
#include "ccngen/enum.h"
#include "global/globals.h"

#include <stdio.h>
#include <stdarg.h>

void printLine(FILE *file, const char* command, ...) {
    va_list args;
    va_start(args, command);
    vfprintf(file, command, args);
    va_end(args);
    fprintf(file, "\n");
}

int branchIndex = 1;
int whileIndex = 1;
int ifelseIndex = 1;
int dowhileIndex = 1;

node_st* cgieRootNode;
node_st* cggRootNode;

FILE *output_file;

int GetGlobalIndex(char name[]) {
    node_st* temp = cggRootNode;
    while(temp != NULL) {
        if(strcmp(CGG_NAME(temp), name) == 0) {
            return CGG_ID(temp);
        }
        temp = CGG_NEXT(temp);
    }
    return -1;
}

/**
 * @fn CGprogram
 */
node_st *CGprogram(node_st *node)
{
    cgieRootNode = PROGRAM_CG_IMPORT_TABLE(node);
    cggRootNode = PROGRAM_CG_GLOBAL_TABLE(node);
    // output_file = fopen("tmp.s", "w");
    output_file = global.output_file;
    if (global.output_file == NULL) {
        output_file = stdout;
    } else {
        output_file = fopen(global.output_file, "w");
    }

    if(output_file == NULL) {
        printf("Failed to open inputfile.");
    }

    TRAVchildren(node);
    printLine(output_file, "");
    
    node_st* temp = PROGRAM_CG_CONST_TABLE(node);
    while(temp!= NULL) {
        // printf("CONST TABLE %d %d %d %d %.2f\n", CGC_INDEX(temp), CGC_TYPE(temp), CGC_VALUEI(temp), CGC_VALUEB(temp), CGC_VALUEF(temp));
        switch (CGC_TYPE(temp))
        {
        case CT_int:
            printLine(output_file, ".const int %d", CGC_VALUEI(temp));
            break;
        case CT_bool:
            printLine(output_file, ".const bool %s", CGC_VALUEB(temp) ? "true" : "false");
            break;
        case CT_float:
            printLine(output_file, ".const float %f", CGC_VALUEF(temp));
            break;
        default:
            printLine(output_file, "ABORT ERROR.");
        }
        temp = CGC_NEXT(temp);
    }

    // print Global table
    printLine(output_file, "");
    temp = PROGRAM_CG_GLOBAL_TABLE(node);
    while(temp!= NULL) {
        switch (CGG_TYPE(temp))
        {
        case CT_int:
            printLine(output_file, ".global int ");
            break;
        case CT_bool:
            printLine(output_file, ".global bool");
            break;
        case CT_float:
            printLine(output_file, ".global float");
            break;
        default:
            printLine(output_file, "ABORT ERROR.");
        }
        temp = CGG_NEXT(temp);
    }

    // print export table
    // printLine(output_file, "");
    temp = PROGRAM_CG_EXPORT_TABLE(node);
    while(temp!= NULL) {
        
        char params[1000] = "";
        node_st* temp2 = CGEE_PARAMS(temp);
        while (temp2 != NULL)
        {
            switch (PARAM_TYPE(temp2))
            {
                case CT_int:
                    strcat(params, "int ");
                    break;
                case CT_bool:
                    strcat(params, "bool ");
                    break;
                case CT_float:
                    strcat(params, "float ");
                    break;
            }
            temp2 = PARAM_NEXT(temp2);
        }
        
        switch (CGEE_TYPE(temp))
        {
        case CT_int:
            printLine(output_file, ".exportfun \"%s\" int %s %s", CGEE_FUNNAME(temp), params, CGEE_LABELNAME(temp));
            break;
        case CT_bool:
            printLine(output_file, ".exportfun \"%s\" bool %s %s", CGEE_FUNNAME(temp), params, CGEE_LABELNAME(temp));
            break;
        case CT_float:
            printLine(output_file, ".exportfun \"%s\" float %s %s", CGEE_FUNNAME(temp), params, CGEE_LABELNAME(temp));
            break;
        case CT_void:
            printLine(output_file, ".exportfun \"%s\" void %s %s", CGEE_FUNNAME(temp), params, CGEE_LABELNAME(temp));
        }
        temp = CGEE_NEXT(temp);
    }

    temp = PROGRAM_CG_IMPORT_TABLE(node);
    while(temp != NULL) {
        char params[1000] = "";
        node_st* temp2 = CGIE_PARAMS(temp);
        while (temp2 != NULL)
        {
            switch (PARAM_TYPE(temp2))
            {
                case CT_int:
                    strcat(params, "int ");
                    break;
                case CT_bool:
                    strcat(params, "bool ");
                    break;
                case CT_float:
                    strcat(params, "float ");
                    break;
            }
            temp2 = PARAM_NEXT(temp2);
        }

        switch (CGIE_TYPE(temp))
        {
        case CT_int:
            printLine(output_file, ".importfun \"%s\" int %s", CGIE_FUNNAME(temp), params);
            break;
        case CT_bool:
            printLine(output_file, ".importfun \"%s\" bool %s", CGIE_FUNNAME(temp), params);
            break;
        case CT_float:
            printLine(output_file, ".importfun \"%s\" float %s", CGIE_FUNNAME(temp), params);
            break;
        case CT_void:
            printLine(output_file, ".importfun \"%s\" void %s", CGIE_FUNNAME(temp), params);
        }
        temp = CGIE_NEXT(temp);
    }

    fclose(output_file);
    return node;
}

/**
 * @fn CGnum
 */
node_st *CGnum(node_st *node)
{
    printLine(output_file, "iloadc %d", NUM_CONSTID(node));
    return node;
}

/**
 * @fn CGfloat
 */
node_st *CGfloat(node_st *node)
{
    printLine(output_file, "floadc %d", FLOAT_CONSTID(node));
    return node;
}

/**
 * @fn CGbool
 */
node_st *CGbool(node_st *node)
{
    printLine(output_file, "bloadc %d", BOOL_CONSTID(node));
    return node;
}

/**
 * @fn CGbinop
 */
node_st *CGbinop(node_st *node)
{
    TRAVleft(node); // We first get the first item from the stack.
    TRAVright(node); // We first get the second item from the stack.
    switch (BINOP_OP(node))
    {
        //Arithmetics
        case BO_add:
            if(BINOP_INFERREDTYPE(node) == CT_int) {
                printLine(output_file, "iadd");
            }
            if(BINOP_INFERREDTYPE(node) == CT_float) {
                printLine(output_file, "fadd");
            }
            if(BINOP_INFERREDTYPE(node) == CT_bool) {
                printLine(output_file, "badd");
            }
            break;
        case BO_sub:
            if(BINOP_INFERREDTYPE(node) == CT_int) {
                printLine(output_file, "isub");
            }
            if(BINOP_INFERREDTYPE(node) == CT_float) {
                printLine(output_file, "fsub");
            }
            break;
        case BO_mul:
            if(BINOP_INFERREDTYPE(node) == CT_int) {
                printLine(output_file, "imul");
            }
            if(BINOP_INFERREDTYPE(node) == CT_float) {
                printLine(output_file, "fmul");
            }
            if(BINOP_INFERREDTYPE(node) == CT_bool) {
                printLine(output_file, "bmul");
            }
            break;
        case BO_div:
            if(BINOP_INFERREDTYPE(node) == CT_int) {
                printLine(output_file, "idiv");
            }
            if(BINOP_INFERREDTYPE(node) == CT_float) {
                printLine(output_file, "fdiv");
            }
            break;
        case BO_mod:
            if(BINOP_INFERREDTYPE(node) == CT_int) {
                printLine(output_file, "irem");
            }
            break;
        // Comparisons
        case BO_lt:
            if(BINOP_INFERREDTYPE(node) == CT_int) {
                printLine(output_file, "ilt");
            }
            if(BINOP_INFERREDTYPE(node) == CT_float) {
                printLine(output_file, "flt");
            }
            break;
        case BO_gt:
            if(BINOP_INFERREDTYPE(node) == CT_int) {
                printLine(output_file, "igt");
            }
            if(BINOP_INFERREDTYPE(node) == CT_float) {
                printLine(output_file, "fgt");
            }
            break;
        case BO_le:
            if(BINOP_INFERREDTYPE(node) == CT_int) {
                printLine(output_file, "ile");
            }
            if(BINOP_INFERREDTYPE(node) == CT_float) {
                printLine(output_file, "fle");
            }
            break;
        case BO_ge:
            if(BINOP_INFERREDTYPE(node) == CT_int) {
                printLine(output_file, "ige");
            }
            if(BINOP_INFERREDTYPE(node) == CT_float) {
                printLine(output_file, "fge");
            }
            break;
        case BO_eq:
            if(BINOP_INFERREDTYPE(node) == CT_int) {
                printLine(output_file, "ieq");
            }
            if(BINOP_INFERREDTYPE(node) == CT_float) {
                printLine(output_file, "feq");
            }
            if(BINOP_INFERREDTYPE(node) == CT_bool) {
                printLine(output_file, "beq");
            }
            break;
        case BO_ne:
            if(BINOP_INFERREDTYPE(node) == CT_int) {
                printLine(output_file, "ine");
            }
            if(BINOP_INFERREDTYPE(node) == CT_float) {
                printLine(output_file, "fne");
            }
            if(BINOP_INFERREDTYPE(node) == CT_bool) {
                printLine(output_file, "bne");
            }
            break;
        default:
            break;
    }
    return node;
}


// node conditionalexpression {
//     children {
//         Expr predexpr { constructor, mandatory },
//         Expr trueexpr { constructor, mandatory },
//         Expr elseexpr { constructor, mandatory }
//     },
//     attributes {
//         Types inferredtype
//     }
// };
/**
 * @fn CGconditionalexpression
 */
node_st *CGconditionalexpression(node_st *node)
{
    int fIndex = branchIndex++;
    int endIndex = branchIndex++;

    TRAVpredexpr(node);
    printLine(output_file, "branch_f %d_false_expr", fIndex);
    TRAVtrueexpr(node);
    printLine(output_file, "jump %d_endce", endIndex);
    printLine(output_file, "%d_false_expr:", fIndex);
    TRAVelseexpr(node);
    printLine(output_file, "%d_endce:", endIndex);
    
    return node;
}

/**
 * @fn CGdowhile
 */
node_st *CGdowhile(node_st *node)
{
    int fIndex = dowhileIndex++;
    int endIndex = dowhileIndex++;

    printLine(output_file, "%d_dowhile:", fIndex);
    TRAVblock(node);
    TRAVcond(node);
    printLine(output_file, "branch_t %d_dowhile", fIndex);
    return node;
}

/**
 * @fn CGmonop
 */
node_st *CGmonop(node_st *node)
{
    TRAVchildren(node);
    if(MONOP_OP(node) == MO_neg && MONOP_INFERREDTYPE(node) == CT_int) {
        printLine(output_file, "ineg");
    }
    if(MONOP_OP(node) == MO_neg && MONOP_INFERREDTYPE(node) == CT_float) {
        printLine(output_file, "fneg");
    }
    if(MONOP_OP(node) == MO_not) {
        printLine(output_file, "bnot");
    }

    return node;
}

/**
 * @fn CGfundef
 */
node_st *CGfundef(node_st *node)
{
    if(FUNDEF_BODY(node) == NULL) {
        return node;
    }
    printLine(output_file, "%s:", FUNDEF_NAME(node));
    int VarDeclCounter = 0;
    node_st* tempnode = FUNBODY_DECLS(FUNDEF_BODY(node));
    
    while(tempnode != NULL) {
        VarDeclCounter++;
        tempnode = VARDECL_NEXT(tempnode);
    }

    if(VarDeclCounter > 0){
        printLine(output_file, "esr %d", VarDeclCounter);
    }

    TRAVbody(node);
    printLine(output_file, "return"); // TODO CHECK IF THIS MATTERS: CHECK IF THE LAST ITEM ON STACK IS RETURN
    return node;
}

/**
 * @fn CGfuncall
 */
node_st *CGfuncall(node_st *node)
{
    printLine(output_file, "isrg");
    node_st* tempnode = cgieRootNode;
    while(tempnode != NULL) {
        if(strcmp(FUNCALL_NAME(node), CGIE_FUNNAME(tempnode)) == 0) {
            TRAVargs(node);
            printLine(output_file, "jsre %d", CGIE_INDEX(tempnode));
            return node; 
        }
        tempnode = CGIE_NEXT(tempnode);
    }
    
    // TRAV PARAMS
    TRAVargs(node);
    // Count variables
    int count = 0;
    tempnode = FUNCALL_ARGS(node);
    while (tempnode != NULL){
        count++;
        tempnode = EXPRS_NEXT(tempnode);
    }
    printLine(output_file, "jsr %d %s", count, FUNCALL_NAME(node));
    return node;
}

/**
 * @fn CGifelse
 */
node_st *CGifelse(node_st *node)
{
    int fIndex = ifelseIndex++;
    int endIndex = ifelseIndex++;

    TRAVcond(node);

    if(IFELSE_ELSE_BLOCK(node) == NULL) {
        printLine(output_file, "branch_f %d_endie", fIndex);
        TRAVthen(node);
        printLine(output_file, "%d_endie:", fIndex);
        return node;
    }

    printLine(output_file, "branch_f %d_else", fIndex);
    TRAVthen(node);
    printLine(output_file, "jump %d_endie", endIndex);
    printLine(output_file, "%d_else:", fIndex);
    TRAVelse_block(node);
    printLine(output_file, "%d_endie:", endIndex);
    
    return node;
}

/**
 * @fn CGvar
 */
node_st *CGvar(node_st *node)
{
    int varIndex = STE_ID(VAR_DECL(node));
    if(STE_SCOPE(VAR_DECL(node)) == 0) {
        varIndex = GetGlobalIndex(VAR_NAME(node));
        switch (STE_TYPE(VAR_DECL(node)))
        {
            case CT_int:
                printLine(output_file, "iloadg %d", varIndex);
                break;
            case CT_float:
                printLine(output_file, "floadg %d", varIndex);
                break;
            case CT_bool:
                printLine(output_file, "bloadg %d", varIndex);
                break;
            default:
                break;
        }
        return node;
    }
    if(varIndex == 0) {
    }
    else if (varIndex == 0x0) {
        return node;
    }
    switch (STE_TYPE(VAR_DECL(node)))
    {
    case CT_int:
        printLine(output_file, "iload %d", varIndex);
        break;
    case CT_float:
        printLine(output_file, "fload %d", varIndex);
        break;
    case CT_bool:
        printLine(output_file, "bload %d", varIndex);
        break;
    default:
        break;
    }
    return node;
}

/**
 * @fn CGreturn
 */
node_st *CGreturn(node_st *node)
{
    TRAVchildren(node);
    if(RETURN_TYPE(node) == CT_int) {
        printLine(output_file, "ireturn");
    }
    if(RETURN_TYPE(node) == CT_float) {
        printLine(output_file, "freturn");
    }
    if(RETURN_TYPE(node) == CT_bool) {
        printLine(output_file, "breturn");
    }
    if(RETURN_TYPE(node) == CT_void) {
        printLine(output_file, "return");
    }
    return node;
}

/**
 * @fn CGvarlet
 */
node_st *CGvarlet(node_st *node)
{
    int varIndex = STE_ID(VARLET_DECL(node));
    if(STE_SCOPE(VARLET_DECL(node)) == 0) {
        varIndex = GetGlobalIndex(VARLET_NAME(node));
        switch (STE_TYPE(VARLET_DECL(node)))
        {
            case CT_int:
                printLine(output_file, "iloadg %d", varIndex);
                break;
            case CT_float:
                printLine(output_file, "floadg %d", varIndex);
                break;
            case CT_bool:
                printLine(output_file, "bloadg %d", varIndex);
                break;
            default:
                break;
        }
        return node;
    }
    switch (STE_TYPE(VARLET_DECL(node)))
    {
    case CT_int:
        printLine(output_file, "iload %d", varIndex);
        break;
    case CT_float:
        printLine(output_file, "fload %d", varIndex);
        break;
    case CT_bool:
        printLine(output_file, "bload %d", varIndex);
        break;
    default:
        break;
    }
    return node;
}

/**
 * @fn CGwhile
 */
node_st *CGwhile(node_st *node)
{
    int fIndex = whileIndex++;
    int endIndex = whileIndex++;

    printLine(output_file, "%d_while:", fIndex);
    TRAVcond(node);
    printLine(output_file, "branch_f %d_endwh", endIndex);
    TRAVblock(node);
    printLine(output_file, "jump %d_while", fIndex);
    printLine(output_file, "%d_endwh:", endIndex);
    return node;
}

/**
 * @fn CGassign
 */
node_st *CGassign(node_st *node)
{
    TRAVexpr(node);
    node_st* steNode = VARLET_DECL(ASSIGN_LET(node));
    int index = STE_ID(steNode);
    if(STE_SCOPE(steNode) == 0) {
        index = GetGlobalIndex(VARLET_NAME(ASSIGN_LET(node)));
        switch (STE_TYPE(steNode))
        {
        case CT_int:
            printLine(output_file, "istoreg %d", index);
            break;
        case CT_float:
            printLine(output_file, "fstoreg %d", index);
            break;
        case CT_bool:
            printLine(output_file, "bstoreg %d", index);
            break;
        }
        return node;
        
    }
    switch (STE_TYPE(steNode))
    {
    case CT_int:
        printLine(output_file, "istore %d", index);
        break;
    case CT_float:
        printLine(output_file, "fstore %d", index);
        break;
    case CT_bool:
        printLine(output_file, "bstore %d", index);
        break;
    }
    return node;
}

/**
 * @fn CGcast
 */
node_st *CGcast(node_st *node)
{
    TRAVexpr(node);
    switch (CAST_TYPE(node)) 
    {
    case CT_int:
        printLine(output_file, "f2i");
        break;
    case CT_float:
        printLine(output_file, "i2f");
        break;
    default:
        printf("SOMETHING WENT HORRIBLY WRONG IN CAST");
        break;
    }
    return node;
}
