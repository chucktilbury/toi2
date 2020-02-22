#include <stdio.h>
#include <stdlib.h>

#include "scanner.h"
#include "parser.h"
#include "errors.h"

int main(int argc, char **argv) {
    init_errors(0, stdout);
    open_file(argv[1]);

    yyparse();

    if(get_num_errors())
        printf("\nparse failed: %d errors: %d warnings\n", get_num_errors(),
               get_num_warnings());
    else
        printf("\nparse succeeded: %d errors: %d warnings\n", get_num_errors(),
               get_num_warnings());
    return 0;
}
