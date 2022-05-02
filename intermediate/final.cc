#include <iostream>
using namespace std;

class Test { 
public:
    void foo() {}
    static void goo() {}
};
void hoo() {}

int main() {
    void(*f1)() = hoo;
    void(*f2)() = &hoo;
    // void(*f3)() = &Test::foo;
    void(*f4)() = &Test::goo;
}