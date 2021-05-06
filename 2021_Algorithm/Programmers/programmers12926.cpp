#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') answer += " ";
        else {
            if (isupper(s[i])) {
                int pos = (s[i] - 'A' + n) % 26;
                answer += ('A' + pos);
            }
            else {
                int pos = (s[i] - 'a' + n) % 26;
                answer += ('a' + pos);
            }
        }
    }
    return answer;
}