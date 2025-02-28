#include <stdio.h>
#include <stdlib.h>

// return by array
int *allocate_array(int size){
    int *p;
    p = (int *) malloc(size * sizeof(int));

    for (int i = 0; i < size; ++i)
        p[i] = i + 1;

    return p;
}

// take array as parameter (passed by address)
void zero_array(int array[], int size){
    // Zero-out the original array
    for (int i = 0; i < size; ++i)
        array[i] = 0;
}

void print_array(int array[], int size){
    // Print the original array
    for (int i = 0; i < size; ++i)
        printf("%i ", array[i]);
    printf("\n");
}

int main(){
    int arr[5] = {10, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    zero_array(arr, size); // array are ONLY passed by address
    print_array(arr, size);
    
    // pointer to an HEAP allocated array
    int *arr_ptr;
    arr_ptr = allocate_array(5);
    print_array(arr_ptr, 5);

    printf("\n");
    return 0;
}