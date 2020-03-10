
#include "utils.h"

typedef struct lifo_element {
    void *data;
    size_t size;
    struct lifo_element *next;
} lifo_element_t;

typedef struct lifo_struct {
    lifo_element_t *top;
    int num_elements;
} lifo_struct_t;

lifo_t lifo_create(void) {
    MARK();
    lifo_struct_t *ls;

    if(NULL == (ls = (lifo_struct_t*)calloc(1, sizeof(lifo_struct_t))))
        fatal_error("cannot allocate memory for LIFO struct");

    return (lifo_t)ls;
}

void lifo_destroy(lifo_t lifo) {
    MARK();
    lifo_struct_t *ls = (lifo_struct_t *)lifo;

    if(ls != NULL) {
        while(lifo_pop(lifo, NULL, 0)) {}
        free(ls);
    }
}

/*
    Push the data given onto the stack.
*/
void lifo_push(lifo_t lifo, void *data, size_t size) {
    MARK();
    lifo_struct_t *ls = (lifo_struct_t *)lifo;
    lifo_element_t *nelem;

    if(ls != NULL) {
        if(NULL == (nelem = (lifo_element_t*)calloc(1, sizeof(lifo_element_t))))
            fatal_error("cannot allocate memory for LIFO element");

        if(NULL == (nelem->data = malloc(size)))
            fatal_error("cannot allocate memory for LIFO element data");

        memcpy(nelem->data, data, size);
        nelem->size = size;
        ls->num_elements ++;

        if(ls->top == NULL)
            ls->top = nelem;
        else {
            nelem->next = ls->top;
            ls->top = nelem;
        }
    }
    else
        fatal_error("attempt to push to an invalid LIFO");
}

/*
    Pop the top of the stack into the data parameter given.
*/
int lifo_pop(lifo_t lifo, void *data, size_t size) {
    MARK();
    lifo_struct_t *ls = (lifo_struct_t *)lifo;
    lifo_element_t *popper;

    if(ls != NULL) {
        if(ls->top != NULL) {
            popper = ls->top;
            if(popper->size != size)
                MSG("LIFO size does not match: popper = %d and parm = %d", popper->size, size);
            if(popper->data != NULL) {
                if(data != NULL && size != 0)
                    memcpy(data, popper->data, size);
                free(popper->data);
                ls->top = popper->next;
                free(popper);
                ls->num_elements --;
                return 1;   // success
            }
            else
                MSG("LIFO popper data is NULL");
        }
    }
    else
        fatal_error("attempt to pop to an invalid LIFO");

    return 0;   // fail
}

/*
    Peek at the top of the stack without actually popping the data.
*/
int lifo_peek(lifo_t lifo, void *data, size_t size) {
    MARK();
    lifo_struct_t *ls = (lifo_struct_t *)lifo;

    lifo_element_t *popper;

    if(ls != NULL) {
        if(ls->top != NULL) {
            popper = ls->top;
            if(popper->size != size)
                MSG("LIFO size does not match: popper = %d and parm = %d", popper->size, size);
            if(popper->data != NULL) {
                if(data != NULL && size != 0)
                    memcpy(data, popper->data, size);
                return 1;   // success
            }
            else
                MSG("LIFO popper data is NULL");
        }
    }
    else
        fatal_error("attempt to pop to an invalid LIFO");

    return 0;   // fail
}

