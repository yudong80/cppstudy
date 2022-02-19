#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

bool linear_search(int n, std::vector<int>& s) {
    for (auto i : s) {
        if (i == n) 
            return true;
    }
    return false;
}

bool binary_search(int n, std::vector<int>& s) {
    auto first = s.begin();
    auto last = s.end();

    while(true) {
        auto range_length = std::distance(first, last);
        auto mid_element_index = std::floor(range_length) / 2;
        auto mid_element = *(first + mid_element_index);

        if(mid_element == n)
            return true;
        else if(mid_element > n)
            std::advance(last, -mid_element_index);
        else
            std::advance(first, mid_element_index);

        if (range_length == 1)
            return false;
    }
}

void run_small_search_test() {
    auto n = 2;
    std::vector<int> s {1, 3, 2, 4, 5, 7, 9, 8, 6};

    std::sort(s.begin(), s.end());

    if (linear_search(n, s))
        std::cout << "선형 검색으로 원소를 찾았습니다!" << std::endl;
    else 
        std::cout << "선형 검색으로 원소를 찾지 못해습니다!" << std::endl;
    
    if (binary_search(n, s))
        std::cout << "이진 검색으로 원소를 찾았습니다!" << std::endl;
    else 
        std::cout << "이진 검색으로 원소를 찾지 못해습니다!" << std::endl;
}

void run_large_search_test(int size, int n) {
    std::vector<int> s;
    std::random_device rd;
    std::mt19937 rand(rd());

    std::uniform_int_distribution<std::mt19937::result_type> uniform_dist(1, size);

    for (auto i = 0; i < size; ++i) 
        s.push_back(uniform_dist(rand));
    
    std::sort(s.begin(), s.end());

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    bool search_result = binary_search(n, s);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << "이진 검색 수행 시간: " << diff.count() << std::endl;

    if (search_result)
        std::cout << "원소를 찾았습니다." << std::endl;
    else 
        std::cout << "원소를 찾지 못했습니다." << std::endl;
}

int main() {
    run_small_search_test(); 

    run_large_search_test(100000, 36543);
    run_large_search_test(1000000, 36543);
    run_large_search_test(10000000, 36543);

    return 0;
}