# C
## Components of writing good code
- Correctness: Does it work as intended? Does it do what it says?
- Design: How well written is the code? Is it concise and nice-looking? Very efficient. 
- Style: What are the asthetics? Like Capitalization and punctuation? How readable is it?

### Learning w CS50 IDE (https://ide.cs50.io)
source code -> compiler -> machine code (binary language)

### Using the Terminal 
`make hello` will complie the file  
`./hello` will run the file  
**always compile before running the file**  
got an error? run `help50 <command>` to see what the problem is  
ugly code? run `style50 <filename>` to see how to improve it
is the code correct? run `check50 <filename path>` to check it

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
