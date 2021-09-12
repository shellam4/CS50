# Algorithms

Searching through input with an algorithm(sequence of steps to iterate through) to get an end value.   
- Running time is how long it takes for an algorithm to run 

#### Big O Notation is used to describe the running time of algorithmns on the upper bound
- O(log n) - where n is the variable- logrithmic means halving a problem again and again to lessen the time to solve

#### Big O Cheatsheet
O(n^2):  selection sort, bubble sort   
O(n log n): merge sort  
O(n):  linear search  
O(log n):  binary search  
O(1):   

#### omega notation refers the lower bound(faster) like minimum steps needed to finish running the algorithm, this refers to the nest case scnerario
Cheatsheet  
omega(n^2):  selection sort  
omega(n log n): merge sort  
omega(n): bubble sort    
omega(log n):    
omega(1):  linear search, binary search 

#### theta notation means the algorithm has the same upper and lower bound in both Big O and omega notation like selection and merge sort

#### Linear search means to check the values of an array 1 by 1 because we did not know if the elements were sorted already  
- What is the upper bound of the running time for a linear search? O(n)  
- What is the lower bound of the running time for a linear search? omega(1) because you could find it at the 1st element which is the best case possible  

#### Binary search means to easily check the values because they are sorted and it becomes more obvious in which direction the values lies
- What is the upper bound of the running time for a binary search? O(log n) because it is the max number of times you can split the array in half until you find the value     
- What is the lower bound of the running time for a binary search? omega(1) because that would be best case if it is exactly where you start the search  

#### Data structures 
Allow the program to use customized data type using `typedef struct {decalre the data types and names} `  

#### Sorting is needed before doing binary search
- Selection sorting means the computer is selecting the smallest element again and again and then ignoring it when sorting the rest  
    - Psuedocode: for i from 0 to n - 1 -> find the smallest between i item and last item -> swap smallest item with i item
- Bubble sort is reverse selection sorting that moves the larger element to the end. it compares each pair of elements to which is larger
    - Psuedocode: repeat until sorted(do not keep doing passing if already sorted) -> for i from 0 to n - 2 -> if i and i + 1 are out of order -> swap them
    - Psuedocode: aka repeat n - 1 times -> quit if no swaps
- Merge sort works more intelligently and means sort as long as the problem keeps getting smaller and smaller by halving it again and again, then sort each portion and combine them into a whole sorted array
    - Psuedocode: if only 1 number -> quit, else -> soft left half -> soft right half -> merge the sorted halves
    - will need at least a second array to temporarily save the sorted arrays meaning it'll need more memory

#### Recursion means calling a function in that same function allowing a larger loop (a function can call itself but be more specific to allow different output even w the same input)
