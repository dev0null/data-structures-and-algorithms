#include <iostream>

using namespace std;
int main(){
    int a = 10;
    int &ref = a;

    // Changing a
    cout << "Adding 1 to 'a'" << endl;
    a += 1;
    cout << "a: " << a << endl;         // 11
    cout << "ref: " << ref << endl;     // 11

    // Changin ref
    cout << "Adding 1 to 'ref'" << endl;
    ref += 1;
    cout << "a: " << a << endl;         // 11
    cout << "ref: " << ref << endl;     // 11

    // Assigning b to ref. 
    // This will not make the ref point to b but will assign the value of b to 'ref' and hence to 'a'
    int b = 20;
    ref=b;
    cout << "a: " << a << endl;         // 20
    cout << "ref: " << ref << endl;     // 20

    return 0;
}