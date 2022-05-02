#include <string>
#include <iostream>
using namespace std;

class People {
public:
    string name;
    string addr;
    int age;
public:
    People(string n, string add, int a): name(n), addr(add), age(a) {}

    // 복사 생성자, 대입 연산자, Move 생성자, Move 대입 연산자를 만드세요. 
    // 실행 여부를 확인하기 위해 logging을 해주세요.
    People(const People& p): name(p.name), addr(p.addr), age(p.age) {
        cout << "copy constructor" << endl;
    }
    People& operator=(const People& p) {
        cout << "copy assignment operator" << endl;
        this->age = p.age;
        this->name = p.name;
        return *this;
    }
    People(People &&p) : name(move(p.name)), addr(move(p.addr)), age(move(p.age)) {
        cout << "move constructor" << endl;
    }
    People& operator=(People &&p) {
        cout << "move assignment operator" << endl;
        name = move(p.name);
        addr = move(p.addr);
        age = move(p.age);
        return *this;
    }
};
int main() {
    People p1 {"홍길동", "서울", 20};
    People p2 = p1;         //copy
    p2 = p1;                //copy assign
    People p3 = move(p1);   //move
    People p4 {"홍길동", "서울", 20};
    p3 = move(p4);          //move assign
}