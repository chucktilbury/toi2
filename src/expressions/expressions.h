#ifndef _EXPRESSIONS_H_
#define _EXPRESSIONS_H_

/*
    The context of the stack is the expected type that the
    expression will take when it is evaluated and returned.
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
    EXPR_OP_BOOL_NOT,
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

/*
    The value stack gets pushed when a operand of the expression is
    parsed.
*/
typedef struct val_fifo_element {
    expr_val_type_t vtype;
    union __attribute__((packed)) {
        unsigned long long unum;
        long long inum;
        double fnum;
        char *refernce;
        expr_ops_t operator;
    } value;
    struct val_fifo_element *next;
} val_fifo_element_t;

typedef struct val_fifo {
    val_fifo_element_t *first;
    val_fifo_element_t *last;
    val_fifo_element_t *crnt;
} val_fifo_t;

/*
    The intermediate stack is used when evaluating the expression. If the
    expression was well formed, then the this will be NULL when the evaluation
    finishes.
*/
typedef struct out_lifo {
    int type;
    union __attribute__((packed)) {
        unsigned long long unum;
        long long inum;
        double fnum;
    } value;
    struct out_lifo *next;
} out_lifo_t;

/*
    This data structure contains all of the elements required to evaluate the
    expression. This is the data structure that is stored in the abstract tree
    as parsing continues.
*/
typedef struct expression {
    expr_context_t context;
    val_fifo_t *item;
    out_lifo_t *out;
} expression_t;

expression_t *create_expression(void);
void destroy_expression(expression_t *expr);

void store_value(expression_t *expr, int type, void *value);
void *get_value(expression_t *expr, int *type);
void reset_value_fifo(expression_t *expr);

void push_inter(expression_t *expr, int type, void *value);
void *pop_inter(expression_t *expr, int *type);
void *peek_inter(expression_t *expr, int *type);

#endif /* _EXPRESSIONS_H_ */