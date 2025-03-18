# Intro to Data Structures
Data structures are specialized formats for organizing, processing, retrieving, and storing data efficiently.

They are fundamental building blocks in computer programming, defining `how data is organized, stored, and manipulated within a program, during the execution time`.

Different types of data structures are suited to different kinds of applications and tasks

## Table of Contents
- [Categories of Data Structures](#categories-of-data-structures)
- [Arrangements of data](#arrangements-of-data)
- [Static vs Dynamic memory](#static-vs-dynamic-memory)
- [Data type](#data-type)
- [ADT: Abstract Data Type](#abstract-data-type)
- [Time & Space complexity](#time-and-space-complexity)

## Categories of data structures
Data structures can be divided in two categories:

- **Physical Data Structure**: define how the data is arranged inside the memory.  It deals with how data is stored, accessed, and managed at the hardware level. Examples includes:
    - **Arrays**: contiguous memory allocation. Can be allocated on Stack or Heap
    - **Linked Lists**: nodes with data and pointers to memory addresses. Always created in Heap.

- **Logical Data Structure**: define the data arrangement and how should be utilized. Examples include:
    - **Linear Data Structures**:
        - **Stacks**: LIFO (Last-In-First-Out)
        - **Queues**: FIFO (First-In-First-Out)
    - **Non-linear Data Structure**:
        - **Trees**: hierarchical relationships 
        - **Graphs**: nodes and edges
    - **Tabular Data Structure**:
        - **Hash Table**: stores data in key-value pairs

> Any logical data structure is implemented using physical data structures, either array or linked-list or a combination of the two

## Arrangements of data
Depending on where data is kept, how it is organized and what is the use of it, there are different arrangments that define its means:

- **Data Structures**: These are arrangements of data items that facilitate efficient operations in main memory from a program (instruction set). Examples include: **arrays**, **linked lists**, **trees**, and **hash tables**.

- **Databases**: Organized collections of data stored on disk, which applications can access by loading data into memory. (operational data, used daily)

- **Data Warehouses**: Large repositories of historical data meant for analysis rather than active use. (legacy/historical data, helpful for analysis, trends, dealing with customers...). Algorithms for analyzing this type of data are called **Data Mining** Algorithms

- **Big Data**: Refers to the enormous volumes of data generated online, which can be analyzed for various business and management applications.


## Static vs Dynamic memory
- **Structure**: memory is organized into addressable units known as bytes and is arranged in a linear manner.

![memory structure](/assets/memory-structure.png)

- **Segments**: Programs utilize main memory, which is divided into three primary sections:
    - **code section** where machine code resides
    - **stack** used for storing local variables
    - **heap** for dynamic memory allocation
- **STACK (static)**: a linear data structure that follows the Last In First Out (LIFO) or First In Last Out (FILO) principle
- **HEAP (dynamic)**: a tree-based data structure



---
### Static memory allocation
- **Fixed size**: Memory is allocated at compile-time, and the size is fixed.
- **Stack-based**: Memory is allocated from the stack, which is a region of memory that stores local variables and function calls.
- **Limited size**: The amount of memory available is limited by the stack size, which can lead to stack overflow errors if not managed properly.

![stack](/assets/stack-1.png)

In this simple example, the program is loaded into the main memory (RAM) and the variables `a` and `b` are allocated on the stack. They are loaded in the fragment called **activation record** of the main function.

In the next example, the main function allocates 2 variables and calls the function `func1()` that allocates a variable and then calls `func2()`.

![stack](/assets/stack-2.png)

The step by step process would be:
1. main function is executed: allocates variables and calls `func1()`
2. `func1()` allocates variable `a` and calls `func2()`
3. once `func2()` is finished, its activation record is deallocated and control is returned to `func1()`
4. once `func1()` is finished, its activation record is deallocated and control is returned to function `main()`
---
### Dynamic Memory Allocation
- **Variable size**: Memory is allocated at runtime, and the size can vary.
- **Heap-based**: Memory is allocated from the heap, which is a region of memory that stores dynamically allocated variables.
- **Flexible size**: The amount of memory available is flexible and can be increased or decreased as needed.

In this example an array is created dynamically and allocated on the **heap** memory.

![heap](/assets/heap.png)

- The address of `p` is equal to the base address of the array.
- each element of the array can be accessed through their index by adding the index to the base address.

## Data Type
- **Datatype** 
    - Representation of data
    - Operation on data

A data type represents the nature and type of data, describing the representation, interpretation, and structure of values or objects stored in computer memory

>A data type is an attribute of data that specifies the type of value a variable can hold and the operations that can be performed on it without causing an error

### Integer data type (primitive datatype)
Example: assume an integer in C/C++ takes 2-bytes, the first bit is reserved for the sign bit and the remaining 15 bits for data.

**Representation**:
The following image illustrate the representation of an integer type.

![integer-representation](/assets/integer-type.png)

**Operations**:
some of the operations allowed:
- addition (`+`)
- subtraction (`-`)
- multiplication (`*`)
- division (`/`)
- modulus (`%`)
- pre/post-increment (`++`, `--`)

## Abstract Data Type
A concept that defines a class of objects and the operations that can be performed on them, along with their expected behavior, but without specifying implementation details.

### ADT: List
A list is a collection of elements
```
List -> 0, 1, 9, 3, 43, 5, 6, 34
```
**DATA**:
Requirements to represent the data type
1. space for storing elements (array or linked-list)
2. capacity
3. size

**OPERATIONS**:
Some operations that can be performed
- **add(*x*)**: add *x* to the end of the list
- **insert(index, *x*)**: shift all other elements to **the right** of the index and insert the element.
- **remove(index)**: remove the element at index and shift all elements after the index to **the left**
- **replace(index, *x*)**: replace the element at index with *x*
- **get(index)**: return the element at index
- **search(*key*)**: return the index of the element (if found)
- **sort()**

The next step to make this a data type is to pack the data and the operations inside a class (C++). This operation will give an abstract data type, since the details of the implementation are unknown.

### Summary
The concept of ADT is: define the data and the operations on data together, and make available to use as a data type (class), without knowing the internal details.


## Time and Space complexity
Time complexity and space complexity are fundamental concepts in computer science used to evaluate the efficiency of algorithms. Time complexity measures the execution time of an algorithm relative to the input size, while space complexity measures the memory usage of an algorithm relative to the input size

>Time complexity is a measure of how the execution time of an algorithm scales with the input size

>Space complexity evaluates how much memory space an algorithm requires relative to the input size
---
### Order of n
The time complexity is defined by the polinomial degree.

Using a **linear search algorithm**, we have to go through each element (worst case) and compare it with the element we are looking for. This is also represented by the `Order of n` or $O(n)$, where n is the number of elements.

The complexity can be determined based on the procedure or by analyzing the code.
- **procedure**
    ```
    Array:  |2|5|9|7|6|13|8| (7 elements)
    O(n) -> O(7)
    ```
- **code**:
The implementation of a linear algorithm in `c` language

    ```c
    int arr[7] = {2,5,9,7,6,13,8};
    for (int i = 0; i < 7; ++i)
        if (arr[i] == 8)
            ...
    ```
We can observe that:
- the for loop will proceed until the end (i = n)
- it will search the entire array and compare if the current element is equal to 8
- the complexity is `O(7)` where 7 is the length of the array (worst case)

---

### Order of ${n^2}$ (quadratic)
An algorithm with a time complexity of O(n<sup>2</sup>) is said to have quadratic time complexity. This means that the runtime of an algorithm scales quadratically with the size of the input (size=10, runtime=100 steps)

- **procedure**
    ```
    Array:  |2|5|9|7|6|13|8| (7 elements)
    O(n2) -> O(49)
    ```

- **code**:
The implementation of a quadratic algorithm in `c` language

    ```c
    for (int i = 0; i < n - 1; ++i){
        for (int j = i + 1; j < n; ++j){
            ...
        }
    }
    ```
We can observe that:
- the loop proceeds until the end (j = n, i = n - 1)
- the loop process the array 2 times
- in the worst case the complexity is O(n<sup>2</sup>)

**Polinomial degree**: $\frac{n(n-1)}{2} = n^{2}$
- this is because the array is traversed 2 times by the nested loops

### Binary search (log n)
Binary search is an algorithm that operates with a time complexity of O(log n) in both average and worst-case scenarios. This efficiency is due to its divide-and-conquer approach, where the search range is halved with each comparison.

- **procedure**
    ```
    Array:  |2|5|9|7|6|13|8| (7 elements)
    O(log n)
    ```
- **code**:
The implementation of the binary search algorithm in `c` language

    ```c
    for (int i = n; i > 1; i = i / 2)
        ...
    ```
    We can observe that:
    - the index `i` is halved every iteration

**Polinomial degree**: $\frac{log(n)}{2} = log_{2}n$
- `i = n` -> $log(n)$
- `i = i/2` -> $log_{2}n$

### Examples
- $O(n^0)$:
    ```c
    void swap(int x, int y){
        int temp;

        temp = x;   // 1 unit of time
        x = y;      // 1 unit of time
        y = temp;   // 1 unit of time
    }
    ```
    - **Time function**: $f(n) = 3$ (units of time)
    - **Order/Degree**: $O(1)$ because $3n^0 = 1$

- $O(n)$:
    ```c
    int sum(int A[], int n){
        int s,i;
        s = 0;                      // 1 unit of time
        for (i = 0; i < n; ++i){    // n + 1 units
            s = s + A[i];           // n units
        }
        return s;                   // 1  unit of time
    }
    ```
    1. assignment `s = 0`: executed 1 time (takes 1 unit of time)
    2. loop header:
        - `i = 0`: executed 1 time
        - `i < n`: executed $n + 1$ times (+1 because it will be checked the final time when `i = n`)
        - `++i`: executed n times
        - **total time** taken is: $n + 1$
    3. assignment:
        - `s = s + A[i]`: executed $n$ times
    4. `return s`: executed 1 time
    - **Time function**: $f(n) = 2n + 3$
    - **Order/Degree**: $O(n)$

- $O(n^2)$:
    ```c
    void add(int n){
        int i,j;
        for (i = 0; i < n; ++i)                 // n + 1
            for (j = 0; j < n; ++j)             // n * (n + 1)
                C[i][j] = A[i][j] + B[i][j];    // n * n
    }
    ```
    1. outer loop (i):
        - `condition checks`: $n + 1$
        - `increments`: $n$
        - **Total**: $2n + 1$
    2. inner loop (j):
        - `condition checks`: $n(n + 1)$
        - **Total**: $n^2 + n$
    3. assignment:
        - `C[i][j] = A[i][j] + B[i][j]`: $n^2$
    - **Time function**: $f(n) = 2n^2 + 2n + 1$
    - **Order/Degree**: $O(n^2)$