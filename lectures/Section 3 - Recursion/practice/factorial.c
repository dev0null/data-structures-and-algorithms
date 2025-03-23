#include <stdio.h>

// Recursive
int fact(int n){
    if (n <= 0)
        return 1;
    return fact(n - 1) * n;
}

// Iterative
int Ifact(int n){
    int f = 1;
    for (int i = 1; i <= n; ++i)
        f *= i;
    return f;
}

int main(){
    printf("%i\n", fact(5)); fflush(0);
    return 0;
}