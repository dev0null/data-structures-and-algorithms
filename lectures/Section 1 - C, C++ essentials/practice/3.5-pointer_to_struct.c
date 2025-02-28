#include <stdio.h>
#include <stdlib.h>

typedef struct Rectangle {
    int length;
    int breadth;
} Rectangle;

int main(){
    // Allocating a structure on Stack
    Rectangle r = {10, 5};
    Rectangle *ptr=&r;

    // Access structure through the variable
    r.breadth = 0;
    r.breadth = 0;

    // Access structure through a pointer with arrow operator or by dereference
    (*ptr).breadth = 20;
    ptr->length = 20;

    // Allocating a structure on Heap
    Rectangle *ptr_heap;
    ptr_heap = (Rectangle *)malloc(sizeof(Rectangle));

    ptr_heap->length = 8;
    ptr_heap->breadth = 5;
    unsigned area = ptr_heap->breadth * ptr_heap->length;

    printf("Length: %i\nBreadth: %i\n", ptr_heap->length, ptr_heap->breadth);
    printf("Area of Rectangle: %u\n", area);

    free(ptr_heap);
    return 0;
}