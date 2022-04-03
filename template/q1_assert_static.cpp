//N1~ N2 사이의 합을 구하는 Sum 만들기 
#include <type_traits>

template<typename T> 
T Sum(T a, T b) {
    static_assert(std::is_integral_v<T>, "error");
    return a + b;
}

int main() {
    int n1 = 5, n2=10;
    short s1 = 5, s2 = 10; 
    double d1 = 3.4, d2 = 1.2;

    Sum(n1, n2); //ok
    Sum(s1, s2); //ok
    //Sum(d1, d2); //error 
}