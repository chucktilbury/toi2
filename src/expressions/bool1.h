#ifndef _BOOL1_H_
#  define _BOOL1_H_

#  include "expressions.h"
void perform_bool_and(expression_t *expr);
void perform_bool_or(expression_t *expr);
void perform_bool_eq(expression_t *expr);
void perform_bool_nqe(expression_t *expr);

#endif /* _BOOL1_H_ */
