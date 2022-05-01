#include <iostream>
#include <algorithm>
using namespace std;

//#1. 람다 표현식과 지역 변수 캡쳐 

int main() {
    vector<int> x {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> y;
    // int x[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // int y[10];
    int v1 = 10;

    // x의 모든 요소에 v1을 더해서 y에 넣어주세요
    // 조건 1. x와 y가 배열이 아닌 vector인 경우도 코드 변경없이 실행되게 해주세요. 
    // 조건 2. 람다 표현식을 사용해주세요 
    transform(x.begin(), x.end(), back_inserter(y), [v1] (int x) { return x + v1; }); //vector
    // transform(x, x + sizeof(x)/sizeof(int), y, [v1] (int x) { return x + v1; }); //array
    

    for (auto n : y)
        cout << n << endl;
}