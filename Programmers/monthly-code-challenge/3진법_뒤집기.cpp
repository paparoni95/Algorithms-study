#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    string result;
    while (n > 0) {
        result += ((n % 3) + '0');
        n /= 3;
    }
    int cnt = 0;
    for (int i = result.size() - 1; i >= 0; i--, cnt++) {
        int num = result[i] - '0';
        int value = pow(3, cnt) * num;
        answer += value;
    }
    return answer;
}