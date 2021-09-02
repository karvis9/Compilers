# Compilers
Developed a compiler for a strongly typed language (SIL) running on a MIPS machine architecture using Lex,Yacc.

Project Summary : 

Built a compiler for a simple and strongly typed language. This included expression evaluator support, static storage allocation, creation of an abstract syntax tree which is parsed. Additionally I enhanced the compiler to support user defined arrays and variables using a global symbol table. The symbol tables uses a HashMap similar to modern compilers. Further enhancements done to the project include functions with recursion support, which required handling variable scope and run time storage allocation.This was constructed by having different local symbol tables and a master Global symbol table, with individual local symbol tables properly deallocated after local function code generation. The compiler generates code for the activation record on a function call at run time. 

Project Road Map : https://silcnitc.github.io/about.html
Project Documentation : https://silcnitc.github.io/documentation.html
