#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    map<string, int> mp;

    int index = 1;
    mp[words[0]]++;
    string prev = words[0];
    for (int i = 1; i < words.size(); i++, index++) {
        if (index == n) index = 0;
        // 이미 사전에 등록되어 있는 경우
        if (mp[words[i]] > 0) {
            answer[0] = index + 1;
            answer[1] = (i / n) + 1;
            break;
        }

        // 끝말잇기가 틀린 경우
        if (prev.back() != words[i].front()) {
            answer[0] = index + 1;
            answer[1] = (i / n) + 1;
            break;
        }
        else {
            prev = words[i];
            mp[words[i]]++;
        }
    }

    return answer;
}