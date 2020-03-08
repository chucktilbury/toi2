#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../parser/scanner.h"
#include "../utils/errors.h"
#include "arith.h"

void perform_arith_add(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);

    switch (left->vtype) {
        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;
                uint64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = le + right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        // integer becomes unsigned
                        warning("converting integer to unsigned value");
                        result = le + (uint64_t) right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to unsigned
                        warning("truncate a float to unsigned value");
                        result = le + (uint64_t) right->value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le + (uint64_t) right->value.bnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;
                int64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        // unsigned is sign extended to integer
                        warning("converting unsigned value to sign extended integer");
                        result = le + (int64_t) right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le + right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to integer
                        warning("truncate a float to unsigned value");
                        result = le + (int64_t) right->value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le + (int64_t) right->value.bnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_INUM, (void *)&result);
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;
                double result;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = le + (double)right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le + (double)right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        result = le + right->value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le + (double)right->value.bnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            fatal_error("addition on boolean result is invalid");
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    free(right);
    free(left);
}

void perform_arith_sub(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);

    switch (left->vtype) {
        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;
                uint64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = le - right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        // integer becomes unsigned
                        warning("converting integer to unsigned value");
                        result = le - (uint64_t) right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to unsigned
                        warning("truncate a float to unsigned value");
                        result = le - (uint64_t) right->value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le - (uint64_t) right->value.bnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;
                int64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        // unsigned is sign extended to integer
                        warning("converting unsigned value to sign extended integer");
                        result = le - (int64_t) right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le - right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to integer
                        warning("truncate a float to unsigned value");
                        result = le - (int64_t) right->value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le - (int64_t) right->value.bnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_INUM, (void *)&result);
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;
                double result;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = le - (double)right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le - (double)right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        result = le - right->value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le - (double)right->value.bnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            fatal_error("subtraction on boolean result is invalid");
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    free(right);
    free(left);
}

void perform_arith_mul(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);

    switch (left->vtype) {
        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;
                uint64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = le * right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        // integer becomes unsigned
                        warning("converting integer to unsigned value");
                        result = le * (uint64_t) right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to unsigned
                        warning("truncate a float to unsigned value");
                        result = le * (uint64_t) right->value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le * (uint64_t) right->value.bnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;
                int64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        // unsigned is sign extended to integer
                        warning("converting unsigned value to sign extended integer");
                        result = le * (int64_t) right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le * right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to integer
                        warning("truncate a float to unsigned value");
                        result = le * (int64_t) right->value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le * (int64_t) right->value.bnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_INUM, (void *)&result);
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;
                double result;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = le * (double)right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le * (double)right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        result = le * right->value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le * (double)right->value.bnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            fatal_error("multiplication on boolean result is invalid");
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    free(right);
    free(left);
}

void perform_arith_div(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);

    // check for divide by zero
    switch (right->vtype) {
        case EXPR_VAL_UNUM:
            if(right->value.unum == 0)
                fatal_error("Attempt to divide by zero detected.");
            break;
        case EXPR_VAL_INUM:
            if(right->value.inum == 0)
                fatal_error("Attempt to divide by zero detected.");
            break;
        case EXPR_VAL_FNUM:
            if(right->value.fnum == 0.0)
                fatal_error("Attempt to divide by zero detected.");
            break;
        case EXPR_VAL_BOOL:
            fatal_error("using boolean result in division operation is illegal");
            break;
        default:
            fatal_error("Unknown vtype right in perform_arithmetic().");
    }

    switch (left->vtype) {
        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;
                uint64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = le / right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        // integer becomes unsigned
                        warning("converting integer to unsigned value");
                        result = le / (uint64_t) right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to unsigned
                        warning("truncate a float to unsigned value");
                        result = le / (uint64_t) right->value.fnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;
                int64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        // unsigned is sign extended to integer
                        warning("converting unsigned value to sign extended integer");
                        result = le / (int64_t) right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le / right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to integer
                        warning("truncate a float to unsigned value");
                        result = le / (int64_t) right->value.fnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_INUM, (void *)&result);
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;
                double result;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = le / (double)right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le / (double)right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        result = le / right->value.fnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            fatal_error("using boolean result in division operation is illegal");
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    free(right);
    free(left);
}

void perform_arith_mod(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);

    // check for divide by zero
    switch (right->vtype) {
        case EXPR_VAL_UNUM:
            if(right->value.unum == 0)
                fatal_error("Attempt to modulo divide by zero detected.");
            break;
        case EXPR_VAL_INUM:
            if(right->value.inum == 0)
                fatal_error("Attempt to modulo divide by zero detected.");
            break;
        case EXPR_VAL_FNUM:
            fatal_error("Modulo operatons only allowed on integer and unsigned.");
            break;
        case EXPR_VAL_BOOL:
            fatal_error("modulo operations not allowed on a boolean result");
            break;
        default:
            fatal_error("Unknown vtype right in perform_arithmetic().");
    }

    switch (left->vtype) {
        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;
                uint64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = le % right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        // integer becomes unsigned
                        warning("converting integer to unsigned value");
                        result = le % (uint64_t) right->value.inum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;
                int64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        // unsigned is sign extended to integer
                        warning("converting unsigned value to sign extended integer");
                        result = le / (int64_t) right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le / right->value.inum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_INUM, (void *)&result);
            }
            break;

        case EXPR_VAL_FNUM:
            fatal_error("Modulo operatons only allowed on integer and unsigned.");
            break;

        case EXPR_VAL_BOOL:
            fatal_error("Modulo operatons not allowed on boolean result.");
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    free(right);
    free(left);
}
