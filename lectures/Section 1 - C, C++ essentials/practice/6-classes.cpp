#include <iostream>

class Rectangle {

    int m_length;
    int m_breadth;

public:
    Rectangle(int _length, int _breadth)
        : m_length(_length), m_breadth(_breadth)
    {

    }

    int area(){
        return m_length * m_breadth;
    }

    void change_length(int n){
        m_length = n;
    }

};

int main(){

    Rectangle r(10, 5);
    int area = r.area();
    r.change_length(20);

    std::cout << "Area: " << area << std::endl;
    return 0;
}