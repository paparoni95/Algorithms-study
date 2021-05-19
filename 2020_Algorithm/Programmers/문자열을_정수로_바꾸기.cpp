#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;

    // 부호처리도 알아서 해준다. (-, +)
    answer = stoi(s);

    return answer;
}