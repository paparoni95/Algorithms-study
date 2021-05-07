#include <string>
#include <vector>
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

vector<int> solution(int n, int m) {
    vector<int> answer(2, 0);
    answer[0] = gcd(n, m);
    answer[1] = (n / answer[0]) * (m / answer[0]) * answer[0];
    return answer;
}