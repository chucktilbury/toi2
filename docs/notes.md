
These are notes about the AST.

Each node will have exactly one parent, except the root node.
Each node will have a list of children.

For example, a class will have a child node for every method and data
definition, each with its own attributes, symbol, etc. A method in the
class will have the class node as its parent and numerous child classes.
A branching node will have the method node as a parent and numerous
child nodes. Every statement that is encountered by the parser will have
it's own node.

Expression nodes (as I see it now) will have a special child that has
all of the operations in the expression stored such that the switching
yard algorithm can be applied to it. I.e. dual stacks. It looks like
bison may do a lot of the work for us on that, so that may be a tree
of nodes as well. Experimentation is required.

When a symbol is looked up, the parent node is checked first. If it's
not found, then the next parent is searched until a name change is
required. In other words, a symbol is defined at the beginning of a
method and the symbol is being looked up from several layers deep in
a branch. First the local branch is searched progressing to parent
branches until it reached the class branch. If the name is a compound
name, then the name cannot be found. Note that inheritance causes
classes to be linked together so that they share a name space. If
the derived class has the symbol then it has been overridden and the
base class will not be searched. If the symbol is not found in the
derived class then the base class is searched. If that class has a
base class, then that is searched and so on. It may be well for a
class to keep a symbol table to speed up these searches. The symbol
table will simply have a pointer to the AST node that has the symbol
and its attributes.

Attributes will be different for different kinds of nodes. It seems
reasonable to store attributes by name in something like a hash table
that can store arbitrary data. For example, a class node does not have
a specific value, but a class variable does. So, designing and maintaining
different data structures for every kind of node seems like more work than
is required. The drawback of this approach is that it would take longer
to get things like attributes over having a data structure that is specific
to a given node type. Also, keeping the names straight while developing the
code is going to be a problem, but it should lead to more readable code.

It seems reasonable to access nodes directly instead of trying to abstract
them somehow. For example, a symbol node has all of that symbol's attributes,
so accessing it directly should save time.

There are still semantic issues to be resolved while the AST is being created.
For example, if a symbol represents an array or a dictionary. An array
requires an integer subscript and a dictionary requires a string. There are
a lot of these, especially when parsing an expression. Boolean and arithmetic
expressions are treated as the same thing in the bison parser.

```C
typedef struct ast_node {
    struct ast_node *parent;
    linked_list_t *children;
    hash_table_t *attributes;
} ast_node_t;
```

Note the implications of importing modules. An imported module will be
parsed and it's name space will be added as a child of the root node, but
with the import name prepended as if it were a class. Accesses will happen
using the import name in dot notation.

Note the implications of object vs. classes. The class to which an object
belongs must be found and stored when the AST is created. objects can be
reassigned to other names and such. For example:

```
a = SomeClass();
b = a;
```

Assignment of classes takes more code. There needs to be a simple way to copy
a node's attributes. Of course there is the scenario where someone may assign
an object to an int or something.

I plan to test the AST by writing code that will re-write the program
represented by the AST as a compilable text file. This should be able to be
done any number of times and still have it semantically the same.

------------------------

Do I want to mangle method names so that methods can be differentiated by their
input and/or their output parameters?

-------------------------

Implement intrinsic types as objects with methods that can be called on them.
These classes are defined in the standard library, which is defined in source
code and automatically imported for the program as children of the root node.

When the AST is created, that is taken into account as "special" syntax. The
"root" node is special in that specifying it is optional.

--------------------

