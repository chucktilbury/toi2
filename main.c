#include <stdio.h>
#include <stdlib.h>

#include "scanner.h"
#include "parser.h"
#include "errors.h"
#include "ast_tree.h"

int main(int argc, char **argv) {
    init_errors(0, stdout);
    open_file(argv[1]);

    init_ast();
    yyparse();

    int errors = get_num_errors();

    if(errors != 0)
        printf("\nparse failed: %d errors: %d warnings\n", errors, get_num_warnings());
    else
        printf("\nparse succeeded: %d errors: %d warnings\n", errors, get_num_warnings());

    return errors;
}
