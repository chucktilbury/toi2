#ifndef _FOR_LOOP_RULES_H_
#  define _FOR_LOOP_RULES_H_

void for_initialize_assign_nothing(void);
void for_initialize_assign_expression(void);
void for_initialize_assign_bool_value(void);
void for_initialize_intrinsic_type(void);
void for_initialize_symbol(void);
void for_initialize_data_definition_finish(void);
void for_initialize_assignment(void);
void for_initialize_assignment_finish(void);
void for_test_expression(void);
void for_test_expression_finish(void);
void for_arith_expression_expression(void);
void for_arith_expression_pre_post_inc(void);
void for_arith_expression_assignment(void);
void for_clause_definition_init(void);
void for_clause_definition_finish(void);
void for_clause_loop_body_finish(void);

#endif /* _FOR_LOOP_RULES_H_ */
