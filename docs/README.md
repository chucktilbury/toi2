# Toi-2
This is another iteration on the toi language. It starts with a mostly working determinstic (i.e. no conflicts) Bison parser for the language. First I will tweak the parser to **exactly** match the language I have in mind. Next, I will instrument the parser in such a way as to mark places in it that will have an effect on the abstract syntax tree. Then I will add the code that actually implements the AST. After that, I will attempt to implement the interpreter, or a compiler for the LLVM assembly  language. I would prefer the compiler version, but the interpreter looks easier.

Here are some code examples with comments.

```C++
/*
  Assuming this program compiles to an executable called "progname".
*/

// This class constructor defines the entry point of the program.
class Main {
   // The default scope of the constructor is public, but all other 
   // class methods are scoped as private. Calling the constructor 
   // directly is a syntax error.
   //
   // The args_len and args parameters are required for the program entry 
   // point only. Any valid name will do, but the types are required.
   construct (int args_len, array args) {
      // Pretty standard for C here. All of the same meanings apply.
      if ( args_len > 2 ) {
         // The call print_formatted()() is part of the standard library. 
         // No imports are required. This is *not* a part of the language.
         print_formatted("Hello %s\n", args[1])();
      }
      // There is no "else if" clause. You simply supply an expression
      // for else. Blank expressions are taken to be True. One could also 
      // supply a blank () after an else clause, but I left it out for 
      // the sake of clarity. Curly braces are required. That simplifies 
      // the parser quite a bit.
      else {
         // The call to print()() is a standard library routine. 
         print("The name to print is a required argument.\n")();
      }
   }
}
```
from the command line:

* "progname"
prints: The name to print is a required argument.

* "progname Chuck"
prints: Hello Chuck!

```C++
/*
  Here is an example with non-library function calls.
*/
import strings

// parens after the class name are optional when there is no base class.
class BaseClass() {
  
  // The construct method is mandatory. An empty method is acceptible.
  // Notice that the constructor does not have any output parameters.
  construct(string name) { 
    
    // This sets the value of my_name using the built in setter method 
    // for class variables. The compiler can tell the difference between 
    // the two names using the symbol's attributes. See below.
    name(name)();
  }
  
  // This is not visible outside of this class. Note the order of the
  // keywords "string" and "private". Note that "getters" and "setters"
  // are automagically defined for variables in a class. They are 
  // referenced like any other function. See below.
  string private name;
  
  // This is a method that will be inherited by the child class.
  // This illustrates the use of input parameters and output parameters.
  // The input parameters, in the first tuple, are passed by value. The
  // output parameters, in the second tuple, are passed by reference.
  // They are both optional, but the () must be present for syntax.
  // Note the order of the "method" and "protected" keywords.
  method protected some_method(string name)(string outstr) {
    // This is contrived. The name is appended to the output parameter.
    strings.append(name)(outstr);
  }
}

// This class inherits the base class.
class SomeClass(BaseClass) {

  // The constructor for the base class is run automatically.
  construct(string name) {
    
    // This is valid syntax for initializing a base class. To create
    // a class instance, you would leave out the "construct" keyword.
    BaseClass.construct(name);
  }
  
  // generic method with no input or output parameters.
  method public do_all()() {
    
    string my_name;
    // This is an example of how a "getter" works. The word "name" is
    // defined by the base class as a protected element of the base 
    // class state. The getter and the setter is inaccesible by other
    // classes that did not inherit the base class.
    name()(my_name);
    
    // This is an example of a "setter".
    name(my_name)();
    
    // This is syntattically correct:
    name(my_name)(my_name);
    // but it makes no sense becasue the setter sets the name and the
    // getter just retrieves the same value.
    
    // Declare a variable before using it, anywhere in the method.
    int print_len;
    
    // Print_formatted returns the length of the string, but there was
    // no output parameter specified in the previous example. This is 
    // to illustrate that output parameters are optional, but they must
    // be defined before they are used. The function that outputs the
    // value can detect if an output parameter was given and behave 
    // accordingly. If an output parameter is given, but not used, then
    // it's ignored. Input parameters can be given default values, like 
    // Python or C++, but named parameters are not supported. Veradic
    // input parameters are supported like C/C++ with an elipsis.
    print_formatted("Hello %s!\n", name)(print_len);
    
    // Print_len is defined and it's value is set as an output parameter.
    print_formatted("there were %d characters printed\n", print_len);
  }
}

// Same as in the first example, but simplified.
class Main(SomeClass) {
  construct(int num_arg, array args) {
    SomeClass.construct(args[1]);
}

```
