#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    int person_num = 0;
    set<string> s;
    string previous;
    for (int i = 0; i < words.size(); i++) {
        person_num = i % n;
        if (previous == "") previous = words[i];
        else if (previous.back() != words[i].front() || s.find(words[i]) != s.end()) {
            answer[0] = person_num + 1;
            answer[1] = i / n + 1;
            break;
        }
        s.insert(words[i]);
        previous = words[i];
    }
    return answer;
}