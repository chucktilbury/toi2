#ifndef __UTILS_H__
#  define __UTILS_H__

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
void destroy_stack(data_stack_t) ;

#endif /* __UTILS_H__ */
