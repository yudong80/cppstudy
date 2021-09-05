#include <iostream>
#include <map>

//ref: https://en.cppreference.com/w/cpp/container/map
void print_map(std::string title, const std::map<std::string, int>& map) {
    std::cout << title << " { "; 
    for (auto pair : map) {
        std::cout << pair.first << ": " << pair.second << ", ";
    }
    std::cout << "}" << std::endl;
}

int main(void) {
    std::map<std::string, int> map = {
        {"CPU", 10},
        {"GPU", 15}, 
        {"RAM", 20},
    };

    print_map("BEFORE:", map);
    map["CPU"] = 25;    //데이터 갱신
    map["SSD"] = 30;    //신규 데이터 추가 
    print_map("AFTER:", map);
}