#include <stdio.h>

double e(int x, int n){
    static double p = 1, f = 1;
    double r;

    if (n == 0)
        return 1;
    
    r = e(x, n - 1);
    p = p * x;
    f = f * n;

    return r + p/f;
}

// Horner's rule recursive
double HornerR_e(int x, int n){
    static double s = 1;

    if (n == 0)
        return s;

    s = 1 + (x*s)/n;
    return HornerR_e(x, n-1);

}

// Horner's rule iterative
double HornerI_e(int x, int n){
    double s = 1;
    
    for (;n > 0; --n)
        s = 1 + (x*s)/n;

    return s;
}

// Horner's rule iterative 2
double HornerI_e2(int x, int n){
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


int main(){
    printf("Recursion: %lf\n", e(1,10));
    printf("Horner Recursion: %lf\n", HornerR_e(1,10));
    printf("Horner Iteration: %lf\n", HornerI_e2(1,10));
    return 0;
}