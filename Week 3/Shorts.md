# Linear Search
- Iterates across an array left to right searching for a specific element  
- Psuedocode: repeat from the 1st element -> if it's that one, then stop searching -> else, move to the next element  
- worst case: have to look through all elements until the last element or it doesn't exist at all O(n)  
- best case: find it immediately omega(1)  

# Binary Search
- requires a special condition to be met beforehand by sorting it first, reduce the search area by half each time  
- Psuedocode: repeat until the size of (sub)array is 0 -> calculate the midpoint of the array and look at the middle -> if middle is less then look right and change endpoint and midpoint -> if middle is greater than look left  
- if the start point is greater than the endpoint, then the sub array size is 0 and the target element does not exist  
- worst case: O(log n)  
- best case: omega(1)  

# Bubble Sort (better for shorter arrays)
- move higher value elements to the right and lower value elements to the left  
- Psuedocode: set swap counter to a non zero value -> repeat until swap is 0 -> reset swap counter to 0 -> look at each of the pairs and sort them all if they are out of order and add 1 to the swap counter for each sort  
- worst case: array is completely reverse O(n^2)  
- best case: array is already sorted omega(n)  

# Selection Sort
- find the smallest unsorted element and add it to the beginning of the sorted list by swapping what is first, build the sorted list one element at a time  
- Psuedocode: repeat until no unsorted elements remain -> search ALL of the unsorted portion to find the smallest element -> swap that with the first element of the unsorted portion  
- worst case: look over all the elements to find the smallest element O(n^2)
- best case: same as worst omega(n^2)

# Recursion
- allows algorithm to run a function within itself  
- elegant because it will solve a problem shorter and more readable  
- the factorial function (n!) (written as fact(n) in programs) is defined over all positive integers. n! = all the positive ints less than or equal to n multiplied together    
    - example: 5! = 5 x 4 x 3 x 2 x 1 = 120  
    - example in programs = fact(5) = 5 x 4 x 3 x 2 x 1 = 120  
- fact(n) = n x fact(n - 1)  
- Base Case: triggers a termination of the recurive call with a simple solution like fact(1) = 1.   
- Recursive Case: where the recursion occurs and the function calls itself in a slightly different way  
- Basically always: `if(n == 1) { return 1; } else { return n * fact(n - 1) }`  

#### Collatz conjecture aka collatz(n)
- if n is 1, stop    
- otherwise, if n is even, repeat this process on n/2  
- otherwise, if n is odd, repeat this process on 3n + 1  

# Merge Sort
- Sort smaller arrays and combine thenm together in sorted order 
- Psuedocode: if (n>1) sort the left half of the array -> sort the right half of the array -> merge the 2 halves together
- worst case: 
- best case: 
