#ifndef _ARITH_H_
#  define _ARITH_H_

#  include "expressions.h"

void perform_arith_add(expression_t *expr);
void perform_arith_sub(expression_t *expr);
void perform_arith_mul(expression_t *expr);
void perform_arith_div(expression_t *expr);
void perform_arith_mod(expression_t *expr);

#endif /* _ARITH_H_ */
