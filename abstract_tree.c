
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"
#include "linked_lists.h"
#include "hash_table.h"
#include "abstract_tree.h"

/*
    This is the node type where the AST nodes are stored.
*/
typedef struct ast_node {
    struct ast_node *parent;
    llist_t children;
    hash_tab_t attributes;
} abstract_tree_node_t;

/*
    This is the data structure containing the root nodes and
    the current node. The current node is used when referencing
    attributes and adding children.
*/
typedef struct abstract_tree {
    abstract_tree_node_t *root;
    abstract_tree_node_t *current;
} abstract_tree_t;


// file global that these function access.
static abstract_tree_t *tree = NULL;
static void destroy_node(ast_node_t);
static inline abstract_tree_node_t *create_node(void);
static inline void add_attribute(const char *name, void *data, const size_t size);
//static inline llist_t *parse_symbol(const char *);


/******************************************************************************
    This block of code is the public interface for this module.

    All access to these data structures is through an opaque handle.
******************************************************************************/

/*
    Create the abstract tree. This gets called exactly once in the
    program.
*/
void init_ast(void) {

    abstract_tree_t *ttree;

    if(NULL == (ttree = (abstract_tree_t*)calloc(1, sizeof(abstract_tree_t))))
        fatal_error("cannot allocate memory for AST");

    tree = ttree;

    // root, current, and parent are all NULL.
    if(NULL == (ttree->root = create_node()))
        fatal_error("cannot allocate memory for AST root node");

    add_attribute("symbol", (void*)"root", strlen("root")+1);
}

/*
    Destroy the abstract tree and free all of the memory that was
    allocated for it.
*/
void ast_destroy_tree(void) {

    destroy_node(tree->root);
}

/*
    Create a new node and add it to the current node's children. Then make this
    node the current one. Adding attributes and such is always done on the
    current node.
*/
void ast_open_node(void) {

    abstract_tree_node_t *node = create_node();
    llist_insert_end(tree->current, (void*)node, sizeof(abstract_tree_node_t));
    tree->current = node;
}

/*
    Set the current node to be the parent of the current node. This should be
    done when we are completely finished with the node. I.e. when a '}' is
    parsed.
*/
void ast_close_node(void) {
    tree->current = tree->current->parent;
}

/*
    Retrieve the data stored in the attribute table based on the name given. If
    the name is not found, then return NULL.
*/
void *ast_get_attribute(const char *name) {
    return hash_find(tree->current->attributes, name);
}

/*
    Add a string attribute to the current node.
*/
void ast_add_string(const char *name, const char *str) {
    add_attribute(name, (void*)str, strlen(str)+1);
}

/*
    Add a generic attribute to the current node.
*/
void ast_add_generic(const char *name, void *data, size_t size) {
    add_attribute(name, data, size);
}

/*
    Dump the tree for debugging.
*/
void ast_dump_tree(void) {

}

/*
    This function retrieves a node where the symbol and its attributes are defined.
    If the symbol cannot be found then return NULL.

    This function will traverse the tree without updating the current node until the
    symbol is either found or not found. First the local node's symbol table is
    examined. If the symbol is not found, then the parent is searched and so on up
    to the root level. Compound symbols are stored as linked lists and the list is
    searched in order until the correct node is found or not. When a part of a
    compound symbol is located, then only child nodes are searched after that.
*/
ast_node_t ast_lookup_symbol(const char* name) {

    return NULL;
}

/*
    Store a symbol in the symbol table. The symbol that is stored in the table is
    always a name that is being defined for this node and it must have a
    corresponding node that has the attributes. Symbols that are being referenced
    are not stored this way.

    The compound symbol is passed in in "dot" notation and it is parsed and stored,
    allocating a compound_symbol_t as needed.
*/
void ast_add_symbol(const char *name) {

}

/******************************************************************************
    End of public interface.
******************************************************************************/

/*
    Save an attribute to the current node. This data is allocated and memcopied
    into the hash table. When the attribute is destroyed, this data must be
    freed. All names should be unique. If a name that is not unique is supplied,
    then the data is replaced in the table.
*/
static inline void add_attribute(const char *name, void *data, const size_t size) {
    hash_save(tree->current->attributes, name, data, size);
}

/*
    This function destroys the current node and all of it's children. It is
    implemented as a recursive function.
*/
static void destroy_node(ast_node_t tree) {

    abstract_tree_node_t *node = (abstract_tree_node_t *)tree;
    abstract_tree_node_t *tmp;

    reset_llist(node->children);
    for(tmp = (abstract_tree_node_t *)llist_current(node->children);
                tmp != NULL;
                tmp = (abstract_tree_node_t *)llist_next(node->children)) {
        destroy_node((ast_node_t)tmp);
    }

    destroy_hash_table(node->attributes);
    destroy_llist(node->children);
}

/*
    Allocate and initialize memory for a blank node, with an optional name.
*/
static inline abstract_tree_node_t *create_node(void) {

    abstract_tree_node_t *node;

    if(NULL == (node = (abstract_tree_node_t *)calloc(1, sizeof(abstract_tree_node_t))))
        fatal_error("cannot create new AST node");

    node->children = create_llist();
    node->attributes = create_hash_table(37); // 37 is a prime number of reasonable size.
    node->parent = tree->current;
    tree->current = node;

    return node;
}

// /*
//     Parse the string that has a format of name.name.name, or simply name.
// */
// static inline llist_t *parse_symbol(const char *name) {

//     if(name == NULL)
//         return NULL;

//     char *ch, *start, *buffer = strdup(name);
//     llist_t list = create_llist();

//     ch = start = buffer;
//     do {
//         if(*ch == '.') {
//             *ch = 0;
//             llist_insert_end(list, (void*)start, strlen(start)+1);
//             start = ++ch;
//         }
//         else {
//             ch++;
//             if(*ch == 0)
//                 llist_insert_end(list, (void*)start, strlen(start)+1);
//         }

//     } while(*ch != 0);

//     free(buffer);
//     return list;
// }