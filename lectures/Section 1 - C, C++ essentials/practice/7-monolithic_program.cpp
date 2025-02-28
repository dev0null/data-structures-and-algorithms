#include <iostream>

using namespace std;
int main(){
    int length = 0, breadth = 0;

    cout << "Enter the Length and Breadth: ";
    cin >> length >> breadth;

    int area = length * breadth;
    int perim = 2 * (length + breadth);

    cout << "Area: " << area << "\nPerimeter: " << perim << std::endl;
    return 0;
}