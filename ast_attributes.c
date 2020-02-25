
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"
#include "linked_lists.h"
#include "hash_table.h"
#include "abstract_tree.h"
#include "ast_attributes.h"

// note that the int and uint are both 64 bits
typedef struct sym_str {
    attrib_type_t value;
    const char *str;
} sym_str_t;

static sym_str_t sym_str_table[] = {
    {ATTRIB_TYPE_DICT, "TYPE_DICT"},
    {ATTRIB_TYPE_ARRAY, "TYPE_ARRAY"},
    {ATTRIB_TYPE_BOOL, "TYPE_BOOL"},
    {ATTRIB_TYPE_STRING, "TYPE_STRING"},
    {ATTRIB_TYPE_INT8, "TYPE_INT8"},
    {ATTRIB_TYPE_INT16, "TYPE_INT16"},
    {ATTRIB_TYPE_INT32, "TYPE_INT32"},
    {ATTRIB_TYPE_INT64, "TYPE_INT64"},
    {ATTRIB_TYPE_FLOAT, "TYPE_FLOAT"},
    {ATTRIB_TYPE_UINT8, "TYPE_UINT8"},
    {ATTRIB_TYPE_UINT16, "TYPE_UINT16"},
    {ATTRIB_TYPE_UINT32, "TYPE_UINT32"},
    {ATTRIB_TYPE_UINT64, "TYPE_UINT64"},
    {ATTRIB_SCOPE_PUBLIC, "SCOPE_PUBLIC"},
    {ATTRIB_SCOPE_PRIVATE, "SCOPE_PRIVATE"},
    {ATTRIB_SCOPE_PROTECTED, "SCOPE_PROTECTED"},
    {ATTRIB_METHOD_CONSTRUCT, "METHOD_CONSTRUCT"},
    {ATTRIB_METHOD_DESTRUCT, "METHOD_DESTRUCT"},
    {ATTRIB_METHOD_NORMAL, "METHOD_NORMAL"},
    {ATTRIB_CLASS_ISMAIN, "CLASS_ISMAIN"},
    {ATTRIB_CLASS_ISCHILD, "CLASS_ISCHILD"},
    {ATTRIB_IS_REFERENCE, "IS_REFERENCE"},
    {ATTRIB_IS_DEFINITION, "IS_DEFINITION"}
};

#define NUM_ITEMS (sizeof(sym_str_table)/sizeof(sym_str_t))

static inline const char *convert_to_string(attrib_type_t type) {

    for(int i = 0; i < NUM_ITEMS; i++)
        if(type == sym_str_table[i].value)
            return sym_str_table[i].str;

    return NULL;
}

/*
 * Set a symbol attribute. The symbol is stored as a whole unit with the dots. 
 */
void ast_set_sym(const char *symbol) {
    ast_add_generic("symbol", (void *)symbol, strlen(symbol) + 2);
}

/*
 * Retrieve a symbol attribute, as a raw symbol, including the dots. 
 */
const char *ast_get_sym(void) {
    return ast_get_attribute("symbol");
}

/*
 * Set a zero data flag from the enums in the header. The presence or absence
 * of a flag indicates the information. 
 */
void ast_set_flag(attrib_type_t type) {
    ast_add_generic(convert_to_string(type), NULL, 0);
}

/*
 * Find out if a flag has been set in the attributes. Return a boolean. 
 */
int ast_get_flag(attrib_type_t type) {
    if(ast_get_attribute(convert_to_string(type)))
        return 1;
    else
        return 0;
}

/*
 * Set a value attribute. A pointer to the value is passed as well as the type. 
 * Both are stored separately in the attribute store. 
 */
void ast_set_value(void *value, attrib_type_t type) {

    size_t size;

    switch (type) {
        case ATTRIB_TYPE_DICT:
        case ATTRIB_TYPE_ARRAY:
            size = sizeof(void *);
            break;
        case ATTRIB_TYPE_STRING:
            size = strlen((char *)value) + 2;
            break;
        case ATTRIB_TYPE_FLOAT:
            size = sizeof(double);
            break;
        case ATTRIB_TYPE_BOOL:
        case ATTRIB_TYPE_INT8:
        case ATTRIB_TYPE_UINT8:
            size = sizeof(char);
            break;
        case ATTRIB_TYPE_INT16:
        case ATTRIB_TYPE_UINT16:
            size = sizeof(short);
            break;
        case ATTRIB_TYPE_INT32:
        case ATTRIB_TYPE_UINT32:
            size = sizeof(int);
            break;
        case ATTRIB_TYPE_INT64:
        case ATTRIB_TYPE_UINT64:
            size = sizeof(long long);
            break;
        default:
            size = sizeof(int);
            break;
    }
    ast_add_generic("value", value, size);
    ast_add_generic("value_type", (void *)&type, sizeof(type));
}

/*
 * Get the value. This function expects the caller to get the type of the value 
 * and cast it to the proper type. 
 */
void *ast_get_value(attrib_type_t * type) {

    void *val = ast_get_attribute("value");

    *type = *((attrib_type_t *) ast_get_attribute("value_type"));
    return val;
}
