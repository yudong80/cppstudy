#include <iostream>

int main(void) {
    int dan;
    std::cin >> dan;

    for (int i=1; i<= 9; ++i) {
        std::cout << dan << " * " << i << " = " << dan * i << std::endl;
    }
}