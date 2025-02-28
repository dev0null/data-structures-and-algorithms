#include <iostream>

template <class T>
class Calculator {
    T x;
    T y;
public:
    Calculator(T x, T y);
    T add();
    T sub();
};

template <class T>
Calculator<T>::Calculator(T x, T y) {
    this->x = x;
    this->y = y;
}

template <class T>
T Calculator<T>::add() {
    return x + y;
}

template <class T>
T Calculator<T>::sub() {
    return x - y;
}

int main(){
    Calculator<int> c_int(3,5);
    Calculator<float> c_float(3.5f, 5.0f);

    std::cout << "c_int (a+b): " << c_int.add() << std::endl;
    std::cout << "c_float (a+b): " << c_float.add() << std::endl;
    return 0;
}