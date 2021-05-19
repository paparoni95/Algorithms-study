#include <string>
#include <vector>
using namespace std;

// 그냥 조합을 쓰면 시간초과 발생, 문자열의 길이가 최대 100만이므로
// 그렇기 때문에 빠르게 패스해주는 탐욕법으로 풀어야 한다.
// 4177252841 k = 4이면,
// 41772 -> 7, idx = 2
// 725 -> 7, idx = 3
// 252 -> 5, idx = 5
// ... 반복
string solution(string number, int k) {
    string answer = "";

    int choice = number.length() - k;
    int start = 0;
    for (int i = 0; i < choice; ++i) {
        char max_number = number[start];
        int max_idx = start;
        for (int j = start; j <= i + k; ++j) {
            if (max_number < number[j]) {
                max_idx = j;
                max_number = number[j];
            }
        }
        start = max_idx + 1;
        answer += max_number;
    }

    return answer;
}