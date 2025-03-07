## C/C++ Essential Concepts
The following are the needed topics to learn, analyze and create data structures in c/c++

## Table of Contents
- [Arrays](#arrays)
- [Struct](#structures)
- [Pointers](#pointers)
- [References](#references) (C++)
- [Functions](#functions)
- [Class and Constructors](#class-and-constructors-c)
- [Monolithic vs Modular programming](#monolithic-vs-modular-programming)

## Arrays
Collection of similar data items stored in contiguous memory locations.

Arrays in C are used to store a fixed-size sequential collection of elements of the same data type.

Array declaration in `C`:
```C
// C
int array[5] = {15,22,31,4,25};                 // Stack 
int *array = (int*)malloc(size * sizeof(int));  // Heap - dynamically allocated
free(array);                                    // free allocated memory
```
Array declaration in `C++`:
```C++
// C++
int array[5] = {15,22,31,4,25};     // Stack 
int* arr = new int[size];           // Heap - dynamically allocated
delete []array;                     // free allocated memory
```

## Structures
Collection of data members, related to each other, accessible under one name (structure name). These data can be of similar or different types.

The **size** of a structure is determined by the total amount of its members size.

### Definition, Declaration and Initialization of a structure
```C
// Definition
typedef struct Rectangle {
    int length;     // 4-bytes
    int breadth;    // 4-bytes
    char n;         // 1-byte
} Rectangle;
...
// Declaration and Initialization
Rectangle rect;
rect.breadth = 5;

Rectangle rect = {5, 8};
```
- **STRUCTURE SIZE**: even tho the answer might seem easy (9-bytes), the compiler will allocate 4 bytes for the `char` (alignment) but will only use 1-byte. So the correct answer is **12-bytes**. This is beacuse of the memory alignment also called `data structure padding`.
- After n (byte 8), the compiler adds 3 padding bytes (bytes 9–11) to ensure the total ***struct size is a multiple of the largest member alignment*** (4 bytes for int).


### Structure examples:
1. **Complex number**: A complex number is an expression of the form a+bi, where a and b are real numbers, and i is the imaginary unit, defined as the square root of −1
    ```c
    struct complex_number {
        int real;
        int imaginary_unit;
    };
    ```
    - **STRUCTURE SIZE**: 8-bytes, assuming `int` size is 4-bytes.

2. **student**: a structure that represent a student.
    ```c
    struct student {
        int roll;
        char name[25];
        char dept[10];      // COMP (Computer Science), etc
        char address[50];
    };
    ```
    - **STRUCTURE SIZE**: 92-bytes (aligned, multiple of the largest member in the struct) instead of 89-bytes, assuming `char` 1-byte and `int` 4-bytes

3. **poker card**: a playing card have
    - a `face value` 1 to 13 (1=ace, ... 13=K)
    - a `shape` 0 to 4 (0-club, 1-spade, 2-diamonds, 3-hearts)
    - a `color` 0 for black, 1 for red
    ```c
    struct Card {
        int face;
        int shape;
        int color;
    };
    ```
     - **STRUCTURE SIZE**: 12-bytes, assuming `int` 4-bytes

## Pointers
A pointer is a variable whose value is the address of another variable of the same type.

```c
int a = 10;
int *p = &a;            // Address of 'a' in stack
printf("%d", *p);       // dereferencing pointer (get access to its value)
```

The reasons for using pointers are:
- Indirect access of **Heap** memory
- Accessing resources: keyboard, files, monitor etc
- Parameter passing

Some data is stored on the heap for several reasons:
- **Dynamic Allocation**: When the size of the data is not known until runtime, heap allocation allows for flexible memory management. For example, reading a file of unknown size would require dynamic allocation since the file size could vary significantly.
- **Longer Lifetime**: Data on the heap can outlive the function that created it, making it suitable for objects that need to persist beyond the scope of a single function.
- **Large Data Structures**: The heap provides more memory compared to the stack, which is typically limited to a few megabytes. This makes it ideal for handling large arrays, structures, or classes.
- **Flexibility in Size and Number of Objects**: The heap allows for the creation of objects whose size is only known at runtime and for managing a variable number of objects, such as in complex data structures like binary trees or linked lists.
- **Avoiding Stack Overflow**: Using the heap prevents stack overflow issues that can occur when the stack limit is exceeded due to deep recursion or large local variables.￼
- **Persistence Across Function Calls**: Data allocated on the heap remains accessible as long as there is a pointer to it, even after the function that allocated it has returned.
- **Thread-Safe Allocation**: In multi-threaded environments, heap allocation is necessary because each thread has its own stack, and shared data needs to be managed in a way that is accessible across threads.

- **TLDR**:
    - large data, dynamic allocation, persistence



### Examples
- **Accessing data on Heap**:
    ```c
    // C
    int *p;                                 // make a pointer and store on the STACK
    p = (int*)malloc(size * sizeof(int));   // allocate memory on the HEAP
    free(p);                                // free allocated memory

    // C++
    int *p = nullptr;
    p = new int[size];
    delete []p;
    ```
    - through the pointer (on stack) we have now access to the memory allocated on the **heap**

### Pointers to structures
Pointers can point to structures on stack and heap as every other types.

#### 1. Structure allocated on STACK:
```C
Rectangle rect = {10,5};
Rectangle *ptr = &rect;   // pointer to rect structure
```
- **Accessing structures on Stack**:
    
    ```C
    // Variable
    rect.breadth = 0;          // dot operator
    rect.length = 0;           // dot operator

    // pointer
    (*ptr).breadth = 20;        // dereference
    ptr->length = 20;           // arrow operator
    ```
    - **variable**: members of a struct can be accessed with the `dot` operator
    - **pointer**: members of a struct can be accessed with the `arrow` operator or by dereference

#### 2. Structure allocated on HEAP:
```c
struct Rectangle *ptr_heap;
ptr_heap = (Rectangle *)malloc(sizeof(Rectangle));
```
    
- **Accessing structures on Heap**:
    ```C
    (*ptr_heap).breadth = 20;        // dereference
    ptr_heap->length = 20;           // arrow operator
    ```
    - **pointer**: members of a struct can be accessed with the `arrow` operator or by dereference

## References
In C++, a reference is an alias for an existing variable, declared using the '&' operator, which allows for efficient parameter passing and modification without copying.

### Definition, Declaration and Initialization of a reference
Unlike pointers, once a reference is initialized, it cannot refer to a different object or set to null.

>A reference **MUST** be initialized at declaration.
```C++
int a = 10;
int &p = a; // Reference
```
- changes applied to either `p` or `a` will have effect on the value `10`

## Functions
In C/C++, a function is a block of code that performs a specific task and can be called from any part of the program.

>Functions are also called **procedures** (procedural programming)

```C++
int add(int a, int b){
    return a + b;
}
```
Functions are useful for encapsulating common operations in a single reusable block, ideally with a name that clearly describes what the function does.

**Terminology**:
- `Signature`: defines the input and output of functions, including the name of the function, its parameters, and the return type
- `Caller`: the function that invokes another function
- `Callee`: the function called by the caller
- `Actual parameters` or `arguments`: values passed from the function caller
- `Formal parameters`: parameters declared inside the function signature.

**BENEFITS**:
- **Reusability**: functions can be reused across the whole program or packed in libraries and used as external utilities.
- **Efficiency**: the code has to be written one time
- **Code readability**: makes the program more readable thanks to the separation of concerns
- **Mantainability**: having code split in modular pieces of code allow for an easier maintenance.

### Parameters Passing Methods
There are three methods for passing parameters:
- **Pass by Value**: a copy of the argument's value is made and passed to the function. Any changes made to the parameter inside the function do not affect the original argument.
    ```c
    void swap(int x, int y);    // signature
    swap(a, b);                 // invocation
    ```
    
- **Pass by Reference** (reference): the memory address of the argument is passed to the function. The function can then access and modify the original data directly.
    ```c++
    void swap(int& x, int& y);
    swap(a, b);
    ```
    - same syntax as call by value, only prepend ampersand to the formal parameters names
    - this method is only supported in C++
    - **copy the code of the function inside the function caller**, making the machine code monolithic but the source code is still procedural/modular
    - should be used for smaller functions

- **Pass by Address** (pointer): this is similar to pass by reference, but it explicitly involves passing the memory address of the argument. The function can then access and modify the original data through the pointers.

    ```c
    void swap(int *x, int *y);
    swap(&a, &b);
    ```
    - use when need to modify actual parameters without making a copy of the argument

### Array inside of Structures
Array inside of structures will be passed by value (copy), so passing the struct by value to a function and modify the array inside that function will not have effect on the original struct.
```c
typedef struct ArrayStruct {
    int arr[5];
    int size;
} ArrayStruct;
```

- Declaring and initializing the original `ArrayStruct` inside of main:
    ```c
    ArrayStruct array = {{2,4,6,8,10}, 5};
    ```
- Passing the **struct by value** to the function `array_struct`:
    ```c
    void array_struct(ArrayStruct arr){
    // Zero-out the copy of the array
    for (int i = 0; i < arr.size; ++i)
        arr.arr[i] = 0;
    }
    ```
    - struct passed by value, having an array inside (array can only be passed by address) but in this case it is passed by value so any change to the array will have no effect on the array of the original struct.
    - the **original** `ArrayStruct.arr` remains the same
    - the **copy** `ArrayStruct.arr` will be changed to 0
 

## Class and Constructors (C++)
In C++, a class is a blueprint for creating objects (a particular data structure), providing initial values for state (member variables or attributes), and implementations of behavior (member functions or methods).

```c++
class Rectangle {

    int m_length;
    int m_breadth;

public:
    // Constructor
    Rectangle(int _length, int _breadth)
        : m_length(_length), m_breadth(_breadth)
    {}

    int area(){
        return m_length * m_breadth;
    }

    void change_length(int n){
        m_length = n;
    }

};

int main(){

    Rectangle r(10, 5);
    int area = r.area();
    r.change_length(20);
    ...
}
```
### Template classes
In C++, a template class is a blueprint for generating classes based on parameters. It allows the creation of classes that can work with any data type, enhancing code reusability and reducing redundancy.

>Instead of creating the same class multiple time to work with different data types, we use generic types

```c++
template <class T>
class Calculator {
    T x;
    T y;
public:
    Calculator(T x, T y);
    T add();
    T sub();
};

template <class T>
Calculator<T>::Calculator(T x, T y) {
    this->x = x;
    this->y = y;
}

template <class T>
T Calculator<T>::add() {
    return x + y;
}

template <class T>
T Calculator<T>::sub() {
    return x - y;
}

int main(){
    Calculator<int> c_int(3,5);
    Calculator<float> c_float(3.5f, 5.0f);
    ...
}
```
---

## Monolithic vs Modular programming
**MONOLITHIC PROGRAM**:
A monolithic program, or monolithic application, is a type of software application that is `designed and built as a single and unified unit`, where all components are tightly coupled and deployed together

**Example of a monolithic program**:
```c++
#include <iostream>

using namespace std;
int main(){
    int length = 0, breadth = 0;

    cout << "Enter the Length and Breadth: ";
    cin >> length >> breadth;

    int area = length * breadth;
    int perim = 2 * (length + breadth);

    cout << "Area: " << area << "\nPerimeter: " << perim << std::endl;
    return 0;
}
```
---
**MODULAR PROGRAMMING**: software design technique that emphasizes `separating the functionality of a program into independent, interchangeable modules`, each containing everything necessary to execute only one aspect of the desired functionality.

>Processing of data is delegated to functions

**Example of a C-style modular program**:
The following program give the same results as the monolithic one but the code is now modular, more readable and scalable.
```c
#include <stdio.h>

typedef struct Rectangle {
    int length;
    int breadth;
} Rectangle;

int get_area(Rectangle r){
    return r.length * r.breadth;
}
int get_perimeter(Rectangle r){
    return 2 * (r.length + r.breadth);
}
void initialize(Rectangle *r, int l, int b){
    r->length = l;
    r->breadth = b;
}

int main(){
    Rectangle rect = {0,0};

    int l, b;
    printf("Enter the Length and Breadth: ");
    scanf("%i %i", &l, &b);
    initialize(&rect, l, b);

    int area = get_area(rect);
    int perim = get_perimeter(rect);

    printf("Area: %d \nPerimeter: %d\n", area, perim);
    return 0;
}
```

**Example of a C++-style (OOP) modular program**:
The following code is the exact same as the program above but 'converted' to pure C++ code.
```c++
#include <iostream>

using namespace std;

class Rectangle {
    int m_length;
    int m_breadth;    
public:
    Rectangle(int length, int breadth)
        : m_length(length), m_breadth(breadth){}

    int area(){
        return m_length * m_breadth;
    }
    int perimeter(){
        return 2 * (m_length + m_breadth);
    }
    // Accessor functions
    int get_length(){
        return m_length;
    }
    int get_breadth(){
        return m_breadth;
    }
    // Mutator functions
    void set_length(int n){
        m_length = n;
    }
    void set_breadth(int n){
        m_breadth = n;
    }
    ~Rectangle(){}
};

int main(){
    int l, b;

    cout << "Enter the Length and Breadth: ";
    cin >> l >> b;
    Rectangle r(l,b);

    int area = r.area();
    int perim = r.perimeter();

    cout << "Area: " << area << "\nPerimeter: " << perim << std::endl;
    return 0;
}
```