Documentation
=============

In total the documentation burden is (at most) 1000 words
plus one diagram. Assesment of the documentation is not relative
to compiler functionality, it just requires a description
of the compiler as-is, and a realistic assessment of the
compiler's strengths and weaknesses.


AST
===

Overview Diagram
----------------

![my-ast.png](my-ast.png)

Description
-----------

It was attempted to make the tree balanced in breadth and depth, and as a result the hierarchy does not have more than four layers. All classes fundamentally inherit from one base class, used as the API for sub-classes. Constants (e.g. integers) are only stored in token classes, allowing the code generation to be consistent with pointers.

Every class in the AST can be traced back to a base class and can access the tokens, context and registers/stack. Expressions require two member functions that statements do not, constant fold for global variables, and the ability to retrieve ID. Each subclass is then derived from the Expression or Statement, split according to their functionality, requiring it to have only the necessary functions. Where possible, another hierarchy of an abstract class has been made, enabling neater code for inheriting classes (such as maths operations).

Statement classes depend on the expression classes, and their correct evaluation, however they do not inherit directly from them. Although the diagram does not show, the final result of most expressions also depend on the code generation of other expressions.

Strengths
---------

_Give two strengths or capabilites of your AST, using 50 words or less for each one_.

### Strength 1

Allowing multiple abstract classes within the hierarchy of the tree has enabled the actual assembly generation code to be relatively short. Code reusability is improved as classes that can be categorised into the same group are grouped together. This also improves the code readability.

### Strength 2

The structure takes advantage of polymorphism, ensuring that the current class does not need to remember the class it has been called from or idenetify the next class being called. Thus, debugging specific classes is also made easier. 

Limitations
-----------

_Give two limitations of your AST, using 50 words or less for each one_.

### Limitation 1

Lists from the grammar in particular need to be stored as vectors in the AST, which each class that requires it must store privately. An AST with better abstraction could use this as part of its structure instead of passing vectors.

### Limitation 2

As expressions and statements are derived from different abstract classes, a certain disconnection between the two exists. The addition of a class that is neither, or that requires both would require inheritance that is not supported by the AST structure produced.


Variable binding
================

General approach
----------------

The API involves a context class and memory class. Each class can thereafter generate their own code, without considering other classes.

Context is used to keep track of the scoping, as well as mapping of the variable. The context knows the current scope, and therefore all the declarations within the scope and above it; essentially forming a separate symbol table for each scope. The index of the vector corresponds to the current scope, and the vectors in the structs store the bindings. Subroutines can be called from the context class, as it keeps track of the current function. Allocation of appropriate amounts of memory is evaluated using a separate member function.

Registers and stack allocation are handled by a separate class, passed in the same way as the context. A vector of pointers to structs (that have their own vector) is used for this purpose, with the current value being a string (as they do not have to be initialised). This allows the obtaining of free space (as stack or registers), writing to it, and freeing it as and when necessary. Whether or not a register or the stack is required depends on the member function using it.

Strengths
---------

_Give two strengths or capabilites of your binding approach, using 50 words or less for each one_.

### Strength 1

It allows for complex input programs. By obtaining a temporary register or memory space and freeing it when not required, there is no need to consider which register may overwrite another as the file is parsed. Variables are stored in the stack, allowing the input programs to have more than thirty-one declarations, for example.

### Strength 2

Binding variables is simple for each member function, as the member function only needs to insert symbols and indicate when a new scope should be created. This makes the program easier to read, debug and further extend.

Limitations
-----------

_Give two limitations of your binding approach, using 50 words or less for each one_.

### Limitation 1

The context is not flushed of variables, as the program assumes it may be required, thus using considerably more stack memory. For this reason the approximated space allocated (by traversing through the AST) needs to be overestimated: multiplied by two.

### Limitation 2

Handling of the memory is performed separately to binding the variables, which allows for more errors in assembly generation. This can be prevented by keeping one class for both that always writes to memory when a variable is declared.


Reflection
==========

Strengths
---------

_What two aspects of your compiler do you think work well (beyond
those identified in the AST and binding parts)?_

### Strength 1

For debugging purposes, every non-abstract class has a pretty print function (which works on a particular stream). The output is much easier to read than debugging assembly (which also has comments for debugging upon enabling) and provides the ability to know which member function is currently executing the input.

### Strength 2

Classes are included in files (hpp or cpp) according to their purpose, rather than having one class per file. This improves the usability/readability of the compiler. The use of cpp objects decreases compile time as all code need not always be recompiled.

Scope for Improvment
---------------------

_What parts of your compiler do you think could be improved?_

### Improvement 1

The grammar restricts the AST structure, which has a further disconnection between Expressions and Statements in the (e.g. declarations and initialisers). Although this could be achieved using global variables, it is not a scalable solution. The AST could be made deeper, or another class could be used to connect them.

### Improvement 2

There is no optimisation performed by the compiler, although constant propagation has been attempted. Assembly files that are needlessly resource extensive are produced as a result. Checks could be done when fetching variables, for example, to make a more optimising compiler.


Functionality (not assessed)
============================

Which of these features does your compiler support (insert
an `x` to check a box):

1 - [ x ] Local variables
2 - [ x ] Integer arithmetic
3 - [ x ] While
4 - [ x ] IfElse
5 - [ x ] For
6 - [ x ] Function calls
7 - [ ] Arrays
8 - [ ] Pointers
9 - [ ] Strings
10 - [ ] Structures
11 - [ ] Floating-point

Note that all features will be tested, regardless of what
appears here. This is documentation of what you expect to work,
versus what doesn't work.


Feedback (not assessed)
=======================

_What aspects of your compiler would you like feedback on.
Be specific, as "what could I have done differently" is
too general to answer._

### Feedback 1

Besides what passed or failed, limitations of the AST used. Was it a good or bad approach for this particular problem?

### Feedback 2

Any general feeback on my program, for example compared to the norm used by computer scientists like yourself?
