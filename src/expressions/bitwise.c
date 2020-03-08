#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../parser/scanner.h"
#include "../utils/errors.h"
#include "bitwise.h"

void perform_bitwise_and(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    uint64_t result;

    if(left->vtype == EXPR_VAL_FNUM || left->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    if(right->vtype == EXPR_VAL_FNUM || right->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                warning("bitwise operations on signed integer");
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le & right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le & right->value.inum);
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
                        result = (le & right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("bitwise operations on signed integer");
                        result = (le & right->value.inum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
    free(right);
    free(left);
}

void perform_bitwise_or(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    uint64_t result;

    if(left->vtype == EXPR_VAL_FNUM || left->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    if(right->vtype == EXPR_VAL_FNUM || right->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                warning("bitwise operations on signed integer");
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le | right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le | right->value.inum);
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
                        result = (le | right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("bitwise operations on signed integer");
                        result = (le | right->value.inum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
    free(right);
    free(left);
}

void perform_bitwise_xor(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    uint64_t result;

    if(left->vtype == EXPR_VAL_FNUM || left->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    if(right->vtype == EXPR_VAL_FNUM || right->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                warning("bitwise operations on signed integer");
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le ^ right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le ^ right->value.inum);
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
                        result = (le ^ right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("bitwise operations on signed integer");
                        result = (le ^ right->value.inum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
    free(right);
    free(left);
}

void perform_bitwise_shl(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    uint64_t result;

    if(left->vtype == EXPR_VAL_FNUM || left->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    if(right->vtype == EXPR_VAL_FNUM || right->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                warning("bitwise operations on signed integer");
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le << right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le << right->value.inum);
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
                        result = (le << right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("bitwise operations on signed integer");
                        result = (le << right->value.inum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
    free(right);
    free(left);
}

void perform_bitwise_shr(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    uint64_t result;

    if(left->vtype == EXPR_VAL_FNUM || left->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    if(right->vtype == EXPR_VAL_FNUM || right->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                warning("bitwise operations on signed integer");
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le >> right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le >> right->value.inum);
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
                        result = (le >> right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("bitwise operations on signed integer");
                        result = (le >> right->value.inum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
    free(right);
    free(left);
}

void perform_bitwise_rol(expression_t *expr) {
    MARK();
    fatal_error("Bitwise rotate is not supported (yet)");
}

void perform_bitwise_ror(expression_t *expr) {
    MARK();
    fatal_error("Bitwise rotate is not supported (yet)");
}
