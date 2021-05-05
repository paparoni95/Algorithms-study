#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int a, int b) {
    // 가우스 공식 n(x + y) / 2
    // n : x와 y 사이의 개수
    // x : 작은 수
    // y : 큰 수
    return (long long)(a + b) * (abs(a - b) + 1) / 2;
}