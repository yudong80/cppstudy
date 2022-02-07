#include <iostream>
#include <forward_list>
#include <vector>

//연습문제 4: 다양한 반복자에서 이동하기


int main() {
    std::vector<std::string> vec = {
        "Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg",
        "Sebastian Vettel", "Lewis Hamilton", "Sebastian Vettel",
        "Sebastian Vettel", "Sebastian Vettel", "Fernando Alonso",
    };

    auto it = vec.begin();
    std::cout << "가장 최근 우승자: " << *it << std::endl;

    it += 8;
    std::cout << "8년전 우승자: " << *it << std::endl;

    advance(it, -3);
    std::cout << "그후 3년 뒤 우승자: " << *it << std::endl;

    std::forward_list<std::string> fwd(vec.begin(), vec.end());

    auto it1 = fwd.begin();
    std::cout << "가장 최근 우승자: " << *it1 << std::endl;

    advance(it1, 5);
    std::cout << "5년전 우승자: " << *it1 << std::endl;
}