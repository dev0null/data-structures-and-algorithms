#include <stdio.h>

// Definition
typedef struct Rectangle {
    int length;     // 4-bytes
    int breadth;    // 4-bytes
    char x;         // 1-byte
} Rectangle;

typedef struct Student {
    int roll;
    char name[25];
    char dept[10];
    char address[50];
} Student;

typedef struct Card {
    int face;
    int shape;
    int color;
} Card;

int main(){
    // Stack allocated
    Rectangle rect;
    rect.breadth = 5;

    // Declaration + Initialization
    Rectangle r = {5, 8};

    printf("Size of Rectangle struct: %lu-bytes\n", sizeof(Rectangle));

    int area = r.length * r.breadth;
    printf("Area of rectangle is: %i\n", area);

    printf("------------------------------------\n");

    Student s;
    printf("Sizeof Student struct: %lu\n", sizeof(s));

    printf("------------------------------------\n");

    Card c;
    printf("Size of Card struct: %lu\n", sizeof(c));
    return 0;
}