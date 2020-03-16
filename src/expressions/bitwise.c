#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scanner.h"
#include "utils.h"
#include "expressions.h"

void perform_bitwise_and(expression_t expr) {
    MARK();
    expr_value_t left;
    expr_value_t right;
    expr_value_t ovalue;
    uint64_t result;
    int error = 0;

    pop_output(expr, &left);
    pop_output(expr, &right);

    if(left.vtype == EXPR_VAL_FNUM || left.vtype == EXPR_VAL_BOOL) {
        syntax("cannot perform bitwise operations of float or boolean");
        error++;
    }

    if(right.vtype == EXPR_VAL_FNUM || right.vtype == EXPR_VAL_BOOL) {
        syntax("cannot perform bitwise operations of float or boolean");
        error++;
    }

    switch (left.vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left.value.inum;

                warning("bitwise operations on signed integer");
                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le & right.value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le & right.value.inum);
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
                        result = (le & right.value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("bitwise operations on signed integer");
                        result = (le & right.value.inum);
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
        ovalue.value.unum = result;
        ovalue.vtype = EXPR_VAL_UNUM;
        push_output(expr, &ovalue);
    }
}

void perform_bitwise_or(expression_t expr) {
    MARK();
    expr_value_t left;
    expr_value_t right;
    expr_value_t ovalue;
    uint64_t result;
    int error = 0;

    pop_output(expr, &left);
    pop_output(expr, &right);

    if(left.vtype == EXPR_VAL_FNUM || left.vtype == EXPR_VAL_BOOL) {
        syntax("cannot perform bitwise operations of float or boolean");
        error++;
    }

    if(right.vtype == EXPR_VAL_FNUM || right.vtype == EXPR_VAL_BOOL) {
        syntax("cannot perform bitwise operations of float or boolean");
        error++;
    }

    switch (left.vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left.value.inum;

                warning("bitwise operations on signed integer");
                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le | right.value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le | right.value.inum);
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
                        result = (le | right.value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("bitwise operations on signed integer");
                        result = (le | right.value.inum);
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
        ovalue.value.unum = result;
        ovalue.vtype = EXPR_VAL_UNUM;
        push_output(expr, &ovalue);
    }
}

void perform_bitwise_xor(expression_t expr) {
    MARK();
    expr_value_t left;
    expr_value_t right;
    expr_value_t ovalue;
    uint64_t result;
    int error = 0;

    pop_output(expr, &left);
    pop_output(expr, &right);

    if(left.vtype == EXPR_VAL_FNUM || left.vtype == EXPR_VAL_BOOL) {
        syntax("cannot perform bitwise operations of float or boolean");
        error++;
    }

    if(right.vtype == EXPR_VAL_FNUM || right.vtype == EXPR_VAL_BOOL) {
        syntax("cannot perform bitwise operations of float or boolean");
        error++;
    }

    switch (left.vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left.value.inum;

                warning("bitwise operations on signed integer");
                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le ^ right.value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le ^ right.value.inum);
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
                        result = (le ^ right.value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("bitwise operations on signed integer");
                        result = (le ^ right.value.inum);
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
        ovalue.value.unum = result;
        ovalue.vtype = EXPR_VAL_UNUM;
        push_output(expr, &ovalue);
    }
}

void perform_bitwise_shl(expression_t expr) {
    MARK();
    expr_value_t left;
    expr_value_t right;
    expr_value_t ovalue;
    uint64_t result;
    int error = 0;

    pop_output(expr, &left);
    pop_output(expr, &right);

    if(left.vtype == EXPR_VAL_FNUM || left.vtype == EXPR_VAL_BOOL) {
        syntax("cannot perform bitwise operations of float or boolean");
        error++;
    }

    if(right.vtype == EXPR_VAL_FNUM || right.vtype == EXPR_VAL_BOOL) {
        syntax("cannot perform bitwise operations of float or boolean");
        error++;
    }

    switch (left.vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left.value.inum;

                warning("bitwise operations on signed integer");
                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le << right.value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le << right.value.inum);
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
                        result = (le << right.value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("bitwise operations on signed integer");
                        result = (le << right.value.inum);
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
        ovalue.value.unum = result;
        ovalue.vtype = EXPR_VAL_UNUM;
        push_output(expr, &ovalue);
    }
}

void perform_bitwise_shr(expression_t expr) {
    MARK();
    expr_value_t left;
    expr_value_t right;
    expr_value_t ovalue;
    uint64_t result;
    int error = 0;

    pop_output(expr, &left);
    pop_output(expr, &right);

    if(left.vtype == EXPR_VAL_FNUM || left.vtype == EXPR_VAL_BOOL) {
        syntax("cannot perform bitwise operations of float or boolean");
        error++;
    }

    if(right.vtype == EXPR_VAL_FNUM || right.vtype == EXPR_VAL_BOOL) {
        syntax("cannot perform bitwise operations of float or boolean");
        error++;
    }

    switch (left.vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left.value.inum;

                warning("bitwise operations on signed integer");
                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le >> right.value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le >> right.value.inum);
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
                        result = (le >> right.value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("bitwise operations on signed integer");
                        result = (le >> right.value.inum);
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
        ovalue.value.unum = result;
        ovalue.vtype = EXPR_VAL_UNUM;
        push_output(expr, &ovalue);
    }
}

void perform_bitwise_rol(expression_t expr) {
    MARK();
    syntax("Bitwise rotate is not supported (yet)");
}

void perform_bitwise_ror(expression_t expr) {
    MARK();
    syntax("Bitwise rotate is not supported (yet)");
}
