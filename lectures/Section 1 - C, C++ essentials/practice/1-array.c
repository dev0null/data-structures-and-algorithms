#include <stdio.h>
#include <stdlib.h>


int main(){
    int size;
    printf("What size should the dynamic array be: ");
    scanf("%d", &size);

    int *array = (int*)malloc(size * sizeof(int));

    // zero-out array
    for (int i = 0; i < size; ++i)
        array[i] = 0;

    // Print array
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);

    printf("\n");
    free(array);
    return 0;
}