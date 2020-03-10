#ifndef _UTILS_H_
#define _UTILS_H_
/*
    This is the include for the utils library.
*/
#  include <stdio.h>
#  include <stdlib.h>
#  include <stdint.h>
#  include <string.h>


/*
    For errors.c
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

void debug_mark(int, const char *);
void debug_msg(int, const char *, ...);

enum {
    SYNTAX_ERROR,
};

/*
 * TODO: Add more macros for debugging and memory tracking.
 */
#  ifdef TRACE
#    define MARK()      debug_mark(5, __func__)
#    define MSG(...)    debug_msg(5, __VA_ARGS__)
#  else
#    define MARK()
#    define MSG(...)
#  endif

/*
    For hash_table.c
*/
typedef void *hash_tab_t;

hash_tab_t create_hash_table(int slots);
void destroy_hash_table(hash_tab_t ht);
int hash_save(hash_tab_t ht, const char *key, void *data, size_t size);
void *hash_find(hash_tab_t ht, const char *key);
uint32_t make_hash(const char *str);

/*
    For linked_lists.c
*/
typedef void *data_stack_t;
typedef void *llist_t;

llist_t create_llist(void);
void destroy_llist(llist_t);
void *llist_current(llist_t);
void *llist_first(llist_t);
void *llist_last(llist_t);
void reset_llist(llist_t);
void *llist_next(llist_t);
void *llist_prev(llist_t);
void llist_insert_end(llist_t, void *, size_t);
void llist_insert_start(llist_t, void *, size_t);
void llist_insert_current(llist_t, void *, size_t);

data_stack_t create_stack(void);
void push_stack(data_stack_t stack, void *data, size_t size);
void pop_stack(data_stack_t stack, void *data, size_t size);
void *get_stack(data_stack_t stack);
void destroy_stack(data_stack_t);

/*
    For lifo.c
*/
typedef void *lifo_t; // opaque handle

lifo_t lifo_create(void);
void lifo_destroy(lifo_t lifo);
void lifo_push(lifo_t lifo, void *data, size_t size);
int lifo_pop(lifo_t lifo, void *data, size_t size);
int lifo_peek(lifo_t lifo, void *data, size_t size);

/*
    For fifo.c
*/
typedef void *fifo_t; // opaque handle

fifo_t fifo_create(void);
void fifo_destroy(fifo_t lifo);
void fifo_add(fifo_t fifo, void *data, size_t size);
int fifo_get(fifo_t fifo, void *data, size_t size);
int fifo_reset(fifo_t fifo);

#endif /* _UTILS_H_ */