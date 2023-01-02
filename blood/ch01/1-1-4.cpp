#include <iostream>

int main(void) {
    while(true) {
        int input;
        std::cout << "Sales? "; std::cin >> input; 
        if(input < 0) {
            break;
        }
        
        int output = (input * 12 / 100) + 50;
        std::cout << "Received money: " << output << std::endl;
    }
}