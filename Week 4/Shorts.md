# Hexadecimal 
Decimal system is base-10
Binary system is base-2
Knowing hexadecimal helps to remember memory addresses with 0x notation

# Pointers 
- provide a new way to pass data between functions unlike making copies 
- actually pass the value to the function and change the orginal value 
- pointers are just addresses to where variables live in the memory 
- a pointer is a data item whose value is a memory address like 0x487599

All data types take up different amounts of space 
- int gets 4 bytes 
- char 1 
- float 4 
- double 8
- long long 8 
- string number of chars + 1 for \0

Indexes allow random access to an array for the value you want 
```
int k;
k = 5;
int* pk;
pk = &k; 
```
- The `&x` is the pointer to the address of x in memory

In C, there's a NULL pointer which points to nothing, use this when the declared pointer is not set to something meaningful immediately. Check if the pointer is set to NULl with `==`. 
Dereferencing means go to the reference of the location and change the value there. `*pc = D` changes the value at the address of variable pc. 
`*` is the dereference operator
`Segmentation fault` happens when you try to derefence a pointer whose value is NULL. This can be a good thing against accidental manipulation. It is better to have the program crash then mess up another area in the code.

# Defining Custom Types
`typedef <old-name> <new-name>`
real example : `typedef char * string`
```
typedef struct car
{
int year;
char model[10];
char plate[7];
}
car_t;

// variable declaration
car_t mycar;
```
# Dynamic Memory Allocation (works w Pointers)
- we need to know exactly how much memory our system will need when our program is compiled. 
- dynamic is coming from the heap (will have higher numbers) 
- static is coming from the stack (grows up)
- Use malloc() by passing in the number of bytes requested and it will return a pointer to that memory which we have to derefence to. But first, check that is does not give back NULL before allocating it 
```
//dynamically obtain an integer
int *px = malloc(sizeof(int));

// get an int from the user
int x = get_int();

// array of floats on the stack 
float stack_array[x];

// array of floats on the heap 
float* heap_array = malloc(x * sizeof(int));

free(heap_array);
```
Memory leak comes when failing to release memory back to the system when the use is done. 
- use `free()` to release the memory 

# Call Stacks (how recursion happens)
- When you call a fuction, you set aside space in memory for the it. The chuncks of memory is called a frame. 
- The frames are arranged in a call stack where one frame is active the rest are waiting to become the active frame. When the function is done, it pops off the stack.

# File Pointers
- The ability to read and write to files for storing persistent data
Pointers
- fopen() opens a file and returns a file pointer to it, alway check that the file is not NULL
`FILE* ptr1 = fopen("file2.txt", "w"` (w is for write)
- fclose () closes the file pointed to by 
`fclose(ptr1)`
- fgetc() reads and returns the next char from the file pointed to
`char ch = fgetc(<file pointer>);`
`char ch = fgetc(ptr1);`
this simulates cat command : 
```
char ch;
while((ch = fgetc(ptr)) != EOF)
  printf("%c", ch);
```
- fputc() writes or appends the specified char to the pointed-to-file 
`fputc('!', ptr1);`
this simulates the cp command:
```
char ch;
while(ch = fgetc(ptr00 != EOF)
  fputc(ch, ptr2);
```
- fread() reads number of units of size from the file pointed to and stores them in memory in a buffere like an array pointed to by the buffer
`fread(<buffer>, <size>, <quantity>, <file pointer>)`
example - reading 40 bytes of info fromt he ptr file and storing it in an array
```
int arr[10];
fread(arr, sizeof(int), 10, ptr)
```
Dynaimcally allocate a buffer
```
double* arr2 = malloc(sizeof(double) * 80);
fread(arr2, sizeof(double), 80, ptr2);
```
- fwrite() writes number of units of size from the file pointed to by reading them from the buffer
```
double* arr2 = malloc(sizeof(double) * 80);
fwrite(arr2, sizeof(double), 80, ptr2);
```
- fgets() and fputs() is for strings
- fprintf() take the thing and print it to a file 
- fseek() move around in a file 
- ftell() what position 
- feof() at end of the file 
- ferror() sees is something went wrong
