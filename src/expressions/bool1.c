#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scanner.h"
#include "utils.h"
#include "expressions.h"

void perform_bool_and(expression_t expr) {
    MARK();
    expr_value_t left;
    expr_value_t right;
    expr_value_t ovalue;
    unsigned char result;
    int error = 0;

    pop_output(expr, &left);
    pop_output(expr, &right);

    switch (left.vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left.value.inum;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = ((le != 0) && (right.value.unum != 0));
                        break;
                    case EXPR_VAL_INUM:
                        result = ((le != 0) && (right.value.inum != 0));
                        break;
                    case EXPR_VAL_FNUM:
                        syntax("integer \"and\" comparison to float is invalid");
                        error++;
                        break;
                    case EXPR_VAL_BOOL:
                        result = ((le != 0) && (right.value.bval != 0));
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                        error++;
                }
            }
            break;

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left.value.unum;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = ((le != 0) && (right.value.unum != 0));
                        break;
                    case EXPR_VAL_INUM:
                        result = ((le != 0) && (right.value.inum != 0));
                        break;
                    case EXPR_VAL_FNUM:
                        syntax("unsigned integer \"and\" comparison to float is invalid");
                        error++;
                        break;
                    case EXPR_VAL_BOOL:
                        result = ((le != 0) && (right.value.bval != 0));
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                        error++;
                }
            }
            break;

        case EXPR_VAL_FNUM:
            syntax("\"and\" comparison to float is invalid");
            break;

        case EXPR_VAL_BOOL:
            {
                unsigned char le = left.value.bval;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = ((le != 0) && (right.value.unum != 0));
                        break;
                    case EXPR_VAL_INUM:
                        result = ((le != 0) && (right.value.inum != 0));
                        break;
                    case EXPR_VAL_FNUM:
                        syntax("boolean \"and\" comparison to float is invalid");
                        error++;
                        break;
                    case EXPR_VAL_BOOL:
                        result = ((le != 0) && (right.value.bval != 0));
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                        error++;
                }
            }
            break;

        default:
            syntax("Unknown vtype left in perform_arithmetic().");
            error++;
    }
    if(!error) {
        ovalue.value.bval = result;
        ovalue.vtype = EXPR_VAL_BOOL;
        push_output(expr, &ovalue);
    }
}

void perform_bool_or(expression_t expr) {
    MARK();
    expr_value_t left;
    expr_value_t right;
    expr_value_t ovalue;
    unsigned char result;
    int error = 0;

    pop_output(expr, &left);
    pop_output(expr, &right);

    switch (left.vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left.value.inum;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = ((le != 0) || (right.value.unum != 0));
                        break;
                    case EXPR_VAL_INUM:
                        result = ((le != 0) || (right.value.inum != 0));
                        break;
                    case EXPR_VAL_FNUM:
                        syntax("integer \"or\" comparison to float is invalid");
                        error++;
                        break;
                    case EXPR_VAL_BOOL:
                        result = ((le != 0) || (right.value.bval != 0));
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                        error++;
                }
            }

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left.value.unum;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = ((le != 0) || (right.value.unum != 0));
                        break;
                    case EXPR_VAL_INUM:
                        result = ((le != 0) || (right.value.inum != 0));
                        break;
                    case EXPR_VAL_FNUM:
                        syntax("unsigned integer \"or\" comparison to float is invalid");
                        error++;
                        break;
                    case EXPR_VAL_BOOL:
                        result = ((le != 0) || (right.value.bval != 0));
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                        error++;
                }
            }
            break;

        case EXPR_VAL_FNUM:
            syntax("unsigned integer \"or\" comparison to float is invalid");
            error++;
            break;

        case EXPR_VAL_BOOL:
            {
                unsigned char le = left.value.bval;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = ((le != 0) || (right.value.unum != 0));
                        break;
                    case EXPR_VAL_INUM:
                        result = ((le != 0) || (right.value.inum != 0));
                        break;
                    case EXPR_VAL_FNUM:
                        syntax("boolean \"or\" comparison to float is invalid");
                        error++;
                        break;
                    case EXPR_VAL_BOOL:
                        result = ((le != 0) || (right.value.bval != 0));
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                        error++;
                }
            }

        default:
            syntax("Unknown vtype left in perform_arithmetic().");
            error++;
    }
    if(!error) {
        ovalue.value.bval = result;
        ovalue.vtype = EXPR_VAL_BOOL;
        push_output(expr, &ovalue);
    }
}

void perform_bool_eq(expression_t expr) {
    MARK();
    expr_value_t left;
    expr_value_t right;
    expr_value_t ovalue;
    unsigned char result;
    int error = 0;

    pop_output(expr, &left);
    pop_output(expr, &right);

    switch (left.vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left.value.inum;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le == right.value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le == right.value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of signed integer and float");
                        result = (le == right.value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and integer");
                        result = (le == right.value.bval);
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                }
            }

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left.value.unum;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le == right.value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le == right.value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le == right.value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le == right.value.bval);
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                        error++;
                }
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left.value.fnum;

                // right side is simply case to double
                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le == right.value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed integer and float");
                        result = (le == right.value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of two floats");
                        result = (le == right.value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and float");
                        result = (le == right.value.bval);
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                        error++;
                }
            }
            break;

        case EXPR_VAL_BOOL:
            {
                unsigned char le = left.value.bval;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le == right.value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of boolean result and integer");
                        result = (le == right.value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of boolean result and float");
                        result = (le == right.value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        result = (le == right.value.bval);
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                        error++;
                }
            }

        default:
            syntax("Unknown vtype left in perform_arithmetic().");
            error++;
    }
    if(!error) {
        ovalue.value.bval = result;
        ovalue.vtype = EXPR_VAL_BOOL;
        push_output(expr, &ovalue);
    }
}

void perform_bool_nqe(expression_t expr) {
    MARK();
    expr_value_t left;
    expr_value_t right;
    expr_value_t ovalue;
    unsigned char result;
    int error = 0;

    pop_output(expr, &left);
    pop_output(expr, &right);

    switch (left.vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left.value.inum;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le != right.value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le != right.value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of signed integer and float");
                        result = (le != right.value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and integer");
                        result = (le != right.value.bval);
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                        error++;
                }
            }

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left.value.unum;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le != right.value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le != right.value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le != right.value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le != right.value.bval);
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                        error++;
                }
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left.value.fnum;

                // right side is simply case to double
                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le != right.value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed integer and float");
                        result = (le != right.value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of two floats");
                        result = (le != right.value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and float");
                        result = (le != right.value.bval);
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                        error++;
                }
            }
            break;

        case EXPR_VAL_BOOL:
            {
                unsigned char le = left.value.bval;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le != right.value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of boolean result and integer");
                        result = (le != right.value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of boolean result and float");
                        result = (le != right.value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        result = (le != right.value.bval);
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                        error++;
                }
            }

        default:
            syntax("Unknown vtype left in perform_arithmetic().");
            error++;
    }
    if(!error) {
        ovalue.value.bval = result;
        ovalue.vtype = EXPR_VAL_BOOL;
        push_output(expr, &ovalue);
    }
}
