#ifndef _EXPRESSIONS_H_
#  define _EXPRESSIONS_H_
#  include <stdint.h>
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
#    define EXPR_OP_MSG(v)      MSG("operation type: %s", \
                                ((v) == EXPR_OP_ADD)? "EXPR_OP_ADD" : \
                                ((v) == EXPR_OP_SUB)? "EXPR_OP_SUB" : \
                                ((v) == EXPR_OP_MUL)? "EXPR_OP_MUL" : \
                                ((v) == EXPR_OP_DIV)? "EXPR_OP_DIV" : \
                                ((v) == EXPR_OP_MOD)? "EXPR_OP_MOD" : \
                                ((v) == EXPR_OP_UNARY_MINUS)? "EXPR_OP_UNARY_MINUS" : \
                                ((v) == EXPR_OP_BOOL_AND)? "EXPR_OP_BOOL_AND" : \
                                ((v) == EXPR_OP_BOOL_OR)? "EXPR_OP_BOOL_OR" : \
                                ((v) == EXPR_OP_BOOL_UNARY_NOT)? "EXPR_OP_BOOL_UNARY_NOT" : \
                                ((v) == EXPR_OP_BOOL_EQ)? "EXPR_OP_BOOL_EQ" : \
                                ((v) == EXPR_OP_BOOL_NEQ)? "EXPR_OP_BOOL_NEQ" : \
                                ((v) == EXPR_OP_BOOL_LE)? "EXPR_OP_BOOL_LE" : \
                                ((v) == EXPR_OP_BOOL_GE)? "EXPR_OP_BOOL_GE" : \
                                ((v) == EXPR_OP_BOOL_LT)? "EXPR_OP_BOOL_LT" : \
                                ((v) == EXPR_OP_BOOL_GT)? "EXPR_OP_BOOL_GT" : \
                                ((v) == EXPR_OP_BIT_AND)? "EXPR_OP_BIT_AND" : \
                                ((v) == EXPR_OP_BIT_OR)? "EXPR_OP_BIT_AND" : \
                                ((v) == EXPR_OP_BIT_XOR)? "EXPR_OP_BIT_XOR" : \
                                ((v) == EXPR_OP_BIT_UNARY_NEG)? "EXPR_OP_BIT_UNARY_NEG" : \
                                ((v) == EXPR_OP_BIT_SHL)? "EXPR_OP_BIT_SHL" : \
                                ((v) == EXPR_OP_BIT_SHR)? "EXPR_OP_BIT_SHR" : \
                                ((v) == EXPR_OP_BIT_ROL)? "EXPR_OP_BIT_ROL" : \
                                ((v) == EXPR_OP_BIT_ROR)? "EXPR_OP_BIT_ROR" : \
                                "UNKNOWN")

#    define EXPR_VAL_MSG(v)     MSG("value type: %s", \
                                ((v) == EXPR_VAL_UNUM)? "EXPR_VAL_UNUM" : \
                                ((v) == EXPR_VAL_INUM)? "EXPR_VAL_INUM" : \
                                ((v) == EXPR_VAL_FNUM)? "EXPR_VAL_FNUM" : \
                                ((v) == EXPR_VAL_BOOL)? "EXPR_VAL_BOOL" : \
                                ((v) == EXPR_VAL_REFERENCE)? "EXPR_VAL_BOOL" : \
                                ((v) == EXPR_VAL_OPERATOR)? "EXPR_VAL_OPERATOR" : \
                                "UNKNOWN")

#    define EXPR_CONTEXT_MSG(v) MSG("context type: %s", \
                                ((v) == EXPR_CONTEXT_NONE)? "EXPR_CONTEXT_NONE" : \
                                ((v) == EXPR_CONTEXT_BOOL)? "EXPR_CONTEXT_BOOL" : \
                                ((v) == EXPR_CONTEXT_UNUM)? "EXPR_CONTEXT_UNUM" : \
                                ((v) == EXPR_CONTEXT_INUM)? "EXPR_CONTEXT_INUM" : \
                                ((v) == EXPR_CONTEXT_FNUM)? "EXPR_CONTEXT_FNUM" : \
                                "UNKNOWN")

#    define EXPR_PRINT_LIFO_VALUE(e) ((e)->vtype == EXPR_VAL_UNUM)? MSG("LIFO value type: EXPR_VAL_UNUM value stores: %lu", (e)->value.unum) : \
                                ((e)->vtype == EXPR_VAL_INUM)? MSG("LIFO value type: EXPR_VAL_INUM value stores: %ld", (e)->value.inum) : \
                                ((e)->vtype == EXPR_VAL_FNUM)? MSG("LIFO value type: EXPR_VAL_FNUM value stores: %f", (e)->value.fnum) : \
                                ((e)->vtype == EXPR_VAL_BOOL)? MSG("LIFO value type: EXPR_VAL_BOOL value stores: %u", (e)->value.bnum) : \
                                MSG("LIFO expr value type is unknown (%d)", (e)->vtype)

#    define EXPR_PRINT_FIFO_VALUE(e) ((e)->vtype == EXPR_VAL_UNUM)? MSG("FIFO value type: EXPR_VAL_UNUM value stores: %lu", (e)->value.unum) : \
                                ((e)->vtype == EXPR_VAL_INUM)? MSG("FIFO value type: EXPR_VAL_INUM value stores: %ld", (e)->value.inum) : \
                                ((e)->vtype == EXPR_VAL_FNUM)? MSG("FIFO value type: EXPR_VAL_FNUM value stores: %f", (e)->value.fnum) : \
                                ((e)->vtype == EXPR_VAL_BOOL)? MSG("FIFO value type: EXPR_VAL_BOOL value stores: %s", (e)->value.bnum? "TRUE" :"FALSE") : \
                                ((e)->vtype == EXPR_VAL_REFERENCE)? MSG("FIFO value type: EXPR_VAL_REFERENCE value stores: %s", (e)->value.ref) : \
                                ((e)->vtype == EXPR_VAL_OPERATOR)? MSG("FIFO value type: EXPR_VAL_OPERATOR value stores: %d", (e)->value.oper) : \
                                MSG("FIFO expr value type is unknown (%d)", (e)->vtype)

#  else
#    define EXPR_OP_MSG(v)
#    define EXPR_VAL_MSG(v)
#    define EXPR_CONTEXT_MSG(v)
#    define EXPR_PRINT_FIFO_VALUE(v)
#    define EXPR_PRINT_LIFO_VALUE(v)
#  endif

/*
 * The value stack gets pushed when a operand of the expression is parsed.
 */
typedef struct val_fifo_element {
    expr_val_type_t vtype;
    union __attribute__((packed)) {
        uint64_t unum;
        int64_t inum;
        double fnum;
        unsigned char bnum;
        char *ref;
        expr_ops_t oper;
    } value;
    struct val_fifo_element *next;
} val_fifo_element_t;

typedef struct val_fifo {
    val_fifo_element_t *first;
    val_fifo_element_t *last;
    val_fifo_element_t *crnt;
} val_fifo_t;

/*
 * The intermediate stack is used when evaluating the expression. If the expression was well formed, then the this will be NULL when the evaluation
 * finishes. Items must resolve to a number before being placed on this stack.
 */
typedef struct out_lifo {
    expr_val_type_t vtype;
    union __attribute__((packed)) {
        uint64_t unum;
        int64_t inum;
        double fnum;
        unsigned char bnum;
    } value;
    struct out_lifo *next;
} out_lifo_t;

/*
 * This data structure contains all of the elements required to evaluate the expression. This is the data structure that is stored in the abstract
 * tree as parsing continues.
 */
typedef struct expression {
    expr_context_t context;
    val_fifo_t *item;
    out_lifo_t *out;
} expression_t;

expression_t *create_expression(void);
void destroy_expression(expression_t *expr);

void store_expr_value(expression_t *expr, expr_val_type_t type, void *value);
val_fifo_element_t *get_expr_value(expression_t *expr);
void reset_value_fifo(expression_t *expr);

void push_inter(expression_t *expr, expr_val_type_t type, void *value);
out_lifo_t *pop_inter(expression_t *expr);
out_lifo_t *peek_inter(expression_t *expr);

#endif /* _EXPRESSIONS_H_ */
