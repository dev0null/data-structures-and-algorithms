#include <iostream>

int main(){
    // STACK
    int sarr[5];  // Stack allocated
    std::cout << sizeof(sarr) << '\n';  // 20 <=> 4-bytes(int) * 5 elements


    // HEAP
    int size {0};
    std::cout << "What size should the dynamic array be: " << '\n';
    std::cin >> size;
    int *arr = new int[size];  // Dynamically allocated array on HEAP
    
    // zero out array
    for (int i = 0; i < size; ++i)
        arr[i] = 0;

    // Print array
    std::cout << "Array: ";
    for (int i = 0; i < size; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    delete []arr; // free allocated memory
    return 0;
} 