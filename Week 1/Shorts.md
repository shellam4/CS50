# Data Types and Variables in C
- int: stores intergers, take up 4 bytes of memory (limited to 32 bits worth of info). 
- unsigned int: a type of qualifier, this doubles the positive range of variables and does not allow negative values (0 to 4 billion)  
- char: a variable that stores a single character, takes up 1 byte (8 bits). ASCII standard maps the positive numbers to characters on our keyboard  
- float: a real number, has a decimal point, takes up to 4 bytes (32 bits).  
- double: stores real numbers like floats but they can store up to 8 bytes (64 bits). This overcomes the precision problem with floats  
- void: this is not a data type (cannot be assigned a value). A function can have a void parameter meaning it does not return any values and does take any arguments. 

#### CS50 Library (must do #include <cs50.h>  
- bool: stores a boolean value (true of false)  
- string: collection of characters. Words, sentences, paragraphs 

#### How to create a variable (examples)  
int number;  (variable declaration)  
number = 17; (variable assignment)  
OR  
int number = 17; (variable initialization)

int width, height, length;  (declaring several variables at once)
float sqrt2, sqrt3, pi;   

# Operators in C  
- Arithmetic: pretty basic operators (add, substract, multiply( * ), and divide(/))   
  - int x = y + 1;   
  - x = x * 5; OR x *= 5;  
  - x++; and x--;
- Modulous: gives the remainder after diving to numbers
  - int m = 13 % 4 (m will be 1)  
- Boolean Expressions: used for comparing values. every non-zero value is equivalent to true and sero is always false
- Logical Operators:
  - Logical AND (&&) is true if and only if both operands are true, otherwise false. 
  - Logical OR (||) is true if and only if at least 1 operand is true, otherwise false.  
  - Logical NOT (!) inverts the value of the operand.  
- Relational Operators:
  - less than  
  - less than or equal to   
  - greater than >   
  - greater than or equal to >=  
  - equals ==  

# Conditional Statements  
Allows your programs to make decisions based on user input  
- if {} else if {} else {}  
- if {} if {} if {} else {} (the else is only binded to the 3rd branch  
- switch (x) {case 1: print...; break; ...} or switch(x) {case 5: print...; ...} (no break)  
- ternary operator: if else -> `int x = (expr) ? 5 : 6;` (if the expression is true do 5, if not do 6.  

# Loops  
- `while(true) {}` means infinite loop    
- `while(boolean expression) {} ` loop untill the expression is false.   
- `do {} while (bool expression);` do something at least once and then continue untill the expression is false.  
- `for (start; expression; incremention;) {}` repeat something a certain number of times.  

# Command Line
- `ls` will list all the files and folders in the current directory
- `cd` to change directories
- `pwd` print working directory
- `mkdir` to create a directory
- `rmdir` to remove a directory
- `cp -r <source> <dest>` copy a file or directory to a another directory
- `rm -rf` delete a file or directory completely
- `mv <source> <dest>` to move a or rename a file 
