# C
## Components of writing good code
- Correctness: Does it work as intended? Does it do what it says?
- Design: How well written is the code? Is it concise and nice-looking? Very efficient. 
- Style: What are the asthetics? Like Capitalization and punctuation? How readable is it?

### Learning w CS50 IDE (https://ide.cs50.io)
source code -> compiler -> machine code (binary language)

### Using the Terminal 
`make hello` will complie the file  c
`./hello` will run the file  
**always compile before running the file**  
got an error? run `help50 <command>` to see what the problem is  
ugly code? run `style50 <filename>` to see how to improve it  
is the code correct? run `check50 <filename path>` to check it  
`mv` to rename and move files  
`rm` to remove files  
`mkdir` make a directory  
`cd` to change directory 
`rmdir` to remove directory  
`cp` to copy a file 

## Syntax
Function: an action or verb   
Arguments: inputs to functions, separate arguments with a comma    
- Scratch to C: when 🟩 clicked -> `int main(void)`  
- Scratch to C: say hello, world -> `printf("hello, world");`  

Return Values: a placeholder  
Variables: what the placeholder is set to  
- Scratch to C: ask What's your name? and wait for answer -> `string answer = get_string("What's your name? ");`  
- Scratch to C: say hello, answer -> `printf("hello, %s\n", answer);`  

`\n` adds a new line after the output  
`//` adds a comment to say what the purpose of this code is  

### Value Types
- bool: true or false 
- int: only use 32 bits total, supports simple negative and positive numbers  
- float: a fraction or decimal
- double:
- string:  
- char:  

#### Printing
- %c prints a  
- %f prints a  
- %i prints an integer  
- %li prints a long integer  
- %s prints a string

#### Operators 
- +  
- -  
- *  
- || is OR 
- && is and

Cast: will change the value type of a variable  

Scratch to C: set counter to 0 -> `int counter = 0;`  
Scratch to C: change counter by 1 -> `counter = counter + 1;` OR `counter += 1;` OR `counter++;`  

#### Conditions  
Scratch to C: if x < y then say it -> ` if (x < y) { printf("x is less than y\n"); }`
Scratch to C: else if x > y then say its not -> `else if (x > y) { printf("x is greater than y\n"); }`
Scratch to C: else if x = y then say their equal -> `else { printf("x is equal to y\n"); }`

#### Loops
Scratch to C: an infinite loop: forever say hello, world -> `while (true) { printf("hello, world"); }`  
Scratch to C: repeat hello, world 50 times -> `int i = 0; while (i < 50) { printf("hello\n"); i++; }`
Scratch to C: (much better) repeat hello, world 50 times -> `for (int i = o; i < 50; i++) {printf("hello\n"); }`

### Abstraction

