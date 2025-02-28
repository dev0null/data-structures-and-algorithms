#include <iostream>

typedef struct Rectangle {
    int breadth;
    int length;
} Rectangle;

typedef struct ArrayStruct {
    int arr[5];
    int size;
} ArrayStruct;


// Call by value
int area_by_value(Rectangle rect){
    return rect.breadth * rect.length;
}

// Call by reference - the function will be pasted in main at compile time (monolithic machine code)
int area_by_reference(Rectangle &rect){
    return rect.breadth * rect.length;
}

// Call by address
void change_length(Rectangle *rect, int n){
    rect->length = n;
}

// struct passed by value, having an array inside (array can only be passed by address)
// but in this case it is passed by value
void array_struct(ArrayStruct arr){
    // Zero-out the copy of the array
    for (int i = 0; i < arr.size; ++i)
        arr.arr[i] = 0;

    std::cout << "Copy ArrayStruct.arr[0] = " << arr.arr[0] << std::endl;
}

// Return dynamically allocated Rectangle object
Rectangle *get_rectangle(){
    Rectangle *p;
    // p = (Rectangle *) malloc(sizeof(Rectangle));
    p = new Rectangle;
    p->breadth = 7;
    p->length = 15;

    return p;
}

int main(){

    Rectangle r = {5, 10};

    // Call by value
    printf("Length: %d\n", r.length);
    printf("Breadth: %d\n", r.breadth);
    printf("area: %d\n", area_by_value(r));

    // Call by address
    change_length(&r, 0);
    printf("Changed length: %d\n", r.length);
    printf("Breadth: %d\n", r.breadth);


    ArrayStruct array = {{2,4,6,8,10}, 5};
    printf("Original ArrayStruct.arr[0] = %i\n", array.arr[0]);
    array_struct(array);
    // The array is not modified by the array_struct() function

    // Create a rectangle object
    Rectangle *rect = get_rectangle();
    std::cout << "Length: " << rect->length << ", breadth: " << rect->breadth << std::endl;
    delete []rect;
    return 0;
}