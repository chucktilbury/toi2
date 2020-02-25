#ifndef _ABSTRACT_TREE_H_
#  define _ABSTRACT_TREE_H_

// Opaque handles for AST
typedef void *ast_node_t;

// The actual tree is a global beause there is only one and
// this code is not reentrant.
void init_ast(void);
void ast_destroy_tree(void);

// These two functions set the current node as the tree is traversed
// while it is being created.
void ast_open_node(void);
void ast_close_node(void);

// Get and set attributes to the current node.
// void ast_add_attribute(const char *name, void *data, const size_t size);
void *ast_get_attribute(const char *name);
void ast_add_string(const char *name, const char *str);
void ast_add_generic(const char *name, void *data, size_t size);

// Symbol manipulations reference the current node.
ast_node_t ast_lookup_symbol(const char *name);
void ast_add_symbol(const char *name);

// Dump the ast tree for debugging
void ast_dump_tree(void);

#endif /* _ABSTRACT_TREE_H_ */
