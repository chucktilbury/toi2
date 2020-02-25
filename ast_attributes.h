#ifndef _AST_ATTRIBUTES_H_
#  define _AST_ATTRIBUTES_H_

typedef enum attrib_type_t {
    ATTRIB_TYPE_DICT,
    ATTRIB_TYPE_ARRAY,
    ATTRIB_TYPE_BOOL,
    ATTRIB_TYPE_STRING,
    ATTRIB_TYPE_INT8,
    ATTRIB_TYPE_INT16,
    ATTRIB_TYPE_INT32,
    ATTRIB_TYPE_INT64,
    ATTRIB_TYPE_INT,
    ATTRIB_TYPE_FLOAT,
    ATTRIB_TYPE_UINT8,
    ATTRIB_TYPE_UINT16,
    ATTRIB_TYPE_UINT32,
    ATTRIB_TYPE_UINT64,
    ATTRIB_TYPE_UINT,

    ATTRIB_SCOPE_PUBLIC,
    ATTRIB_SCOPE_PRIVATE,
    ATTRIB_SCOPE_PROTECTED,

    ATTRIB_METHOD_CONSTRUCT,
    ATTRIB_METHOD_DESTRUCT,
    ATTRIB_METHOD_NORMAL,

    ATTRIB_CLASS_ISMAIN,
    ATTRIB_CLASS_ISCHILD,
    ATTRIB_IS_REFERENCE,
    ATTRIB_IS_DEFINITION
} attrib_type_t;

void ast_set_sym(const char *symbol);
const char *ast_get_sym(void);
void ast_set_flag(attrib_type_t type);
int ast_get_flag(attrib_type_t type); // returns bool
void ast_set_value(void *value, attrib_type_t type);
void *ast_get_value(attrib_type_t * type);

#endif /* _AST_ATTRIBUTES_H_ */
