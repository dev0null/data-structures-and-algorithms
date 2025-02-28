#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size){
    printf("Printing array: ");
    for (int i = 0; i < size; ++i)
        printf("%i ", *(arr+i));

    printf("\n");
}

int main(){
    int a = 10;
    int *ptr_a;

    ptr_a = &a;
    *ptr_a += 1; // Dereference and add 1 to the value pointed by p

    printf("Address of p: %p\n", ptr_a);    // 0x7ffeac6011ebc
    printf("Address of a: %p\n", &a);       // 0x7ffeac6011ebc

    printf("Value of p: %i\n", *ptr_a); // 11
    printf("Value of a: %i\n", a);      // 11

    // ARRAYS POINTERS on STACK

    int arr[5] = {2,4,6,8,10};
    int *ptr;
    ptr = arr; // arrays are already pointers
    print_array(ptr, 5);


    // ARRAYS POINTERS on HEAP

    int *h_ptr = (int*)malloc(5 * sizeof(int));
    
    // Populate array
    for (int i = 0; i < 5; ++i)
        *(h_ptr+i) = i * 2;

    print_array(h_ptr, 5);

    free(h_ptr);    // Deallocate memory

    return 0;
}