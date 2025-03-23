#include <stdio.h>


void TOH(int n, int A, int B, int C, int *k){
    if (n > 0){
        TOH(n-1, A, C, B, k);
        printf("from %d to %d\n", A, C);
        TOH(n-1, B, A, C, k);
    }
    *k += 1;
}

int main(){
    int steps = 0;
    TOH(4, 1, 2, 3, &steps);

    printf("Steps: %d\n", steps);
    return 0;
}