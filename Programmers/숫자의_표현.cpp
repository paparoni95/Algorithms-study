#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool func(int start, int goal) {

    int sum = 0;
    while (true) {
        if (sum > goal) break;
        sum += start;
        if (sum == goal) {
            return true;
        }

        ++start;
    }
    return false;
}

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        if (func(i, n)) {
            ++answer;
        }
    }
    return answer;
}