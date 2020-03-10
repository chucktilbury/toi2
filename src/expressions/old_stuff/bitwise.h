#ifndef _BITWISE_H_
#  define _BITWISE_H_

#  include "expressions.h"
void perform_bitwise_and(expression_t *expr);
void perform_bitwise_or(expression_t *expr);
void perform_bitwise_xor(expression_t *expr);
void perform_bitwise_shl(expression_t *expr);
void perform_bitwise_shr(expression_t *expr);
void perform_bitwise_rol(expression_t *expr);
void perform_bitwise_ror(expression_t *expr);

#endif /* _BITWISE_H_ */
