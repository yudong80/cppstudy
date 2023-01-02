#include <iostream>

int main(void) {
    int a[5];
    for (int i=0; i<5; ++i) {
        std::cout << (i+1) << "th Number? ";
        std::cin >> a[i];
    }

    int sum = 0;
    for (int i=0; i<5; ++i) {
        sum += a[i];
    }
    std::cout << "Sum: " << sum; 
}