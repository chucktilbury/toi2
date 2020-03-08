//////////// STYLES ///////////////////////////////
// Use GNU coding style.  This is the default.
//--gnu-style

// Use Kernighan & Ritchie coding style.
//--k-and-r-style

// Use Linux coding style.
//--linux-style

// Use the original Berkeley coding style.
//--original

/////////// INDENTATION //////////////////////////////////////
// If using tabs for indentation, use spaces for alignment.
--align-with-spaces

// Do not pad comments out to the nearest tabstop.
--dont-tab-align-comments

// Set tab size to n spaces.
--tab-size4

// Use tabs. This is the default.
//--use-tabs

// Use spaces instead of tabs.
--no-tabs

// Set indentation level to n spaces.
--indent-level4

// Set offset for labels to column n.
--indent-label0

// Indent parameter types in old-style function definitions by n spaces.
//--parameter-indentation0

// Zero width indentation for parameters.
--no-parameter-indentation

// Line up continued lines at parentheses.
--continue-at-parentheses

// Leave space between ‘#’ and preprocessor directive.
--leave-preprocessor-space

// Specify the indentation for preprocessor conditional statements.
--preprocessor-indentation2


//////////// BLANK LINES ///////////////////////////////
// Force blank lines after the declarations.
--blank-lines-after-declarations

// Do not force blank lines after declarations.
//--no-blank-lines-after-declarations

// Force blank lines after procedure bodies.
--blank-lines-after-procedures

// Do not force blank lines after procedure bodies.
//--no-blank-lines-after-procedures

// Force blank lines before block comments.
--blank-lines-before-block-comments

// Do not swallow optional blank lines.
//--leave-optional-blank-lines

// Swallow optional blank lines.
--swallow-optional-blank-lines


//////////// DECLARATIONS ///////////////////////////////////////
// Force newline after comma in declaration.
//--blank-lines-after-commas

// Do not force newlines after commas in declarations.
--no-blank-lines-after-commas

// Put braces on line following function definition line.
//--braces-after-func-def-line

// Put braces on function definition line.
--braces-on-func-def-line

// Put braces on the line after struct declaration lines.
//--braces-after-struct-decl-line

// Put braces on struct declaration line.
//--braces-on-struct-decl-line

// Break the line before all arguments in a declaration.
//--break-function-decl-args

// Don’t put each argument in a function declaration on a separate line.
--dont-break-function-decl-args

// Break the line after the last argument in a declaration.
//--break-function-decl-args-end

// If -cd 0 is used then comments after declarations are left justified
// behind the declaration.
//--left-justify-declarations

// Comments after declarations are treated the same as comments after
// other statements.
--dont-left-justify-declarations

// Put variables in column n.
//--declaration-indentation4

// Put the type of a procedure on the same line as its name.
--dont-break-procedure-type

// Put the type of a procedure on the line before its name.
//--procnames-start-lines

// Put a space after the ‘{’ and before the ‘}’ in initializers.
//--spaces-around-initializers

// Tell indent the name of typenames. All type names must be named to
// format properly.
-T parser_node_type_t
-T parser_attr_type_t
-T item_value_t
-T symbol_linkage_t
-T expr_linkage_t
-T expression_t
-T parse_tree_attrs_t
-T parse_tree_node_t

////////////// LONG LINES //////////////////////////////
// Prefer to break long lines before boolean operators.
//--break-before-boolean-operator

// Do not prefer to break long lines before boolean operators.
--break-after-boolean-operator

// Treat gettext _("...") and N_("...") as strings rather than as
// functions.
//--gettext-strings

// Treat gettext _("...") and N_("...") as normal functions.  This is
// the default.
--no-gettext-strings

// Prefer to break long lines at the position of newlines in the input.
//--honour-newlines

// Do not prefer to break long lines at the position of newlines in the
// input.
--ignore-newlines

// Set maximum line length for non-comment lines to n.
--line-length150


////////////// STATEMENTS ///////////////////////////////
// Put braces on line after if, etc.
//--braces-after-if-line

// Put braces on line with if, etc.
--braces-on-if-line

// Indent braces n spaces.
--brace-indent0

// Put a space between sizeof and its argument.
//--blank-before-sizeof

// Indent braces after a case label N spaces.
--case-brace-indentation4

// Continuation indent of n spaces.
--continuation-indentation4

// Case label indent of n spaces.
--case-indentation4

// Put a space after a cast operator.
//--space-after-cast

// Do not put a space after cast operators.
--no-space-after-casts

// Cuddle while of do {} while; and preceding ‘}’.
--cuddle-do-while

// Do not cuddle } and the while of a do {} while;.
//--dont-cuddle-do-while

// Cuddle else and preceding ‘}’.
//--cuddle-else

// Do not cuddle } and else.
--dont-cuddle-else

// Do not line up parentheses.
//--dont-line-up-parentheses

// Do not put space after the function in function calls.
--no-space-after-function-call-names

// Insert a space between the name of the procedure being called and
// the ‘(’.
//--space-after-procedure-calls

// Put a space after every ’(’ and before every ’)’.
//--space-after-parentheses

// Do not put a space after every ’(’ and before every ’)’.
--no-space-after-parentheses

// Do not force a space before the semicolon after certain statements.
// Disables ‘-ss’.
--dont-space-special-semicolon

// Specify the extra indentation per open parentheses ’(’ when a
// statement is broken.See  STATEMENTS.
--paren-indentation0

// Put a space after each for.
//--space-after-for

// Do not put a space after every for.
--no-space-after-for

// Put a space after each if.
//--space-after-if

// Do not put a space after every if.
--no-space-after-if

// Put a space after each while.
//--space-after-while

// Do not put a space after every while.
--no-space-after-while

// Indent braces of a struct, union or enum N spaces.
--struct-brace-indentation0

// Allow for unbraced conditionals (if, else, etc.) to have their inner
// statement on the same line.
--single-line-conditionals

// On one-line for and while statements, force a blank before the
// semicolon.
--space-special-semicolon


///////////////// COMMENTS ////////////////////////////////////
// Put comments to the right of code in column n.
--comment-indentation0

// Set maximum line length for comment formatting to n.
--comment-line-length80

// Put comments to the right of the declarations in column n.
--declaration-comment-column0

// Put comment delimiters on blank lines.
--comment-delimiters-on-blank-lines

// Do not put comment delimiters on blank lines.
//--no-comment-delimiters-on-blank-lines

// Put comments to the right of #else and #endif statements in column n.
--else-endif-column0

// Set indentation of comments not to the right of code to n spaces.
--line-comments-indentation0

// Format comments in the first column.
--format-first-column-comments

// Do not format comments in the first column as normal.
//--dont-format-first-column-comments

// Do not disable all formatting of comments.
--format-all-comments

// Do not format any comments.
//--dont-format-comments

// Fix nested comments.
--fix-nested-comments

// Do not put the ‘*’ character at the left of comments.
//--dont-star-comments


///////////////// MISC ////////////////////////////////

// Enable verbose mode.
//--verbose

// Disable verbose mode.
--no-verbosity

// Put asterisks in pointer declarations on the left of spaces, next to
// types: ‘‘char* p’’.
//--pointer-align-left

// Put asterisks in pointer declarations on the right of spaces, next to
// variable names: ‘‘char *p’’. This is the default behavior.
--pointer-align-right

// Preserve access and modification times on output files.
//--preserve-mtime

// Put the ‘*’ character at the left of comments.
--start-left-side-of-comments

// Write to standard output.
//--standard-output

