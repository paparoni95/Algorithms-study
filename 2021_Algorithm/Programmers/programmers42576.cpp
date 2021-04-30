#include <string>
#include <vector>
#include <map>
using namespace std;

// 완주하지 못한 선수
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    map<string, int> m;
    for (int i = 0; i < participant.size(); i++) {
        string name = participant[i];
        m[name]++;
    }

    for (int i = 0; i < completion.size(); i++) {
        string name = completion[i];
        m[name]--;
    }

    for (auto p : m) {
        if (p.second > 0) {
            answer = p.first;
            break;
        }
    }

    return answer;
}