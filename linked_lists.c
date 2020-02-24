#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_lists.h"
#include "errors.h"

linked_list_t *create_llist(void) {

    linked_list_t *lst;

    if(NULL == (lst = calloc(1, sizeof(linked_list_t))))
        fatal_error("cannot allocate memory for linked list");

    return(lst);
}

void destroy_llist(linked_list_t * lst) {

    linked_list_item_t *tmp;
    linked_list_item_t *next;

    for(tmp = lst->first; tmp != NULL; tmp = next) {
        next = tmp->next;
        if(tmp->data != NULL)
            free(tmp->data);
        free(tmp);
    }
    free(lst);
}

void *get_llist_current(linked_list_t * lst) {

    return(lst->current->data);
}

void *get_llist_first(linked_list_t * lst) {

    return(lst->first->data);
}

void *get_llist_last(linked_list_t * lst) {

    return(lst->last->data);
}

void reset_llist(linked_list_t * lst) {

    lst->current = lst->first;
}

void *llist_next(linked_list_t * lst) {

    if(lst->current->next != NULL) {
        lst->current = lst->current->next;
        return(lst->current->data);
    }
    else {
        return(NULL);
    }
}

void *llist_prev(linked_list_t * lst) {

    if(lst->current->prev != NULL) {
        lst->current = lst->current->prev;
        return(lst->current->data);
    }
    else {
        return(NULL);
    }
}

void llist_insert_end(linked_list_t * lst, void *data, size_t size) {

    linked_list_item_t *tmp;

    if(NULL == (tmp = calloc(1, sizeof(linked_list_item_t))))
        fatal_error("cannot allocate memory for list item at end");

    if(NULL == (tmp->data = calloc(1, size)))
        fatal_error("cannot allocate %d bytes for list data at end");

    memcpy(tmp->data, data, size);

    if(lst->first != NULL) {
        lst->last->next = tmp;
        tmp->prev = lst->last;
        lst->last = tmp;
    }
    else {
        lst->first = tmp;
        lst->current = tmp;
        lst->last = tmp;
    }
}

void llist_insert_start(linked_list_t * lst, void *data, size_t size) {

    linked_list_item_t *tmp;

    if(NULL == (tmp = calloc(1, sizeof(linked_list_item_t))))
        fatal_error("cannot allocate memory for list item at end");

    if(NULL == (tmp->data = calloc(1, size)))
        fatal_error("cannot allocate %d bytes for list data at end");

    memcpy(tmp->data, data, size);

    if(lst->first != NULL) {
        lst->first->prev = tmp;
        tmp->next = lst->first;
        lst->first = tmp;
    }
    else {
        lst->first = tmp;
        lst->current = tmp;
        lst->last = tmp;
    }
}

// insert after the current pointer and make the new point the current one.
void llist_insert_current(linked_list_t * lst, void *data, size_t size) {

    linked_list_item_t *tmp;

    if(NULL == (tmp = calloc(1, sizeof(linked_list_item_t))))
        fatal_error("cannot allocate memory for list item at end");

    if(NULL == (tmp->data = calloc(1, size)))
        fatal_error("cannot allocate %d bytes for list data at end");

    memcpy(tmp->data, data, size);

    if(lst->first != NULL) {
        tmp->prev = lst->current;
        tmp->next = lst->current->next;
        lst->current->next->prev = tmp;
        lst->current->next = tmp;
        lst->current = tmp;
    }
    else {
        lst->first = tmp;
        lst->current = tmp;
        lst->last = tmp;
    }
}

/*
 *  These functions implement an arbitrary data stack.
 */
data_stack_t create_stack(void) {

    return((data_stack_t) create_llist());
}

void push_stack(data_stack_t stack, void *data, size_t size) {

    llist_insert_start((linked_list_t *) stack, data, size);
}

void pop_stack(data_stack_t stack, void *data, size_t size) {

    linked_list_t *lst = (linked_list_t *) stack;
    linked_list_item_t *tmp = lst->first;

    if(tmp != NULL) {
        lst->first->prev = NULL;
        lst->first = lst->first->next;
        if(data != NULL)
            memcpy(data, tmp->data, size);
        if(tmp->data != NULL)
            free(tmp->data);
        free(tmp);
    }
}

void *get_stack(data_stack_t stack) {

    return(get_llist_first((linked_list_t *) stack));
}

void destroy_stack(data_stack_t stack) {

    destroy_llist((linked_list_t *) stack);
}

/*
    To build: clang linked_lists.c scanner.c errors.c parser.c
*/
// #define TESTING_LIST
#ifdef TESTING_LIST

void print_list(linked_list_t * list) {
    char *data;

    reset_llist(list);
    data = get_llist_current(list);
    do {
        printf("data: %s\n", data);
        data = llist_next(list);
    }
    while(data != NULL);

    data = get_llist_current(list);
    do {
        printf("data: %s\n", data);
        data = llist_prev(list);
    }
    while(data != NULL);
}

int main(void) {
    linked_list_t *list;
    char buf[1024];
    char *data;
    int i;

    list = create_llist();

    for(i = 0; i < 10; i++) {
        sprintf(buf, "this is string number %d", i);
        llist_insert_end(list, buf, strlen(buf) + 1);
    }

    print_list(list);

    for(i = 0; i < 4; i++)
        llist_next(list);

    sprintf(buf, "insert this string at start");
    llist_insert_start(list, buf, strlen(buf));
    sprintf(buf, "insert this string at end");
    llist_insert_end(list, buf, strlen(buf));
    data = get_llist_current(list);
    printf("\ndata: %s\n\n", data);

    print_list(list);

    for(i = 0; i < 4; i++)
        llist_next(list);

    data = get_llist_current(list);
    printf("\ndata: %s\n\n", data);
    sprintf(buf, "insert this string at current 1");
    llist_insert_current(list, buf, strlen(buf));
    sprintf(buf, "insert this string at current 2");
    llist_insert_current(list, buf, strlen(buf));

    print_list(list);

    data = get_llist_current(list);
    printf("\ndata: %s\n\n", data);

    destroy_llist(list);
    return 0;
}

int yywrap(void) {
    return 0;
}

#endif
