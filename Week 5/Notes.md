# Resizing arrays
- Last time, we learned about pointers, malloc, and other useful tools for working with memory.
- In week 2, we learned about arrays, where we could store the same kind of value in a list, back-to-back in memory. When we need to insert an element, we need to increase the size of the array as well. But, the memory after it in our computer might already be used for some other data, like a string:
- One solution might be to allocate more memory where there’s enough space, and move our array there. But we’ll need to copy our array there, which becomes an operation with running time of O(n), since we need to copy each of the original n elements first:
  - The lower bound of inserting an element into an array would be O(1) since we might already have space in the array for it.

# Data Structures
- Data structures are more complex ways to organize data in memory, allowing us to store information in different layouts.
- To build a data structure, we’ll need some tools:
  - `struct` to create custom data types
  - `.` to access properties in a structure
  - `*` to go to an address in memory pointed to by a pointer
  - `->` to access properties in a structure pointed to by a pointer

# Linked Lists
- With a linked list, we can store a list of values that can easily be grown by storing values in different parts of memory:
  - We have the values 1, 2, and 3, each at some address in memory like 0x123, 0x456, and 0x789.
  - This is different than an array since our values are no longer next to one another in memory. We can use whatever locations in memory that are free.
- To track all of these values, we need link our list together by allocating, for each element, enough memory for both the value we want to store, and the address of the next element:
three boxes, each divided in two and labeled (1 0x123 and 0x456), (2 0x456 and 0x789), and (3 0x789 and NULL)
  - Next to our value of 1, for example, we also store a pointer, 0x456, to the next value. We’ll call this a node, a component of our data structure that stores both a value and a pointer. In C, we’ll implement our nodes with a struct.
  - For our last node with value 3, we have the null pointer, since there’s no next element. When we need to insert another node, we can just change that single null pointer to point to our new value.
- We have the tradeoff of needing to allocate twice as much memory for each element, in order to spend less time adding values. And we can no longer use binary search, since our nodes might be anywhere in memory. We can only access them by following the pointers, one at a time.
- In code, we might create our own struct called node, and we need to store both our value, an int called number, and a pointer to the next node, called next:
```
typedef struct node
{
    int number;
    struct node *next;
}
node;
```

# Implementing Arrays 
- Recall that malloc allocates and frees memory from the heap area. It turns out that we can call another library function, realloc, to reallocate some memory that we allocated earlier:
`int *tmp = realloc(list, 4 * sizeof(int));`
  - And realloc copies our old array, list, for us into a bigger chunk of memory of the size we pass in. If there happens to be space after our existing chunk of memory, we’ll get the same address back, but with the memory after it allocated to our variable as well.

# Implementing linked lists
- Similarly, to insert a node in the middle of our list, we change the next pointer of the new node first to point to the rest of the list, then update the previous node to point to the new node.
- A linked list demonstrates how we can use pointers to build flexible data structures in memory, though we’re only visualizing it in one dimension.

# trees
-  A tree is another data structure where each node points to two other nodes, one to the left (with a smaller value) and one to the right (with a larger value):
tree with node 4 at top center, left arrow to 3 below, right arrow to 6 below; 2 has left arrow to 1 below, right arrow to 3 below; 6 has left arrow to 5 below, right arrow to 7 below
  - Notice that we now visualize this data structure in two dimensions (even though the nodes in memory can be at any location).
  - And we can implement this with a more complex version of a node in a linked list, where each node has not one but two pointers to other nodes. All the values to the left of a node are smaller, and all the values of nodes to the right are greater, which allows this to be used as a binary search tree. And the data structure is itself defined recursively, so we can use recursive functions to work with it.
  - Each node has at most two children, or nodes it is pointing to.
  - And like a linked list, we’ll want to keep a pointer to just the beginning of the list, but in this case we want to point to the root, or top center node of the tree (the 4).

# More data structures
- A data structure with almost a constant time, O(1) search is a hash table, which is essentially an array of linked lists. Each linked list in the array has elements of a certain category.
  - This is called a hash table because we use a hash function, which takes some input and deterministically maps it to the location it should go in. In our example, the hash function just returns an index corresponding to the first letter of the name, such as 0 for “Albus” and 25 for “Zacharias”.
  - It turns out that the worst case running time for a hash table is O(n), since, as n gets very large, each bucket will have on the order of n values, even if we have hundreds or thousands of buckets. In practice, though, our running time will be faster since we’re dividing our values into multiple buckets.
- There are even higher-level constructs, abstract data structures, where we use our building blocks of arrays, linked lists, hash tables, and tries to implement a solution to some problem.
  - For example, one abstract data structure is a queue, like a line of people waiting, where the first value we put in are the first values that are removed, or first-in-first-out (FIFO). To add a value we enqueue it, and to remove a value we dequeue it. This data structure is abstract because it’s an idea that we can implement in different ways: with an array that we resize as we add and remove items, or with a linked list where we append values to the end.
- An “opposite” data structure would be a stack, where items most recently added are removed first: last-in-first-out (LIFO). At a clothing store, we might take, or pop, the top sweater from a stack, and new sweaters would be added, or pushed, to the top as well.
- Another example of an abstract data structure is a dictionary, where we can map keys to values, such as words to their definitions. We can implement one with a hash table or an array, taking into account the tradeoff between time and space.
