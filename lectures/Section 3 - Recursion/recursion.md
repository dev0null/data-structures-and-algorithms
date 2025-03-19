# Recursion - Introduction
Recursion is a technique where a function calls itself repeatedly to solve a problem by breaking it down into smaller, similar subproblems.

>A function must have a condition that stops the recursive calls to prevent infinite loops and stack overflow errors

Recursion uses the LIFO principle, similar to the stack data structure, where **each recursive call creates a new stack frame** that stores information about local variables, formal parameters, and the return address

- code is **more readable and easier to understand**, especially for problems involving tree or graph structures.
- **reduce code duplication** and break them down into smaller, more manageable subproblems.

>NOTE: recursion can have higher performance overhead compared to iteration because each recursive call creates a new stack frame, which consumes additional memory and CPU resources

## Table of Contents
- [Tracing](#tracing)
- [Recursion Phases](#recursion-phases)
- [Space Complexity](#space-complexity)
- [Time Complexity](#time-complexity)
- [Static/Global variables](#static-variables-in-recursion)
- [Types of Recursion](#types-of-recursion)

Algorithms:
- [Recursive algorithms](./recursive-algorithms.md)

## Tracing
Tracing recursive functions involves understanding how the function calls itself and how each call interacts with the previous ones.

Recursive functions are traced in the form of a `tree`

### Example program
Taking as an example this simple C program, the function calls itself with the input `n` decreased by 1 each call `func(n - 1)`, until the condition/base case fail and return control to the previous call.

```c
void func(int n){
    if (n > 0){                 // condition or base case
        printf("%i\n", n);
        func(n - 1);            // recursion call
    }
}

int main(){
    func(3);
}
```
*Refer to the image below for a visual representation of the working tree or tracing tree of the program.*

![](/assets/recursion-tracing-tree.png)
1. print *n*
2. recursive call

## Recursion Phases
Recursion involves two main phases:
- the **calling**/**winding** phase:
    - starts when the recursive function is called for the first time and continues until the termination condition is met, during which the function calls itself repeatedly.
- the **returning**/**unwinding** phase:
    - Once the termination condition is reached, the returning phase begins
    - during this phase, the function calls start returning in **reverse order** until the initial call returns control to the function that initiated the recursion.

>Summary: The calling phase involves the function making deeper and deeper calls to itself, while the returning phase involves the function returning control back up the call stack

### Example program
This is similar to the program above but with one notable difference. The function `func()` is called **before** the printing statement, leading to a different output.

In this example, the function `func()` calls itself until the termination condition is met and returns back the control to the call stack (line were the recursion occurred), then execute the print statements.
```c
void func(int n){
    if (n > 0) {
        func(n-1);          // recursion
        printf("%i\n", n);
    }
}

int main(){
    func(3);
}
```
*Refer to the image below for a visual representation of the working tree or tracing tree of the program.*
![](/assets/recursion-tracing-tree-2.png)
1. recursive call
2. print *n*

### Recursion vs Loops (Phases)
**Recursion** has two phases:
1. **ascending** or calling/winding
2. **descending** or returning/unwinding

**Loops** only have the ascending phase (linear)

```C
void func(int n){
    if (n > 0){
        ...         // Calling phase    /   Ascending
        func(n-1);
        ...         // Returning phase  /   Descending
    }
}
```

---

## Space Complexity
Space complexity in recursive algorithms is determined by the maximum depth of the recursion stack.

The memory used by recursive functions correlates with the number of calls made, represented as $O(n)$ space complexity.

In this example the function is passed an integer `n` = 3, that is decreased by 1 each call. `func()` will be called 4 times ($n + 1$) so there will be a total of 4 activation records on the stack.

![](/assets/recursion-tracing-tree.png)

- **Polinomial formula**: $n + 1$
- **Order/Degree**: $O(n)$

---

## Time Complexity
The time complexity of a recursive function **depends on the structure and design of the algorithm**. In general, there are two main factors that determine the time complexity:

1. **The number of recursion calls**: this is directly related to **how many times the function calls itself** before reaching the base case.

    If a recursive function makes $n$ recursive calls and each call takes constant time, then the overall time complexity would be $O(n)$.

2. **The depth of recursion**: this refers to the maximum **number of levels in the recursion tree**. If the depth of recursion is logarithmic (i.e., it halves at every level), then the time complexity would be $O(\log n)$ or better, which are considered efficient complexities for many problems.

The best way to determine the time complexity is by analyzing the structure and design of the algorithm, counting the number of operations at each level of recursion, and then determining the dominant term in the resulting big O notation.

### Time Complexity Analysis
>**NOTE**: For this case we assume that every statement takes 1 unit of time ($n$).

To analyze the time complexity of this code, we need to count the number of operations (statements) at each level of recursion.

```c
void func(int n){
    if (n > 0){                 
        printf("%i\n", n);      // 1 unit of time (n)
        func(n - 1);            // 1 unit of time (n)
    }
}

int main(){
    func(3);
}
```
Since this is a recursive function with base case `(n > 0)`, the function will be called until it reaches the base case, which means that there are $\boldsymbol{n}$ recursive calls in total when calling `func(n)`.

Each call takes constant time (1 unit of time), so the overall time complexity for these recursive calls is $O(n)$.

![](/assets/recursion-tracing-tree-time-complexity.png)

- **Order/Degree**: $O(n)$, where `n` is the input of the function


### Time Complexity Analysis via Recurrence Relation  
To determine the time complexity $ T(n) $ of the function `func()`, we assume:  
- The function call `func(n)` takes $ T(n) $ time.  
- Each non-recursive statement (e.g., the `if` check and `printf`) takes **1 unit** of time.  
- The recursive call `func(n - 1)` contributes $ T(n-1) $ time.  

**Code Breakdown**:  
```c  
void func(int n) {  
    if (n > 0) {          // 1 unit  
        printf("%i", n);  // 1 unit  
        func(n - 1);      // T(n - 1)  
    }  
}  
```  

**Recurrence Relation Derivation**:  
The total time $ T(n) $ is the sum of the non-recursive operations and the recursive call:  
$$  
T(n) = \underbrace{1 \ (\text{if-check}) + 1 \ (\text{printf})}_{\text{2 units}} + T(n-1)  
$$  
Simplifying:  
$$  
T(n) = T(n - 1) + 2  
$$  

**Formal Recurrence Relation**:  
$$
T(n) = 
\begin{cases} 
1 & \text{if } n = 0 \quad (\text{base case, no operations}) \\
T(n - 1) + 2 & \text{if } n > 0  
\end{cases}  
$$  

### - Conclusion -
The time complexity is $ T(n) = 2n + 1 $, which simplifies to $ \mathcal{O}(n) $.

---

## Static Variables in Recursion
This example demonstrates how a static variable behaves in a recursive function. Unlike local variables, **static variables retain their values between function calls**, leading to unique behavior in recursive contexts.

```c
int fun(int n){
    static int x = 0;       // Static variable: initialized ONCE and persists across calls
    if (n > 0){
        x++;                // Increments x in every recursive call
        return fun(n-1) + x;
    }
    return 0;
}

int main(){
    int a = 5;
    printf("%d ", fun(a));  // Output: 25
}
```
1. **Static Variable Behavior**:  
   - `x` is initialized **once** at program startup, not reinitialized on subsequent calls.  
   - All recursive calls to `fun()` share the **same** `x` variable.  
   - `x` acts like a "global" variable but is scoped to `fun()`.  

2. **Recursion Workflow**:  
   - During the **winding phase** (recursive calls):  
     - `x` increments from `0` to `5` as `n` decreases from `5` to `0`.  
   - During the **unwinding phase** (returns):  
     - Each recursive return adds the **final value of `x` (5)** to the result.  

- Tracing the recursion:
    Assume `n = 5`:  
    1. **Winding Phase**:  
        ```
        fun(5) → x = 1 → calls fun(4)  
        fun(4) → x = 2 → calls fun(3)  
        fun(3) → x = 3 → calls fun(2)  
        fun(2) → x = 4 → calls fun(1)  
        fun(1) → x = 5 → calls fun(0)  
        fun(0) → returns 0  
        ```  
    2. **Unwinding Phase**:  
        ```
        fun(1) returns 0 + 5 = 5  
        fun(2) returns 5 + 5 = 10  
        fun(3) returns 10 + 5 = 15  
        fun(4) returns 15 + 5 = 20  
        fun(5) returns 20 + 5 = 25  
        ```  
    **Final Output**: `25`

Refer to the diagrams below for a visual breakdown of the recursion and memory allocation:
*The tree shows how `x` increments during the winding phase and how the final value of `x` propagates during unwinding.*

![recursion-static](/assets/recursion-static-tree.png)
![recursion-static](/assets/recursion-static-diagram.png)

---

## Types of Recursion
- [Tail Recursion](#tail-recursion): The recursive call is the last operation in the function (no pending operations after the call).
- [Head Recursion](#head-recursion): The function performs operations after the recursive call.
- [Tree Recursion](#tree-recursion): The function makes multiple recursive calls per invocation, creating a tree-like call stack.
- [Indirect/Mutual Recursion](#indirect-recursion): Two or more functions call each other in a cycle.
- [Nested Recursion](#nested-recursion): The recursive call uses the function itself as a parameter.
---
### Tail Recursion
Tail recursion is a type of recursive function where **the recursive call is the last action** performed by the function.

In functional programming languages, tail recursion can be seen as the "counterpart to iteration", as it can be translated into an equivalent loop in an imperative language.

Tail recursion can be optimized by the compiler to use **constant stack space**, unlike non-tail recursive functions which require additional stack space for each recursive call.

#### Example tail recursion function
```c
void func(int n){
    if (n > 0){
        printf("%i\n", n);  // performed at calling time (winding)
        func(n - 1);        // recursive call performed last
    }
}
```
- **Time**: $O(n)$
- **Space**: $O(n)$, allocate as many activation records as $n$

>Every previous statement to the recursive call is executed at calling time/winding phase

#### - Tail Recursion vs Loop comparison -
Tail recursion can easily be converted in the form of a loop. Most compilers will try to optimize space consumption and convert tail recursions into a loop.

The following is the **iterative version** of the previous tail recursion code:
```c
void fun(int n){
    while (n > 0){
        printf("%i\n", n);
        n--;
    }
}
```
- **Time**: $O(n)$
- **Space**: $O(1)$, only one activation record is allocated

#### - Conclusion -
In this case, tail recursion and loops have the same time complexity, but worse space optimization.
Instead of using recursion, it is better to convert it into a loop to improve efficiency.

---

### Head Recursion
In a head recursive function, the recursive call is the **first statement** in the function. There are no operations before the call.

The time complexity of head recursion is $O(n)$, and the space complexity is also $O(n)$ because each recursive call adds a new stack frame to the call stack.

In contrast to tail recursion, where the recursive call is the last statement in the function and can be optimized by some compilers to reduce space complexity to $O(1)$, head recursion does not offer such optimization, leading to potential memory inefficiency for deep recursion.

```C
void func(int n){
    if (n > 0){
        func(n - 1);        // recursive call performed first
        printf("%i\n", n);  // performed at returning time (unwinding)
    }
}
```
- **Time**: $O(n)$
- **Space**: $O(n)$, allocate as many activation records as $n$
- **Output**: fun(3) -> 1 2 3

>Every subsequent statement to the recursive call is executed at returning time/unwinding phase

#### - Head Recursion vs Loop comparison -
Head recursion can be compared to a loop, but converting it is not always straightforward and may require additional logic.

Unlike Tail Recursion, Head Recursion in this case need a second variable to hold a numeric ascending value in order to have the same output.
```c
void fun(int n){
    int i = 1;
    while (i <= n){
        printf("%i\n", n);
        i++;
    }
}
```
- **Time**: $O(n)$
- **Space**: $O(1)$, only one activation record is allocated
- **Output**: fun(3) -> 1 2 3

#### - Conclusion -
Head recursion can be converted to a loop, but it will not be as simple as converting a tail recursion.

---

### Tree Recursion
Tree recursion is a type of recursion where a function **calls itself more than once in a single execution** step.

In tree recursion, each call can lead to multiple recursive calls, creating a tree-like structure of function calls.

This method is useful for solving problems that can be broken down into smaller subproblems, such as certain types of algorithm analysis and mathematical computations (fibonacci).

```c
void fun(int n){
    if (n > 0){
        printf("%d", n);
        fun(n-1);
        fun(n-1);
    }
}
```
- **Time Complexity**: $O(2^n)$
    - Representing the recursion tree in levels, we count the total number of calls for each level:
        ```
        Level 1 ->  1 call
        Level 2 ->  2 calls
        Level 3 ->  4 calls
        Level 4 ->  8 calls
        ```
    - **Formula**: $2^{n+1}-1$
        - **Total calls**: 1 + 2 + 4 + 8 = 15

            This expression can also be simplified as: $2^0 + 2^1 + 2^2 + 2^3$
- **Space Complexity**: $O(n)$ - space is equal to the number of levels the tree has. 
- **Output**: 3 2 1 1 2 1 1

    Refer to the diagrams below for a visual breakdown of the recursion tree:
*The tree shows the sequence in which calls are made and illustrate the levels or depth of the tree for this function*

    ![](/assets/recursion-type-tree.png)

---

### Indirect Recursion
Indirect recursion, also known as mutual recursion, happens when a function calls another function, which in turn calls the first function again, creating a **cyclic dependency between the functions**.

This technique is useful for solving complex problems that cannot be effectively handled by a single function alone.

>The recursion ends when the base case is met, at which point the process stops

```c
void fun_A(int n){
    if (n > 0){
        printf("%i", n);
        fun_B(n-1);
    }
}
void fun_B(int n){
    if (n > 1){
        printf("%i", n);
        fun_A(n/2);
    }
}
```
- **Time Complexity**: $O(\log n)$
    <details>
        <summary>Step-by-Step Explanation</summary>

    1. **Recursive Calls Analysis**:
        - `fun_A(n)` calls `fun_B(n-1)`.
        - `fun_B(n)` calls `fun_A(n/2)` (using integer division).

    2. **Recurrence Relations**:
        - Let $ T_A(n) $ denote the time for `fun_A(n)`.
        - Let $ T_B(n) $ denote the time for `fun_B(n)`.
        - The recurrences are:
            $$
            T_A(n) = O(1) + T_B(n-1) \quad \text{(for } n > 0\text{)}
            $$
            $$
            T_B(n) = O(1) + T_A(n/2) \quad \text{(for } n > 1\text{)}
            $$
        - Base cases: $ T_A(n) = O(1) $ for $ n \leq 0 $, $ T_B(n) = O(1) $ for $ n \leq 1 $.

    3. **Simplifying the Recurrences**:
        - Substitute $ T_B(n-1) $ into $ T_A(n) $:
            $$
            T_A(n) = O(1) + O(1) + T_A\left(\frac{n-1}{2}\right) \quad \text{(for } n > 2\text{)}
            $$
        - This simplifies to:
            $$
            T_A(n) = T_A\left(\frac{n}{2}\right) + O(1) \quad \text{(asymptotically, ignoring constants)}.
            $$

    4. **Solving the Recurrence**:
        - The recurrence $ T(n) = T(n/2) + O(1) $ has a solution of $ O(\log n) $ by the Master Theorem (case 2 for decreasing functions).

    5. **Conclusion**:
        - Each recursive step reduces $ n $ by approximately half, leading to $ \log n $ steps. Each step involves $ O(1) $ work (prints and checks), resulting in a total time complexity of **O(log n)**.
    </details>

- **Space Complexity**: $O(\log n)$
    <details>
        <summary>Step-by-Step Explanation</summary>

    1. **Call Stack Mechanism**:
        - Each recursive call (either to `fun_A` or `fun_B`) adds a new frame to the call stack.
        - The space complexity is determined by the **maximum depth** of the call stack during execution.

    2. **Parameter Reduction Pattern**:
        - Starting with `fun_A(n)`, the sequence of parameters evolves as follows:
            ```
            n → n-1 → (n-1)/2 → ((n-1)/2)-1 → ... (until termination)
            ```
        - Each step reduces the parameter by roughly **half** (ignoring constants due to integer division and subtraction).

    3. **Recursive Depth Analysis**:
        - For a given `n`, the recursion alternates between `fun_A` and `fun_B`, reducing `n` by approximately a factor of 2 every two steps.
        - Example for `n = 8`:
            ```
            fun_A(8) → fun_B(7) → fun_A(3) → fun_B(2) → fun_A(1) → fun_B(0)
            ```
            The call stack depth is **6**, which is proportional to **2 × log₂(8) = 6**.

    4. **General Case**:
        - The recursion terminates when `n` reaches `≤ 0` or `≤ 1`.
        - The number of steps (and stack depth) is proportional to **O(log n)**, as each pair of calls (`A → B` or `B → A`) reduces `n` by roughly half.

    5. **Conclusion**:
        - Despite alternating between two functions, the parameter `n` decreases exponentially, leading to a logarithmic number of stack frames. Constants (e.g., doubling the depth for alternating calls) are asymptotically irrelevant in Big O notation.
    </details>

![](/assets/recursion-type-indirect.png)

---

### Nested Recursion
Nested recursion is a form of recursion where a recursive function makes a **recursive call with a parameter that is itself a recursive call**. This can lead to complex behavior and is less common than direct or indirect recursion because it involves multiple layers of recursion, making the flow of execution more intricate.

Nested recursion can be used in complex mathematical problems or algorithms where the solution to a problem depends on the solution to another recursive call.

```c
int fun(int n){
    if (n > 100)
        return n - 10;
    else
        return fun(fun(n + 11));
}
fun(95);
```
The given function `fun(n)` is an implementation of the McCarthy 91 function, which recursively computes 91 for all inputs $ n \leq 100 $ and $ n - 10 $ otherwise.

- **Time Complexity**: $ O(1) $, as the number of operations does not scale with input size
    - **Explanation**: Each call to `fun(n)` for $ n \leq 100 $ triggers two nested recursive calls: one to `fun(n + 11)` and another to `fun(result)`. For `fun(95)`, the recursion chain progresses from 95 to 100, with each step involving a fixed number of operations. The total number of function calls made is **13**, which is a constant.

- **Space Complexity**: $ O(1) $, as the stack depth is constant and does not depend on input size.
    - **Explanation**: The space complexity is determined by the maximum depth of the call stack. During the execution of `fun(95)`, the deepest stack occurs when the recursion reaches `fun(111)` (from `fun(100)`), resulting in a maximum stack depth of **7**.

![](/assets/recursion-type-nested.png)