#ifndef _SWITCH_CASE_RULES_H_
#  define _SWITCH_CASE_RULES_H_

void case_clause_unum(void);
void case_clause_inum(void);
void case_clause_fnum(void);
void case_clause_loop_body_finish(void);
void default_case(void);
void case_body_init(void);
void case_body_add(void);
void switch_clause_intro_expression_start(void);
void switch_clause_intro_expression_finish(void);
void switch_clause_intro_case_body_start(void);
void switch_clause_intro_case_body_finish(void);
void switch_clause_after_intro(void);
void switch_clause_after_intro_default(void);
void switch_clause_finish(void);

#endif /* _SWITCH_CASE_RULES_H_ */
