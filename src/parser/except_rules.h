#ifndef _EXCEPT_RULES_H_
#  define _EXCEPT_RULES_H_

void except_parameter_formatted_string(void);
void except_parameter_complex_name(void);
void except_parameter_list_init(void);
void except_parameter_list_add(void);
void except_clause_parameter_list_start(void);
void except_clause_parameter_list_finish(void);
void except_clause_method_body_finish(void);
void except_clause_complex_name(void);
void final_clause_start(void);
void final_clause_finish(void);
void try_clause_intro_start(void);
void try_clause_intro_finish(void);
void try_clause_finish(void);
void raise_clause_parameter_start(void);
void raise_clause_parameter_finish(void);
void raise_clause_finish(void);

#endif /* _EXCEPT_RULES_H_ */
