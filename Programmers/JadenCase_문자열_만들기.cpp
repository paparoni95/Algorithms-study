#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    vector<string> v;
    string temp;
    // 한 문장을 ' '을 기준으로 나눠서 문자열로 벡터에 저장
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != ' ') {
            temp += s[i];
        }
        else {
            v.push_back(temp);
            temp.clear();
        }
    }
    v.push_back(temp);

    // 문자열의 첫 문자를 대문자로 변경, 그 외의 문자는 소문자로 변경
    for (int i = 0; i < v.size(); ++i) {
        string& str = v[i];
        if (str[0] >= 'a' && str[0] <= 'z')
            str[0] -= 32;
        for (int j = 1; j < str.length(); ++j) {
            if (str[j] >= 'A' && str[j] <= 'Z')
                str[j] += 32;
        }
    }

    // 벡터를 다시 string 객체에 옮긴다.
    string answer = "";
    answer += v[0];
    for (int i = 1; i < v.size(); ++i) {
        answer += " ";
        answer += v[i];
    }

    return answer;
}