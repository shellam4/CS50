#### CS50 tools
- help50
- check50
- submit50
- printf
- debug50: create a breakpoint by clicking on the gutter side on the specific line. Will open a panel on the right side. 

Debugging explains the methodology of your code and why you're getting that certain output. 
- Call Stack is a fancy way of referring to all functions that have been executed but not yet returned.
- Step into will go to the first line of code in the function that executes something
- Rubber Duck Debugging: have someone to talk to about when walking through my code

#### Data Types 
  bool: 1 byte  
  char: 1 byte  
  double: 8 bytes  
  float: 4 bytes  
  int: 4 bytes  
  long: 8 bytes  
  string: ? bytes (variable)  
  
## Arrays: a sequence of values stored in memeory 
 instead of:  
 `int score1 = 72;
  int score2 = 73;
  int score3 = 33;`
 do:  
 `int scores[0];
  scores[0] = 72;  
  scores[1] = 73;
  scores[2] = 33;`  
The number in the brackets refers to the position of the value in the array.  
The program needs to know how big the array is when you are declaring it.   
\0 marks the end of the string with a null character. 
An array of arrays looks like arrayname[][]  
See all the many functions at manual.cs50.io. 

#### Command line arguments
`echo $?` to see the exit status   
`int main(int argc, string argv[])` to pass input variables to the main function. 
 `int main` means the function returns an integer for the exit status  

#### Cryptography: support encryption between the user and the program by scrabbling the text from plain to cipher. 
The cipher is a sophisticated algorithm that scrabbles the input to something not so obvious like using the ascii notation or going up by 1 for every letter   
