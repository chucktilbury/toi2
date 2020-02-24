#ifndef __UTILS_H__
#  define __UTILS_H__

/*
 *  Data structure for a generic linked list.
 */
typedef struct linked_list_item_t {
    void *data;
    struct linked_list_item_t *next;
    struct linked_list_item_t *prev;
} linked_list_item_t;

typedef struct linked_list_t {
    struct linked_list_item_t *first;
    struct linked_list_item_t *last;
    struct linked_list_item_t *current;
} linked_list_t;

typedef void *data_stack_t;

linked_list_t *create_llist(void);
void destroy_llist(linked_list_t *);
void *get_llist_current(linked_list_t *);
void *get_llist_first(linked_list_t *);
void *get_llist_last(linked_list_t *);
void reset_llist(linked_list_t *);
void *llist_next(linked_list_t *);
void *llist_prev(linked_list_t *);
void llist_insert_end(linked_list_t *, void *, size_t);
void llist_insert_start(linked_list_t *, void *, size_t);
void llist_insert_current(linked_list_t *, void *, size_t);

data_stack_t create_stack(void);
void push_stack(data_stack_t stack, void *data, size_t size);
void pop_stack(data_stack_t stack, void *data, size_t size);
void *get_stack(data_stack_t stack);
void destroy_stack(data_stack_t);

#endif /* __UTILS_H__ */
