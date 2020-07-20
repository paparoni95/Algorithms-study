#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int i;

bool compare(string a, string b) {
    // 삼항 연산자를 사용하면 간단하게 표현가능하다.
    return a[i] == b[i] ? a < b : a[i] < b[i];
}

vector<string> solution(vector<string> strings, int n) {
    i = n;
    sort(strings.begin(), strings.end(), compare);
    return strings;
}