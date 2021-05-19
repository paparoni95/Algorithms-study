#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

string solution(string s) {
    // string에서도 가능하다.
    // 내림차순으로 하려면 greater<>()를 사용하자.
    sort(s.begin(), s.end(), greater<char>());
    return s;
}