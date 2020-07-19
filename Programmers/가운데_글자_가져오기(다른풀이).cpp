#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    int len = s.length();
    if (len % 2 == 0)
        answer = s.substr((len / 2) - 1, 2);
    else
        answer = s[len / 2];

    return answer;
}