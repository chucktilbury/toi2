#ifndef _EXPRESSIONS_H_
#define _EXPRESSIONS_H_

#  include <stdint.h>
#  include "utils.h"

/*
 * The context of the stack is the expected type that the expression will take when it is evaluated and returned.
 */
typedef enum {
    EXPR_CONTEXT_NONE,
    EXPR_CONTEXT_BOOL,
    EXPR_CONTEXT_UNUM,
    EXPR_CONTEXT_INUM,
    EXPR_CONTEXT_FNUM,
} expr_context_t;

typedef enum {
    EXPR_VAL_UNUM,
    EXPR_VAL_INUM,
    EXPR_VAL_FNUM,
    EXPR_VAL_BOOL,
    EXPR_VAL_REFERENCE,
    EXPR_VAL_OPERATOR,
} expr_val_type_t;

typedef enum {
    EXPR_OP_ADD,
    EXPR_OP_SUB,
    EXPR_OP_MUL,
    EXPR_OP_DIV,
    EXPR_OP_MOD,
    EXPR_OP_UNARY_MINUS,
    EXPR_OP_BOOL_AND,
    EXPR_OP_BOOL_OR,
    EXPR_OP_BOOL_UNARY_NOT,
    EXPR_OP_BOOL_EQ,
    EXPR_OP_BOOL_NEQ,
    EXPR_OP_BOOL_LE,
    EXPR_OP_BOOL_GE,
    EXPR_OP_BOOL_LT,
    EXPR_OP_BOOL_GT,
    EXPR_OP_BIT_AND,
    EXPR_OP_BIT_OR,
    EXPR_OP_BIT_XOR,
    EXPR_OP_BIT_UNARY_NEG,
    EXPR_OP_BIT_SHL,
    EXPR_OP_BIT_SHR,
    EXPR_OP_BIT_ROL,
    EXPR_OP_BIT_ROR,
} expr_ops_t;

#  ifdef TRACE
#    define EXPR_PRINT_VALUE(e) ((e)->vtype == EXPR_VAL_UNUM)? MSG("Value type: EXPR_VAL_UNUM value stores: %lu", (e)->value.unum) : \
                                ((e)->vtype == EXPR_VAL_INUM)? MSG("Value type: EXPR_VAL_INUM value stores: %ld", (e)->value.inum) : \
                                ((e)->vtype == EXPR_VAL_FNUM)? MSG("Value type: EXPR_VAL_FNUM value stores: %f", (e)->value.fnum) : \
                                ((e)->vtype == EXPR_VAL_BOOL)? MSG("Value type: EXPR_VAL_BOOL value stores: %s", (e)->value.bval? "TRUE" :"FALSE") : \
                                ((e)->vtype == EXPR_VAL_REFERENCE)? MSG("Value type: EXPR_VAL_REFERENCE value stores: %s", (e)->value.ref) : \
                                ((e)->vtype == EXPR_VAL_OPERATOR)? MSG("Value type: EXPR_VAL_OPERATOR value stores: %s", \
                                    ((e)->value.oper == EXPR_OP_ADD)? "EXPR_OP_ADD" : \
                                    ((e)->value.oper == EXPR_OP_SUB)? "EXPR_OP_SUB" : \
                                    ((e)->value.oper == EXPR_OP_MUL)? "EXPR_OP_MUL" : \
                                    ((e)->value.oper == EXPR_OP_DIV)? "EXPR_OP_DIV" : \
                                    ((e)->value.oper == EXPR_OP_MOD)? "EXPR_OP_MOD" : \
                                    ((e)->value.oper == EXPR_OP_UNARY_MINUS)? "EXPR_OP_UNARY_MINUS" : \
                                    ((e)->value.oper == EXPR_OP_BOOL_AND)? "EXPR_OP_BOOL_AND" : \
                                    ((e)->value.oper == EXPR_OP_BOOL_OR)? "EXPR_OP_BOOL_OR" : \
                                    ((e)->value.oper == EXPR_OP_BOOL_UNARY_NOT)? "EXPR_OP_BOOL_UNARY_NOT" : \
                                    ((e)->value.oper == EXPR_OP_BOOL_EQ)? "EXPR_OP_BOOL_EQ" : \
                                    ((e)->value.oper == EXPR_OP_BOOL_NEQ)? "EXPR_OP_BOOL_NEQ" : \
                                    ((e)->value.oper == EXPR_OP_BOOL_LE)? "EXPR_OP_BOOL_LE" : \
                                    ((e)->value.oper == EXPR_OP_BOOL_GE)? "EXPR_OP_BOOL_GE" : \
                                    ((e)->value.oper == EXPR_OP_BOOL_LT)? "EXPR_OP_BOOL_LT" : \
                                    ((e)->value.oper == EXPR_OP_BOOL_GT)? "EXPR_OP_BOOL_GT" : \
                                    ((e)->value.oper == EXPR_OP_BIT_AND)? "EXPR_OP_BIT_AND" : \
                                    ((e)->value.oper == EXPR_OP_BIT_OR)? "EXPR_OP_BIT_AND" : \
                                    ((e)->value.oper == EXPR_OP_BIT_XOR)? "EXPR_OP_BIT_XOR" : \
                                    ((e)->value.oper == EXPR_OP_BIT_UNARY_NEG)? "EXPR_OP_BIT_UNARY_NEG" : \
                                    ((e)->value.oper == EXPR_OP_BIT_SHL)? "EXPR_OP_BIT_SHL" : \
                                    ((e)->value.oper == EXPR_OP_BIT_SHR)? "EXPR_OP_BIT_SHR" : \
                                    ((e)->value.oper == EXPR_OP_BIT_ROL)? "EXPR_OP_BIT_ROL" : \
                                    ((e)->value.oper == EXPR_OP_BIT_ROR)? "EXPR_OP_BIT_ROR" : \
                                    "operator type unknown") :\
                                MSG("Expr value type is unknown (%d)", (e)->vtype)
#  else
#    define EXPR_PRINT_VALUE(v)
#  endif

typedef struct expr_value {
    expr_val_type_t vtype;
    union __attribute__((packed)) {
        uint64_t unum;
        int64_t inum;
        double fnum;
        expr_ops_t oper;
        char *ref;
        unsigned char bval;
    } value;
} expr_value_t;

typedef void *expression_t;

expression_t create_expression(void);
void destroy_expression(expression_t expr);

void store_expr_value(expression_t expr, expr_value_t *value);
int get_expr_value(expression_t expr, expr_value_t *value);
int reset_expr_input(expression_t expr, expr_value_t *value);

void push_output(expression_t expr, expr_value_t *value);
int pop_output(expression_t expr, expr_value_t *value);
int peek_output(expression_t expr, expr_value_t *value);

void perform_arith_add(expression_t expr);
void perform_arith_sub(expression_t expr);
void perform_arith_mul(expression_t expr);
void perform_arith_div(expression_t expr);
void perform_arith_mod(expression_t expr);

void perform_bitwise_and(expression_t expr);
void perform_bitwise_or(expression_t expr);
void perform_bitwise_xor(expression_t expr);
void perform_bitwise_shl(expression_t expr);
void perform_bitwise_shr(expression_t expr);
void perform_bitwise_rol(expression_t expr);
void perform_bitwise_ror(expression_t expr);

void perform_bool_and(expression_t expr);
void perform_bool_or(expression_t expr);
void perform_bool_eq(expression_t expr);
void perform_bool_nqe(expression_t expr);

void perform_bool_le(expression_t expr);
void perform_bool_ge(expression_t expr);
void perform_bool_lt(expression_t expr);
void perform_bool_gt(expression_t expr);

void perform_unary_minus(expression_t expr);
void perform_unary_neg(expression_t expr);
void perform_unary_not(expression_t expr);

void *evaluate_expression(expression_t *expr, expr_val_type_t * type);

#endif /* _EXPRESSIONS_H_ */