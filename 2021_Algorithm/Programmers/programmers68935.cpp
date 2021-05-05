#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> ret;

    while (n) {
        ret.push_back(n % 3);
        n /= 3;
    }

    int mul = 1;
    for (int i = ret.size() - 1; i >= 0; i--, mul *= 3) {
        answer += (ret[i] * mul);
    }

    return answer;
}