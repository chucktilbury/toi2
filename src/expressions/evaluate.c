#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"
#include "scanner.h"
#include "expressions.h"

/*
    This exists to allow the parser to store an expression in such a way as
    to allow it to be evaluated multiple times without re-parsing it, such as
    the case would be if a function were called multiple times.

    The parser already organizes the order of values for us. Instead of having
    to use a different algorithm to convert the order of evaluation to
    something like RPN, we can simply store items in the order we find them,
    i.e. in a FIFO queue. As we evaluate the expression, we also use a stack
    (LIFO) to keep track. See the data structures in expressions.h.

    while there are items in the FIFO
        get an item from the FIFO
        if it's not an operator, then
            push it on to the LIFO.
        else if it's a unary operator,
            pop one from the LIFO
            apply the operator
            push the result back on the LIFO
        else if it's an operator and not unary
            pop two from the LIFO
            apply the operator
            push the result back on the LIFO
    The value on top of the LIFO is the result of the expression.

    These functions also evaluate the symantics of the expression. For example,
    trying to use a float to calculate a bool or mixing signed and unsigned
    types in an expression.
*/