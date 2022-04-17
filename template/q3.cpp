#include <iostream>
class Count {
    static int cnt;
public:
    Count() { ++cnt; }
    ~Count() { --cnt; }
    static int count() { return cnt; }
};
int Count::cnt = 0;

class Mouse: public Count{};
class Keyboard: public Count{};

int main() { 
    Mouse m1, m2;
    Keyboard k1, k2;
    std::cout << m1.count << std::endl;
}