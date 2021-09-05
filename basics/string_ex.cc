#include <iostream>

std::string getGreeting(std::string name) {
    std::string res = "hello ";
    return res + name;
}

int main() {
    const std::string hello = "hello";
    const std::string name = "yudong";

    //함수의 인자로 넘기고 반환하기 
    const std::string greeting = getGreeting(name);
    std::cout << greeting << std::endl;

    //간단한 멤버 함수 호출 
    std::cout << "length? " << greeting.length() << std::endl;
    std::cout << "is empty? " << greeting.empty() << std::endl;

    const int nameIndex = greeting.find(name);
    std::cout << "name idx? " << nameIndex << std::endl; 
    std::cout << "name? " << greeting.substr(nameIndex) << std::endl; 
}