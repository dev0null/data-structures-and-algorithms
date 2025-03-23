#include <stdio.h>

int fact(int n){
    int r = 1;
    for (int i = 1; i <= n; ++i)
        r *= i;
    return r;
}

// combination formula (using factorial)
int ncr_fact(int n, int r){
    int num, den;

    num = fact(n);
    den = fact(r) * fact(n-r);

    return num/den;
}

// recursive
int ncr(int n, int r){
    if (r == 0 || r == n)
        return 1;

    return ncr(n-1, r-1) + ncr(n-1, r);
}

int main(){
    int n, r;
    n = 5;
    r = 2;
    
    printf("%d\n", ncr_fact(n,r));
    printf("%d\n", ncr(n,r));
    return 0;
}