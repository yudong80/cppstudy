#include <iostream>
#include <list> 

void print_list(std::string title, std::list<std::string> list) {
    std::cout << title << " [ ";
    for (std::string element : list) {
        //TODO 마지막 콤마(,)를 없애는 방법은? (+ 깔끔한 코딩)
        std::cout << element << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() { 
    std::list<std::string> planets = {
        "Earth",    //지구
        "Mars",     //화성
        "Jupiter"   //목성
    };

    //1. 순회 
    print_list("BEFORE:" , planets);

    const std::string mercury = "Mercury";  //수성 
    const std::string venus = "Venus";      //금성
    const std::string saturn = "Saturn";    //토성
    const std::string uranus = "Uranus";    //천왕성

    //2. 가장 앞/뒤에 넣기 
    planets.push_front(mercury);
    planets.push_back(saturn);

    //3. 중간에 넣기 
    auto it = planets.begin(); 
    it++;  
    planets.insert(it , venus);

    //4. emplace_back (no move)
    planets.emplace_back(uranus);
    print_list("AFTER: " , planets);
}