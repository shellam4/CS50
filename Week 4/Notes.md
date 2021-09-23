# Memory
Hexidecimal aka base-16 uses 16 characters 0-9 and A-F, numbers are referenced as 0xnumber like 0x48  
#### Operators
& means to find the address in memory  
\* means to look inside the address in memory  
#### Pointer   
A variable that contains the memeory address of a another variable    
#### Strings  
The address is just the first character of the whole string, each character is a byte  
#### Pointer Arithmetic  
aka address arithmetic   
Adding or subtracting from a pointer moves it by a multiple of the size of the data type it points to. For example, assume we 
have a pointer to an array of 4-byte integers. Incrementing this pointer will increment its value by 4 (the size of the element).
#### UH OH  
What is a segmentation fault? Means we have touched a segment of memory that we shouldn't have accessed.  
Valgrind is used to find where this memory bug is happening 
-  `valgrind ./memory`
