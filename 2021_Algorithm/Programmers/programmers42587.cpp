#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int, int> > dq;
    for (int i = 0; i < priorities.size(); i++) {
        dq.push_back({ priorities[i], i });
    }

    while (!dq.empty()) {
        int current_priority = dq.front().first;
        int current_location = dq.front().second;
        dq.pop_front();
        int max_priority = (*max_element(dq.begin(), dq.end())).first;
        if (current_priority >= max_priority) {
            answer++;
            if (current_location == location) return answer;
        }
        else {
            dq.push_back({ current_priority, current_location });
        }
    }

    return answer;
}