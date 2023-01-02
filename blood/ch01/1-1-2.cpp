#include <iostream>

int main(void) {
    std::string name;
    std::string phone;

    std::cout << "Name? "; std::cin >> name;
    std::cout << "Phone? "; std::cin >> phone;

    std::cout << "Name is " << name << ", Phone number is " << phone << std::endl;
}