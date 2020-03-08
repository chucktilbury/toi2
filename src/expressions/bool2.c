#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../parser/scanner.h"
#include "../utils/errors.h"
#include "bool2.h"

void perform_bool_le(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    unsigned char result;

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le <= right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le <= right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of signed integer and float");
                        result = (le <= right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and integer");
                        result = (le <= right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le <= right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le <= right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le <= right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le <= right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le <= right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed integer and float");
                        result = (le <= right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of two floats");
                        result = (le <= right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and float");
                        result = (le <= right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            {
                unsigned char le = left->value.bnum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le <= right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of boolean result and integer");
                        result = (le <= right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of boolean result and float");
                        result = (le <= right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        result = (le <= right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_BOOL, (void *)&result);
    free(right);
    free(left);
}

void perform_bool_ge(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    unsigned char result;

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le >= right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le >= right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of signed integer and float");
                        result = (le >= right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and integer");
                        result = (le >= right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le >= right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le >= right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le >= right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le >= right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le >= right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed integer and float");
                        result = (le >= right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of two floats");
                        result = (le >= right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and float");
                        result = (le >= right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            {
                unsigned char le = left->value.bnum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le >= right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of boolean result and integer");
                        result = (le >= right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of boolean result and float");
                        result = (le >= right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        result = (le >= right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_BOOL, (void *)&result);
    free(right);
    free(left);
}

void perform_bool_lt(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    unsigned char result;

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le < right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le < right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of signed integer and float");
                        result = (le < right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and integer");
                        result = (le < right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le < right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le < right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le < right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le < right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le < right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed integer and float");
                        result = (le < right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of two floats");
                        result = (le < right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and float");
                        result = (le < right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            {
                unsigned char le = left->value.bnum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le < right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of boolean result and integer");
                        result = (le < right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of boolean result and float");
                        result = (le < right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        result = (le < right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_BOOL, (void *)&result);
    free(right);
    free(left);
}

void perform_bool_gt(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    unsigned char result;

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le > right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le > right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of signed integer and float");
                        result = (le > right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and integer");
                        result = (le > right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le > right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le > right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le > right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le > right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le > right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed integer and float");
                        result = (le > right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of two floats");
                        result = (le > right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and float");
                        result = (le > right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            {
                unsigned char le = left->value.bnum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le > right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of boolean result and integer");
                        result = (le > right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of boolean result and float");
                        result = (le > right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        result = (le > right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_BOOL, (void *)&result);
    free(right);
    free(left);
}
