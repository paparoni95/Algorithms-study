#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<pair<int, int> > q; // (progresses, speed_index)
    for (int i = 0; i < progresses.size(); i++) {
        q.push({ progresses[i], i });
    }

    while (!q.empty()) {
        int q_size = q.size();
        int cnt = 0;
        //전체 작업률 증가
        for (int i = 0; i < q_size; i++) {
            int progress = q.front().first;
            int speed_idx = q.front().second;
            q.pop();
            q.push({ progress + speeds[speed_idx], speed_idx });
        }
        //100% progress는 추출하기
        for (int i = 0; i < q_size; i++) {
            if (q.front().first >= 100) {
                q.pop();
                cnt++;
            }
        }

        if (cnt > 0) answer.push_back(cnt);
    }

    return answer;
}