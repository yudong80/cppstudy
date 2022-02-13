#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

//연습문제 14: 체이닝을 사용하는 해시 테이블

using uint = unsigned int;

class hash_map {
public:
    hash_map(size_t n) {
        data.resize(n);
    }

    void insert(uint value) {
        int n = data.size();
        data[value % n].push_back(value); //FIXME: 해시값 충돌 이슈 
        std::cout << value << "을(를) 삽입했습니다." << std::endl;
    }

    bool find(uint value) {
        int n = data.size();
        auto& entries = data[value % n];
        return std::find(entries.begin(), entries.end(), value) != entries.end();
    }

    void erase(uint value) {
        int n = data.size();
        auto& entries = data[value % n];
        auto iter = std::find(entries.begin(), entries.end(), value);
        if (iter != entries.end()) {
            entries.erase(iter);
            std::cout << value << "을(를) 삭제했습니다." << std::endl;
        }
    }

private:    
    std::vector<std::list<int>> data;
};

int main() {
    hash_map map(7);

    auto print = [&](int value) { 
        if (map.find(value))
            std::cout << "해시 맵에서 " << value << "을(를) 찾았습니다.";
        else
            std::cout << "해시 맵에서 " << value << "을(를) 찾지 못했습니다.";
        std::cout << std::endl;
    };

    map.insert(2);
    map.insert(25);
    map.insert(10);
    map.insert(100);
    map.insert(55);

    print(100);
    print(2);

    map.erase(2);
}