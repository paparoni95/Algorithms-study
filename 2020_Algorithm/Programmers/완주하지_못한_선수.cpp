#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    // hash map 사용
    unordered_map<string, int> hash;

    // 참가자들을 우선 증가 시킨다.
    for (string name : participant)
        ++hash[name];
    
    // 완주한 선수들을 감소 시킨다.
    for (string name : completion)
        --hash[name];

    // hash map을 돌면서
    for (auto elem : hash)
    {
        // 참가자들이 완주를 했다면 0이지만, 그럼에도 완주하지 못했다면?
        if (elem.second > 0)
        {
            answer = elem.first;
            break;
        }
    }

    return answer;
}