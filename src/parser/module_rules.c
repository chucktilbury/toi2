#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"
#include "scanner.h"
#include "linked_lists.h"
#include "hash_table.h"
#include "parser_support.h"

void module_module_list_end(void) {
    MARK();
}

void module_item_import_definition_end(void) {
    MARK();
}

void module_item_class_definition_end(void) {
    MARK();
}

void module_list_module_item_end(void) {
    MARK();
}
