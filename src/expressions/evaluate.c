
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scanner.h"
#include "utils.h"
#include "expressions.h"

void reset_value_fifo(expression_t e);
void perform_bitwise_operation(expression_t expr, expr_ops_t oper);
void perform_boolean_operation(expression_t expr, expr_ops_t oper);

/*!
 * This exists to allow the parser to store an expression in such a way as to
 * allow it to be evaluated multiple times without re-parsing it, such as the
 * case would be if a function were called multiple times.
 *
 * The parser already organizes the order of values for us. Instead of having
 * to use a different algorithm to convert the order of evaluation to something
 * like RPN, we can simply store items in the order we find them, i.e. in a
 * FIFO queue. As we evaluate the expression, we also use a stack (LIFO) to
 * keep track. See the data structures in expressions.h.
 *
 * while there are items in the FIFO get an item from the FIFO if it's not an
 * operator, then push it on to the LIFO. else if it's a unary operator, pop
 * one from the LIFO apply the operator push the result back on the LIFO else
 * if it's an operator and not unary pop two from the LIFO apply the operator
 * push the result back on the LIFO The value on top of the LIFO is the result
 * of the expression.
 *
 * These functions also evaluate the symantics of the expression. For example,
 * trying to use a float to calculate a bool or mixing signed and unsigned
 * types in an expression.
 *
 * The individual operations take on the type of the left operand. Most
 * demotions produce warnings, most promotions do not. Whether the actual value
 * fits into the actual size that has been specified, such as in an assignment,
 * is left to other code to determine. This code is concerned to evaluating
 * an expression that has already been parsed.
 *
 * Returns a pointer to the value of the expression. The type parameter
 * indicates the type that the return value points to.
 */
void evaluate_expression(expression_t expr) {
    MARK();
    expr_value_t value;
    expr_value_t ovalue;
    //int finished = 0;

    reset_value_fifo(expr);
    MSG("----- BEGIN EXPRESSION EVALUATION");
    //while(!finished) {
    while(get_expr_value(expr, &value)) {
        EXPR_PRINT_VALUE(&value);
        if(value.vtype == EXPR_VAL_OPERATOR) {
            // apply the operation to the out stack
            expr_ops_t oper = value.value.oper;

            switch (oper) {
                    // Arithmetic operations
                case EXPR_OP_ADD:
                    perform_arith_add(expr);
                    break;
                case EXPR_OP_SUB:
                    perform_arith_sub(expr);
                    break;
                case EXPR_OP_MUL:
                    perform_arith_mul(expr);
                    break;
                case EXPR_OP_DIV:
                    perform_arith_div(expr);
                    break;
                case EXPR_OP_MOD:
                    perform_arith_mod(expr);
                    break;

                    // Unary operations
                case EXPR_OP_UNARY_MINUS:
                    perform_unary_minus(expr);
                    break;
                case EXPR_OP_BIT_UNARY_NEG:
                    perform_unary_neg(expr);
                    break;
                case EXPR_OP_BOOL_UNARY_NOT:
                    perform_unary_not(expr);
                    break;

                    // Boolean operations
                case EXPR_OP_BOOL_AND:
                case EXPR_OP_BOOL_OR:
                case EXPR_OP_BOOL_EQ:
                case EXPR_OP_BOOL_NEQ:
                case EXPR_OP_BOOL_LE:
                case EXPR_OP_BOOL_GE:
                case EXPR_OP_BOOL_LT:
                case EXPR_OP_BOOL_GT:
                    perform_boolean_operation(expr, oper);
                    break;

                    // Bitwise operations
                case EXPR_OP_BIT_AND:
                case EXPR_OP_BIT_OR:
                case EXPR_OP_BIT_XOR:
                case EXPR_OP_BIT_SHL:
                case EXPR_OP_BIT_SHR:
                case EXPR_OP_BIT_ROL:
                case EXPR_OP_BIT_ROR:
                    perform_bitwise_operation(expr, oper);
                    break;

                default:
                    syntax("Unknown operator type in evaluate_expression().");
            }
        }
        else if(value.vtype == EXPR_VAL_REFERENCE) {
            // find the value of the reference and push it on the out stack
            syntax("References are not supported (yet)");
        }
        else {
            // push the value on the out stack
            switch (value.vtype) {
                case EXPR_VAL_UNUM:
                        ovalue.value.unum = value.value.unum;
                        ovalue.vtype = EXPR_VAL_UNUM;
                        push_output(expr, &ovalue);
                    break;
                case EXPR_VAL_INUM:
                        ovalue.value.inum = value.value.inum;
                        ovalue.vtype = EXPR_VAL_INUM;
                        push_output(expr, &ovalue);
                    break;
                case EXPR_VAL_FNUM:
                        ovalue.value.fnum = value.value.fnum;
                        ovalue.vtype = EXPR_VAL_FNUM;
                        push_output(expr, &ovalue);
                    break;
                case EXPR_VAL_BOOL:
                        ovalue.value.bval = value.value.bval;
                        ovalue.vtype = EXPR_VAL_BOOL;
                        push_output(expr, &ovalue);
                    break;
                default:
                    syntax("Unknown vtype in push_inter_value().");
            }
        }
    }
    MSG("----- FINISH EXPRESSION EVALUATION");
}
