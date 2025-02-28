#include <cstdio>
#include <iostream>

// Call by value
void pass_by_value(int a, int b){
    a = 0;
    b = 0;
}

// Call by reference
void pass_by_reference(int &a, int &b){
    a = 0;
    b = 0;
}

// Call by address
void pass_by_address(int *a, int *b){
    *a = 10;
    *b = 100;
}


int main(){
    int num1 = 10, num2 = 15;

    printf("### CALL BY VALUE ###\n");
    pass_by_value(num1, num2);
    printf("num1: %i\nnum2: %i\n", num1, num2);
    // num1, num2 did not change

    printf("### CALL BY REFERENCE ###\n");
    pass_by_reference(num1, num2);
    printf("num1: %i\nnum2: %i\n", num1, num2);
    // num1, num2 changed to 0

    printf("### CALL BY ADDRESS ###\n");
    pass_by_address(&num1, &num2);
    printf("num1: %i\nnum2: %i\n", num1, num2);
    // num1, num2 changed to 10 and 100
    
    return 0;
}