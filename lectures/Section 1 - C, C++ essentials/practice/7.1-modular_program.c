#include <stdio.h>

typedef struct Rectangle {
    int length;
    int breadth;
} Rectangle;

int get_area(Rectangle r){
    return r.length * r.breadth;
}
int get_perimeter(Rectangle r){
    return 2 * (r.length + r.breadth);
}
void initialize(Rectangle *r, int l, int b){
    r->length = l;
    r->breadth = b;
}

int main(){
    Rectangle rect = {0,0};

    int l, b;
    printf("Enter the Length and Breadth: ");
    scanf("%i %i", &l, &b);
    initialize(&rect, l, b);

    int area = get_area(rect);
    int perim = get_perimeter(rect);

    printf("Area: %d \nPerimeter: %d\n", area, perim);
    return 0;
}