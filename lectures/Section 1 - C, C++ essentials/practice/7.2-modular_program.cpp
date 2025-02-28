#include <iostream>

using namespace std;

class Rectangle {
    int m_length;
    int m_breadth;    
public:
    Rectangle() {
        m_length = m_breadth = 0;
    }
    Rectangle(int length = 0, int breadth = 0)
        : m_length(length), m_breadth(breadth){}

    ~Rectangle(){}
    
    int area(){
        return m_length * m_breadth;
    }
    int perimeter(){
        return 2 * (m_length + m_breadth);
    }
    int get_length(){
        return m_length;
    }
    int get_breadth(){
        return m_breadth;
    }
    void set_length(int n){
        m_length = n;
    }
    void set_breadth(int n){
        m_breadth = n;
    }
};

int main(){
    int l, b;

    cout << "Enter the Length and Breadth: ";
    cin >> l >> b;
    Rectangle r(l,b);

    cout << "Area: " << r.area() << "\nPerimeter: " << r.perimeter() << std::endl;
    return 0;
}