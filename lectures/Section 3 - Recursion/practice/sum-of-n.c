#include <stdio.h>

// Direct formula
int sum_f(int n){
    if (n <= 1) return n;
    return n * (n+1) / 2;
}

// Recursive
int sum(int n){
    if (n == 0) return 0;
    return sum(n - 1) + n;
}

// Iterative
int Isum(int n){
    int s = 0;
    for (int i = 1; i <= n; ++i)
        s += i;
    return s;
}

int main(){
    printf("%d\n", Isum(5));
    fflush(0); // flush stdout - force output
    return 0;
}