# Functions 
aka procedures, methods, or subroutines
What is it? a black box with 0 or more inputs and 1 output. 
Why have it? 
- organization 
- simplification (easier to debug)
- reusablity 

Function Declarations go at the top of the code before main() to give the compiler a heads up   
syntax: return-type name(arguments);

#### Practice Problem
//create a function that makes sure the ints can create a valid triangle  
bool valid_triangle(float x, float y, float z) {  
// make sure all sides are positives  
  if (x <= 0 || y <= 0 || z <= 0) {  
    return false;  
  }  
// make sure the sum of any two values is greater than the 3rd value  
  if (x + y <= z || x + z <= y || y + z <= x) {  
    return false;  
  }  
  else {  
    return true;  
  }  
}  

# Variables and Scope 
Scope defines from which functions the variable can be access.  
- Local variable can only be accessed within the function it was created.  
- Global variable can be accessed by any function if it is declared outside all functions.  
- Passed by Value means that the variable being called by a function is returning a copy of it to the recipient function   

# Arrays
An array is a block of contigous space in memory which has partitioned into small, iidentically sized blocks of space called elements each of which can store a certain amount of data all of the same datat type which can be accessed directly by an index.   
- In C, the elements of an array are indexed starting at 0, so if you have n elements, the last element is n - 1.  
- Syntax: data-type name[size];    
- Create the list of elements: `bool table[] = {false, true, true};`     
- Create multiple size specifiers: `bool chessboard[10][10];`  
- Passed by Reference: means the function that calls the array will receive the actual array and not a copy of it compared to other declared variables  

# Command line arguments
Allows a user to provide data to the program at run-time instead of while the program is alraedy running by collecting the data at the command line.  
Declare main as: `int main(int argc, string argv[]) {`  
`argc` is the argument count, it stores the number of arguments the user typed when the program was executed.  
`argv` is the argument vector (array), it stores the strings per element in the list which is the actual arguments that the user typed. Everything is stored as a string.  
