
/*
 *  Errors header
 */
#ifndef _ERRORS_H_
#  define _ERRORS_H_

/*
 * TODO: Add macros for debugging and memory tracking.
 */

void init_errors(int level, FILE * fp);
void syntax(char *str, ...);
void scanner_error(char *str, ...);
void warning(char *str, ...);
void debug(int level, char *str, ...);
void fatal_error(char *str, ...);

void set_logging_level(int lev);
int get_logging_level(void);
int get_num_errors(void);
int get_num_warnings(void);
void set_error_level(int lev);
int get_error_level(void);
void set_error_stream(FILE * fp);
FILE *get_error_stream(void);
void inc_error_count(void);
void inc_warning_count(void);

enum {
    SYNTAX_ERROR,
};

#define DEBUG() debug(5, "%s: %d: %d: %s", get_file_name(), get_line_number(), get_col_number(), __func__);
#define DEBSTR(s) debug(5, "%s: %d: %d: %s: %s", get_file_name(), get_line_number(), get_col_number(), __func__, (s));

#endif /* _ERRORS_H_ */
