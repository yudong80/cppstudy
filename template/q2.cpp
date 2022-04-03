//평균 구하기 
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

template <typename T, size_t n>
double average(const T (&t)[n]) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += t[i];
    return sum / n;
}

template<typename T>
double average(std::vector<T> const& v) {
    if (v.empty()) {
        return 0;
    }
    return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}

int main() {
    int x[10] { 1,2,3,4,5,6,7,8,9,10} ;
    vector<int> v { 1,2,3,4,5,6,7,8,9,10 };

    cout << average(x) << endl;
    cout << average(v) << endl;
}