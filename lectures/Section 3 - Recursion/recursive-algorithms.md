# Recursive Algorithms
Recursive algorithms are a powerful technique used in computer science to solve complex problems by breaking them down into smaller, similar subproblems. These algorithms repeatedly **apply the same logic to these subproblems until they reach a base case**, which is a problem simple enough to be solved directly without further recursion.

#### A recursive algorithm consists of two main components
- **Base case**: This is the condition under which the recursion stops. It prevents infinite recursion and stack overflow errors.

- **Recursive step**: This involves calling the function itself to solve smaller instances of the same problem.

Recursive algorithms are widely used in various applications, including sorting (e.g., merge sort), tree traversal, and dynamic programming.

## Table of Contents
- [Sum of First 'N' Natural Numbers](#sum-of-first-n-natural-numbers)
- [Factorial of a number](#factorial-of-a-number)
- [Exponential](#exponential)
- [Taylor Series $e^x$](#taylor-series)
- [Fibonacci Series](#fibonacci-sequence)
- [Combination formula](#combination-formula)
- [Tower of Hanoi](#tower-of-hanoi)

## Sum of First N Natural Numbers
*Sum of n natural numbers* can be defined as a form of **arithmetic progression** where the sum of $n$ terms are arranged in a sequence with the first term being 1, $n$ being the number of terms along with the $n^{th}$ term.

Example:
```
1 + 2 + 3 + 4 + 5 + 6 + 7
1 + 2 + 3 + 4 + . . . + n
Sum(n) = 1 + 2 + 3 + ... + (n - 1) + n
Sum(n) = Sum(n-1) + n
```
The sum is equal to the sum of all terms up to $ n - 1 $ (recursive), then $ + n $ (constant):
- $n - 1$: recursive part of the equation
- $+ n$: the last term is added to $sum(n-1)$
- **Example**: 
    ```
    Sum(4) = (1 + 2 + 3) + 4
    Sum(n-1): 1 + 2 + 3 = 6

    for n -> 4
    Sum(4) = Sum(4-1) + 4
    ```

**Recurrence Relation**:
$$
Sum(n) = 
\begin{cases} 
0 & \quad n = 0 \\
Sum(n - 1) + n & \quad n > 0  
\end{cases}  
$$

Implementation of the algorithm:
```c
int sum(int n){
    if (n == 0)
        return 0;
    else
        return sum(n - 1) + n;
}
```
- **Time Complexity**: $O(n)$, 6 total calls for `sum(5)` -> $n + 1$ calls
- **Space Complexity**: $O(n)$, 6 stack frames are created for `sum(5)` -> $n + 1$

*Refer to the tracing tree for a visual representation of the function control flow*
  ![](/assets/recursion-sum-of-numbers.png)

### - Sum on N numbers using Direct Formula -
This formula is derived from the sum of an arithmetic progression where the first term is 1 and the common difference is 1.

$$
S(n) = \frac {n(n+1)}{2}
$$

This method is fast and efficient because the time complexity is constant and is related to the number of operations:
- **first operation**: $n + 1$: 
- **second operation**: $n * (n+1)$
- **third operation**: $n * (n+1) / 2$
- **Time Complexity**: $O(1)$ (constant time)
    - **Time function**: $O(3)$, 3 operations

Implementation in C code:
```c
int sum(int n){
    return n * (n + 1) / 2;
}
```

### - Sum on N numbers using Iteration -
Implementation of the algorithm using iteration:
```c
int sum(int n){
    int s = 0;                      // 1
    for (int i = 1; i <= n; ++i){   // n + 1
        s = s + i;                  // n
    }
    return s;                       // 1
}
```
- **Time Complexity**: $O(n)$
    1. **Initialization**: `s = 0` executed 1 time (takes 1 unit of time)
    2. **Loop header**:
        - `i = 1`: executed 1 time
        - `i <= n`: executed $n + 1$ times (+1 because it will be checked the final time when `i > n`)
        - `++i`: executed n times
        - **total time** taken is: $n + 1$
    3. **Loop body**:
        - `s = s + i`: executed $n$ times
    4. **Return statement**: `return s` (executed 1 time)
    - **Time function**: $f(n) = 2n + 3$
    - **Asymptotic Time Complexity**: $O(n)$
- **Space Complexity**: $O(1)$
    - The function uses a fixed number of integer variables (n, s, i), regardless of the input size.

### - Conclusion -
The recursive version of the algorithm is easier to code in a programming language but takes more space compared to the iterative version that is faster and more efficient.

See [complete code](./practice/sum-of-n.c) for this topic

---

## Factorial of a number
A factorial of a number n, denoted as $\boldsymbol{n!}$, is the product of all positive integers from 1 to $n$.

$$
\begin{align*}
n!      &= 1 * 2 * 3 * .... * n \\
fact(n) &= 1 * 2 * 3 * .... * (n - 1) \times n \\  
fact(n) &= fact(n - 1) \times n 
\end{align*}
$$

**Formal Recurrence Relation**:  
$$
fact(n) = 
\begin{cases} 
1 & \quad \quad n = 0 \\
fact(n-1) \times n & \quad \quad n > 0  
\end{cases}  
$$

Example: $$5! = 1 * 2 * 3 * 4 \times 5 = 120$$

### Factorial using recursion
Implementation of the recursive algorithm:
```c
int fact(int n){
    if (n <= 0)
        return 1;
    return fact(n - 1) * n;
}
```
- **NOTE**: the base case should never be `n == 0` because a negative input will lead to a Stack Overflow error, since the condition is never met and the input `n` is decremented every call.
- **Time Complexity**: $O(n)$, 6 total calls for `fact(5)` -> $n + 1$ calls
- **Space Complexity**: $O(n)$, 6 stack frames are created for for `fact(5)` -> $n + 1$

###  Factorial using Iteration
Implementation of the algorithm using iteration:
```c
int fact(int n){
    int f = 1;
    for (int i = 1; i <= n; ++i)
        f *= i;
    return f;
}
```
- **Time Complexity**: $O(n)$
    1. **Initialization**: `f = 1` executed 1 time (takes 1 unit of time)
    2. **Loop header**:
        - `i = 1`: executed 1 time
        - `i <= n`: executed $n + 1$ times (+1 because it will be checked the final time when `i > n`)
        - `++i`: executed n times
        - **total time** taken is: $n + 1$
    3. **Loop body**:
        - `f = f * i`: executed $n$ times
    4. **Return statement**: `return f` (executed 1 time)
    - **Time function**: $f(n) = 2n + 3$
    - **Asymptotic Time Complexity**: $O(n)$
- **Space Complexity**: $O(1)$
    - The function uses a fixed number of integer variables (n, f, i), regardless of the input size.

### Conclusion

See [complete code](./practice/factorial.c) for this topic

---

## Exponential
In mathematics, a power of a number, also known as an exponent, indicates how many times the base number is used as a factor in multiplication.

Example:
$$
2^5 = 2 * 2 * 2 * 2 * 2 = 32
$$

**Reducing formula**:
$$
\begin{align*}
m^n      &= m \times m \quad... \quad \text{for n times} \\
pow(m,n) &= (m * m * ... * (n - 1) \ \text{times}) \times m \\
pow(m,n) &= pow(m, n - 1) \times m
\end{align*}
$$

**Formal Recurrence Relation**:  
$$
pow(m,n) = 
\begin{cases} 
1 & \quad \quad n = 0 \\
pow(m,n-1) \times m & \quad \quad n > 0  
\end{cases}  
$$


```c
int pow(int m, int n){
    if (n == 0)
        return 1;
    return pow(m, n - 1) * m;
}
```
- **Time Complexity**: $O(n)$, where $n$ is the exponent
    - **Recursive Calls**: The function makes $n$ recursive calls (from $n$ down to 0)
    - **Operations per Call**: Each call performs a constant-time multiplication (* m) and a decrement of $n$
    - **Total Work**: There are $n$ multiplications in total, leading to a linear time complexity


*Refer to the tracing tree for a visual representation of the function control flow*
  ![](/assets/tracing-tree-exponential.png)


### Recursive Exponential (faster version)
This version, compared to the first one above, give the same output with 3 less multiplications. To make it work we add an additional check to tell if the exponent ($n$) is even or odd and adjust the formula accordingly.

- **When the input is even**:
    - the base is squared (multiplied by itself)
    - the exponent is halved
$$
\begin{align*}
2^8 &= (2^2)^4 \\
    &= (2 \times 2)^4
\end{align*}
$$

- Derivated Formula:
$$
    \begin{align*}
    \quad m^n &= (m^m)^{n/2} \\
    \end{align*}
$$

- **When the input is odd**,
    - the base is squared (multiplied by itself)
    - the exponent **decremented by 1** is halved
    - the base multiply the result of the exponential
$$
\begin{align*}
\quad 2^9 &= 2 \times (2^2)^4 \\
    &= 2 \times (2 \times 2)^4
\end{align*}
$$


Implementation of the faster version in C language:
```C
int Hpow(int m, int n){
    if (n == 0)
        return 1;
    if (n % 2 == 0)     // n is even
        return Hpow(m * m, n / 2);
    else                // n is odd
        return m * Hpow(m * m, (n-1) / 2);
}
```
- **Time Complexity**: $O(\log n)$, where $n$ is the exponent
    - The exponent $n$ is halved at every step, leading to $log_2(n)$ recursive calls.
    - Even when $n$ is odd, the next step becomes even (`n - 1`), maintaining the halving behavior.

*Refer to the tracing tree for a visual representation of the function control flow*
![](/assets/exponential-tracing-tree-v2.png)
- **Unwinding Phase**:
    - The last call `pow(16,1)` returns 1;
    - `16 * (2^8, 0)`: The return value is multiplied by the $m$ of the current stack frame: 16 * 1 = 16, return 16;
    - `pow(16,1)`: The return value is simply returned, return 16;
    - `2 * (4, 2)`: The return value is finally multiplied by the $m$ of current stack frame: 2 * 16 = 32, return 32
    - The final return value is 32


### Exponential using Iteration
This is the implementation of the algorithm using iteration instead of recursion:
```c
int Ipow(int m, int n){
    int e = 1;
    for (int i = 1; i <= n; ++i)
        e *= m;
    return e;
}
```
- **Time Complexity**: $O(n)$
    1. **Initialization**: `e = 1` executed 1 time (takes 1 unit of time)
    2. **Loop header**:
        - `i = 1`: executed 1 time
        - `i <= n`: executed $n + 1$ times (+1 because it will be checked the final time when `i > n`)
        - `++i`: executed n times
        - **total time** taken is: $n + 1$
    3. **Loop body**:
        - `e = e * m`: executed $n$ times
    4. **Return statement**: `return e` (executed 1 time)
    - **Time function**: $f(n) = 2n + 3$
    - **Asymptotic Time Complexity**: $O(n)$
- **Space Complexity**: $O(1)$
    - The function uses a fixed number of integer variables (m, n, e, i), regardless of the input size.

#### - Second version (Iteration) using while loop -
```c
int Ipow(int m, int n){
    int e = 1;
    while (n > 0){
        e *= m;
        n--;
    }
    return e;
}
```
- **Time Complexity**: $O(n)$
    1. **Initialization**: `e = 1` (1 operation).
    2. **Loop Condition Checks**: The condition `n > 0` is checked $n + 1$ times (once to enter the loop and n times after each decrement).
    3. **Loop Body**:
        - `e *= m` (1 multiplication per iteration, total n operations).
        - `n--` (1 decrement per iteration, total n operations).
    4. **Return Statement**: `return e` (1 operation).
    - **Time function**: $f(n) = 3n + 3$
    - **Asymptotic Time Complexity**: $O(n)$
- **Space complexity**: $O(1)$
    - The function uses a fixed number of integer variables (m, n, e), regardless of the input size.

### Conclusion
See [complete code](./practice/exponential.c) for this topic

---

## Taylor Series
The Taylor series or Taylor expansion of a function is an infinite sum of terms that are expressed in terms of the function's derivatives at a single point.

$$
e^x = 1 + \frac{x}{1} + \frac{x^2}{2!} + \frac{x^3}{3!} + \frac{x^4}{4!} + \dots + n \enspace \text{terms}
$$

In the Taylor series we have a combination of exponentials, factorials and the sum of the first two.

We have already seen the [Sum](#sum-of-first-n-natural-numbers), [Factorial](#factorial-of-a-number) and [Exponential](#exponential) recursive functions. In this algorithm we need to combine them.


>When need to return multiple values in a recursion, make use of static variables

**Example for** ($\boldsymbol{e^x}$) **with 4 terms**:

```C
double e(int x, int n){
    static double p = 1, f = 1; // p = power, f = factorial
    double r;
    if (n == 0)
        return 1;

    r = e(x, n-1);
    p = p * x;
    f = f * n;
    return r + p/f;
}
e(1,10); // 2.718282
```
- **Time Complexity**: $O(n^2)$

The analysis of the Taylor Series formula reveals that for every term, the number of operations (multiplication) is increased by 2.

![](/assets/taylor-series-analysis.png)

The algorithm can be optimized by decreasing the number of operations for each iteration. The solution is using the Horner's rule, discussed in the next chapter.

### - Taylor Series using Horner's rule (linear complexity)
Horner's rule can be used to evaluate Taylor series more efficiently by reducing the number of multiplications needed from $O(n^2)$ to $O(n)$.

This method **transforms the polynomial into a nested form**, which allows for the calculation of each term in the series with fewer operations.

Starting from the original formula, the Horner's rule is applied and polynomials are divided into monomials:

$$
\begin{align*}
e^x &= 1 + \frac{x}{1} + \frac{x^2}{2!} + \frac{x^3}{3!} + \frac{x^4}{4!} + \dots + n \enspace \text{terms} \\
&= 1 + \frac{x}{1} + \frac{x}{1*2} + \frac{x^2}{1*2*3} + \frac{x^3}{1*2*3} + \frac{x^4}{1*2*3*4}\\
&= 1 + \frac{x}{1} \bigg[1 + \frac{x}{2} + \frac{x^2}{2*3} + \frac{x^3}{2*3*4}\bigg] \\
&= 1 + \frac{x}{1} \Bigg[1 + \frac{x}{2} \bigg[ 1 + \frac{x}{3} + \frac{x^2}{3*4}\bigg]\Bigg] \\
&= 1 + \frac{x}{1} \Bigg[1 + \frac{x}{2} \bigg[ 1 + \frac{x}{3} \bigg[1 + \frac{x}{4}\bigg]\bigg]\Bigg]
\end{align*}
$$

The reduced formula is:
$$\mathbf{
1 + \frac{x}{1} \Bigg[1 + \frac{x}{2} \bigg[ 1 + \frac{x}{3} \bigg[1 + \frac{x}{4}\bigg]\bigg]\Bigg]}
$$


![taylor-series-horner-rule](/assets/taylor-series-horner-rule.png)



**Recursive Horner's rule**:
```c
double RH_e(int x, int n){
    static double s = 1;

    if (n == 0)
        return s;

    s = 1 + (x*s)/n; // multiply x by s to avoid integer division
    return RH_e(x, n-1);
}
```
- `s = 1 + (x*s)/n`: the original formula (s = 1 + x/n * s) is modified to avoid integer division(loss of data). `x` is multiplied by `s` beforehand.
- **Time Complexity**: $O(n)$

**Iterative Horner's rule**:
```c
double IH_e(int x, int n){
    double s = 1;
    
    for (;n > 0; --n)
        s = 1 + (x*s)/n;

    return s;
}
```
- **Time Function**: $O(4n + 2)$
    1. **Initialization**: `double s = 1` (1 operation)
    2. **Loop body**: `x * s`, `(x*s) / n`, `1 + (x*s) / n`, `s = 1 + (x*s)/n` (4 ops per iteration -> **4n**)
    3. **Return statement**: 1 operation

- **Time Complexity**: $O(n)$

**Iterative Horner's rule (easier to read)**:
```c
double HornerI_e(int x, int n){
    double s = 1;
    double num = 1; // numerator
    double den = 1; // denominator
    
    for (int i = 1; i <= n; ++i){
        num *= x;
        den *= i;
        s += num / den;
    }
    return s;
}
```
**Time Function**: $O(4n + 5)$
1. **Initialization**: `double s = 1`, `double num = 1`, `double den = 1`, `int i = 1` (4 operations)
2. **Loop body**: `num *= x`, `den *= i`, compute `num / den`, `s += num / den` (4 ops per iteration -> **4n**)
3. **Return statement**: 1 operation

**Time Complexity**: $O(n)$


### - Conclusion -
The Taylor series breaks a function into a polynomial "copy" that behaves just like the original function near a chosen point, with each term refining the approximation.

See [complete code](./practice/taylor-series.c) for this topic

---

## Fibonacci Sequence
In mathematics, the Fibonacci sequence is a sequence in which each element is the sum of the previous two terms.

$$
\boldsymbol{0 \enspace 1 \enspace 1 \enspace 3 \enspace 5 \enspace 8 \enspace 13} \dots
$$

![fibonacci-series](/assets/fibonacci-series.png)

The mathematical **recurrence relations** is as follow:
$$
fib(n) =
\begin{cases}
0 &  n = 0 \\
1 &  n = 1 \\
fib(n-2) + fib(n-1) & n > 1
\end{cases}
$$

### Naive Fibonacci - O(2^n)
The time complexity of the naive recursive Fibonacci algorithm is often cited as $\boldsymbol{O(2^n)}$, but this is actually a simplification. The precise complexity is $\boldsymbol{O(φⁿ)}$, where $\boldsymbol{φ ≈ 1.618}$ (the golden ratio). However, since $\boldsymbol{φ^n < 2^n}$, we use $\boldsymbol{O(2^n)}$ as a **loose upper bound** to emphasize its exponential nature.

```c
int fib(int n){
    if (n <= 1)
        return n;

    return fib(n-2) + fib(n-1);
}
```
- return the $n^{th}$ number of the sequence
- **Time Complexity**: approx. $O(2^n)$, exact $\boldsymbol{O(φⁿ)}$
    - The recursion tree has a **branching factor of 2** (each call splits into two subcalls), leading to a worst-case scenario of $\boldsymbol{O(2^n)}$ operations.
    - When $n = 46$, execution time: ~14s (on this [setup](#testing-setup))
- **Space Complexity**: $O(n)$
    - Each function call uses a constant amount of space (storing parameters, return address, etc.)
    - Space complexity is directly proportional to the levels of the tracing tree for this recursion (stack depth), therefore $O(n)$

#### - Recursion Tree Visualization -
Text based visualization:
```
                fib(5)
              /        \
        fib(4)          fib(3)
       /      \          /     \
   fib(3)  fib(2)    fib(2)  fib(1)
   /  \     /  \      /  \
fib(2) fib(1) ...    ...
```
Image based **naive fibonacci recursion tree** visualization:
![fibonacci-tree](/assets/fibonacci-recursion-tree-naive.png)

### Memoized Fibonacci - Reducing to O(n)
To avoid the excessive calls of the *Naive Fibonacci algorithm*, you use **memoization** (caching results of subproblems), the recursive Fibonacci algorithm can be optimized to $O(n)$ time, matching the iterative version’s efficiency.

```c
unsigned long long Mfib(int n){
    if (n <= 1) {
        F[n] = n;
        return n;
    }
    // if returning values are not already cached, do recursive call and store them
    if (F[n-2] == -1)
        F[n-2] = Mfib(n-2);
    if (F[n-1] == -1)
        F[n-1] = Mfib(n-1);

    F[n] = F[n-2] + F[n-1];
    return F[n-2] + F[n-1];
}
```
- **Time Function**: $O(n+1)$, does $n + i$ function calls, the rest are returned from the cached values.
    - When $n = 46$, execution time: ~0.004s
- **Time Complexity**: $O(n)$
- **Space Complexity**: $O(n)$

### Fibonacci using Iteration

```c
int Ifib(int n) {
    if (n <= 1) return n;

    int t0 = 0, t1 = 1, s;
    for (int i = 2; i <= n; ++i) {
        s = t0 + t1;  // Sum of previous two terms
        t0 = t1;       // Update t0 to the previous t1
        t1 = s;        // Update t1 to the new sum
    }
    return s;
}
```
- **Time Function**: $O(4n) \enspace \text{for n > 1}$
    - **Conditional check**: 1 operation
    - **Assignements**: `int t0 = 0, t1 = 1, s`; 1 operation
    - **Loop header**: n times
    - **Loop body**:
        - `s = t0 + t1`: n-1
        - `t0 = t1`: n-1
        - `t1 = s`: n-1
    - **Return statement**: 1 operation
- **Time Complexity**: $O(n)$
- **Space Complexity**: $O(1)$, only stores the last 2 terms

### Avoiding Integer Overflow
- **Limit of unsigned long long**: The maximum value is **18,446,744,073,709,551,615**.
- **Fibonacci numbers exceeding this limit**:
    - The 93rd Fibonacci number (12,200,160,415,121,876,738) is within the limit.
    - The **94th** Fibonacci number (19,740,274,219,868,223,167) exceeds it, **causing overflow**.

### - Conclusion -
While memoization trade space for time, the trade-off is minimal and the benefit in terms of algorithm time efficiency is really high.

See [complete code](./practice/fibonacci-series.c) for this topic

Here are the score of each Fibonacci algorithm (on this [setup](#testing-setup)):
|       Algorithm       |   Input  |  Time  |
|-----------------------|:--------:|:------:|
|  Excessive (naive)    |    46    |14.222s ± 0.1|
|  Memoized recursion   |    46    |0.004s ± 0.001|
|       Iterative       |    46    |0.004s ± 0.002|

---

## Combination Formula
The nCr formula, also known as combinations, is used to **find the number of ways to choose $r$ elements from a set of $n$ distinct elements without regard to the order of selection.**

$$
\boldsymbol{
    ^nC_r = \frac{n!}{r!(n-r)!}
}
$$

- $\boldsymbol{n}$: number of elements
- $\boldsymbol{C}$: combination function (there is also $\boldsymbol{^np_r}$ i.e. permutation function)
- $\boldsymbol{r}$: value from 0 to $n$

### Implementation of the ncr formula (non-recursive):
**Assumption**: the `fact()` function is implemented **iteratively** $O(n)$
```c
int ncr(int n, int r){
    int num, den;

    num = fact(n);
    den = fact(r) * fact(n-r);

    return num / den;
}
```
- **Time Complexity**: $O(n)$
    - `fact(n)`: $O(n)$
    - `fact(r)`: $O(r)$
    - `fact(n-r)`: $O(n - r)$
    
    Total time complexity is dominated by the largest term, which is $O(n)$. Even if `r` is small, the worst-case input (e.g., $r ≈ n/2$) still results in $O(n)$ operations.
- **Space Complexity**: $O(1)$
    - The function uses a constant number of variables `num, den`, and the iterative factorial implementation uses $O(1)$ auxiliary space (no recursion stack).

### Combination using Recursion
The recursive method to solve the combination function is to use the Pascal's Triangle algorithm.

Implementation of the **recursive** algorithm in C language:
```c
int ncr(int n, int r){
    if (r == 0 || r == n)
        return 1;

    return ncr(n-1, r-1) + ncr(n-1, r);
}
```
- **Time Complexity**: $O(n^2)$ 
    - Exponential due to redundant recomputation of overlapping subproblems (e.g., ncr(3, 1) is computed twice for ncr(4, 2)).
- **Space Complexity**: $O(n)$
    - Dictated by the maximum recursion depth (height of the call tree).
- **Stack Frame Analysis**:
    - **Winding Phase**: The recursion drills down to the base cases (leaves of the call tree).
    - **Unwinding Phase**: Partial results bubble upward, summing left and right subtree values.
    - **Inefficiency**: Repeated computation of identical subproblems (e.g., ncr(2, 1) is called for both ncr(3, 1) and ncr(3, 2)).

*Refer to the image below for a visual representation of the algorithm using the Pascal's Triangle model*
![](/assets/recursion-combination.png)


### Understanding the Recursive Combination (nCr) Algorithm
This algorithm calculates combinations using recursion, mimicking the structure of Pascal's Triangle. Here’s how it works:

#### <u>Base Case(boundary conditions)</u>:
- If `r` is **0 or equal to** `n`, the function returns 1.
    
    *(This corresponds to the edges of Pascal's Triangle.)*

- **Stack Frame**: These base cases terminate the winding phase of recursion, initiating the unwinding phase where **intermediate results propagate upward**.

#### <u>Recursive Logic</u>:
The function splits each problem into two smaller subproblems:

- **Left branch (subtree)**: `ncr(n-1, r-1)`
    
    (Decrease both `n` and `r` by 1)

- **Right branch (subtree)**: `ncr(n-1, r)`
    
    (Decrease only `n` by 1)

The final result is the sum of these two recursive calls:
`return ncr(n-1, r-1) + ncr(n-1, r);`

- **Call Stack Dynamics**:
Each recursive call generates a new stack frame, with parameters $(n,r)$ decrementing until a base case is reached. The **call tree’s leaves** correspond to $r=0$ or $r=n$, while internal nodes represent partial computations.


### Matrix Interpretation
The algorithm implicitly constructs a **lower-triangular matrix** where:
- **Row Index** represent values of `n` (0-based, starting from the apex).
- **Column Index** represent values of `r` up to $n$ ($0 \le r \le n$).

**Example Computations**:
$$\binom{3}{1} = \orange{\binom{2}{0}} + \binom{2}{1} = \orange{1} + 2 = 3$$
$$\binom{4}{1} = \orange{\binom{3}{0}} + \binom{3}{1} = \orange{1} + 3 = 4$$
$$\binom{4}{2} = \orange{\binom{3}{1}} + \binom{3}{1} = \orange{3} + 3 = 6$$

>Think of it as a matrix or a dimensional array where rows corresponds to $n$ and columns to $r$, so for n=4 and r=2, the result is 6 as seen in the example above

### Conclusion
This recursive approach encodes combinatorial principles but suffers from exponential time complexity.
For large $n$, iterative or closed-form solutions (multiplicative formula) are preferable.

See [complete code](./practice/combination-ncr.c) for this topic

---

## Tower of Hanoi
The Tower of Hanoi is a classic mathematical puzzle and a fundamental problem in computer science, often used to illustrate recursion, problem decomposition, and algorithmic thinking. Invented by French mathematician Édouard Lucas in 1883, it is accompanied by a legend: *priests in a temple must move 64 golden disks between three rods, and the world will end once the task is completed.* While the legend is fictional, it underscores the puzzle’s exponential time complexity.

Completing it with 64 disks would require $2^{64}−1$ moves!

![tower-of-hanoi](/assets/tower-of-hanoi.gif)

### Problem description
**The puzzle consists of:**
- Three rods (source, auxiliary, target).
- $n$ disks of different sizes, initially stacked on the source rod in decreasing order (largest at the bottom).

**Rules**:
- Only one disk can be moved at a time.
- A larger disk cannot be placed on top of a smaller one.

**Goal**: Transfer all disks from the **source** rod to the **target** rod using the auxiliary rod.

See: Interactive Tower of Hanoi [puzzle](https://www.mathsisfun.com/games/towerofhanoi.html)
### Procedures for solution
```
Procedure:
  TOH(n disk, from, using, to)

1-disk:
TOH(1, A, B, C)
    move disk from A to C using B

2-disks:
TOH(2, A, B, C)
  1. TOH(1, A, C, B)
  2. move disk from A to C using B
  3. TOH(1, B, A, C)

3-disks
TOH(3, A, B, C)
  1. TOH(2, A, C, B)
  2. move disk from A to C using B
  3. TOH(2, B, A, C)
----------------------------------  
GENERAL FORMULA

TOH(n, A, B, C)
  1. TOH(n-1, A, C, B)
  2. move disk from A to C using B
  3. TOH(n-1, B, A, C)
```
Implementation of the algorithm in C code:
```c
void TOH(int n, int A, int B, int C){
    if (n > 0){
        TOH(n-1, A, C, B);
        printf("from %d to %d\n", A, C);
        TOH(n-1, B, A, C);
    }
}
```
- Towers are passed as integers:
    - `A`: the source rod (tower 1)
    - `B`: the auxiliary rod (tower 2)
    - `C`: the target rod (tower 3)

![](/assets/tower-of-hanoi-tracing-tree.png)
- **Steps**: steps are executed at returning time (from bottom to top of the tree)
- **Time Complexity**: exponential $O(2^n)$
    - **Mathematical**: $\mathbf{2^{n+1} - 1}$
        - $1+2+2^2+ \ldots + 2^n$
        - for $n=3$, **15 calls** are made: $1 + 2 + 2^2 + 2^3 = 2^4 - 1$
        - for $n=2$, **7 calls** are made: $1 + 2 + 2^2 = 2^3 - 1$
    - **Recurrence relation**: $T(n) = 2(n - 1) + 1$
        - This arises because each call to `TOH(n)` generates two recursive calls (`TOH(n-1)` twice) and one printf operation.
- **Space Complexity**: linear $O(n)$
    - The space complexity is determined by the maximum depth of the recursion stack. At any point, the recursion depth is $n$ (e.g., for $n=3$, the call sequence is TOH(3) → TOH(2) → TOH(1) → TOH(0)).

### Conclusion
See [complete code](./practice/tower-of-hanoi.c) for this topic

## Footnotes

### Testing Setup
- **CPU**: AMD Ryzen 5 2600X @ 3.8Ghz
- **OS**: Debian - kernel 6.12.15 - x86_64
- **Compiler**(s): GCC