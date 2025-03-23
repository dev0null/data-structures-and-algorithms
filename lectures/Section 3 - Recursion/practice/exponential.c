#include <stdio.h>

// Recursive
int _pow(int m, int n){
    if (n == 0)
        return 1;
    return _pow(m, n - 1) * m;
}

// Iterative - for
int FIpow(int m, int n){
    int e = 1;
    for (int i = 1; i <= n; ++i){
        e *= m;
    }
    return e;
}

// Iterative
int Ipow(int m, int n){
    int e = 1;
    while (n > 0){
        e *= m;
        n--;
    }
    return e;
}
// halved (logarithmic)
int Hpow(int m, int n){
    if (n == 0)
        return 1;
    if (n % 2 == 0)     // n is even
        return Hpow(m * m, n/2);
    else      // n is odd
        return m * Hpow(m * m, (n-1)/2);
}

int main(){
    int m = 2;
    int n = 8;
    
    for (int i = n; i >= 0; --i){
        printf("\n- Calculating %i to the %i\n", m,i);
        printf("_pow:  %i\n", _pow(m, i)); fflush(0);
        printf("FIpow: %i\n", FIpow(m, i)); fflush(0);
        printf("Ipow:  %i\n", Ipow(m, i)); fflush(0);
        printf("Hpow:  %i\n", Hpow(m, i)); fflush(0);
    }
    return 0;
}