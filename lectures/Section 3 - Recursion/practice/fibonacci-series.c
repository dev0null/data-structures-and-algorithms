#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long u64;
typedef signed long long i64;

#define MEMO_SIZE 96
i64 F[MEMO_SIZE]; // global array for memoization

// Recursive
u64 fib(int n){
    if (n <= 1) return n;
    return fib(n-2) + fib(n-1);
}
// Iterative
u64 Ifib(int n) {
    if (n <= 1) return n;

    int t0 = 0, t1 = 1, s = 0, i;
    for (i = 2; i <= n; ++i) {
        s = t0 + t1;            // Sum of previous two terms
        t0 = t1;                // Update t0 to the previous t1
        t1 = s;                 // Update t1 to the new sum
    }
    return s;
}
// Memoized
u64 Mfib(int n){
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

int main(int argc, char *argv[]){
    int n = 12;
    if (argc > 1){
        int inp = atoi(argv[1]);
        n = inp > 94 ? 12 : inp;
    }

    // initialize array to -1
    for(int i = 0; i < MEMO_SIZE; ++i)
        F[i] = -1;
    
    // printf("Naive Recursive: %llu\n", fib(n)); // Slow
    // printf("Iterative: %llu\n", Ifib(n));
    printf("Memoized Recursive: %llu\n", Mfib(n));

    // print memoized values
    for(i64* p = F; *p != -1; p++){
        printf("%lli\n", *p);
    }
    return 0;
}