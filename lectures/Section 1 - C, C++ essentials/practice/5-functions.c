#include <stdio.h>

// Function prototype, tells the compiler there will be a definition later
int add(int a, int b);

int main(){
    int sum = add(1,5);         // assign the return value to sum
    printf("Sum: %i\n", sum);

    return 0;
}

// Function definition
int add(int a, int b){
    return a + b;
}