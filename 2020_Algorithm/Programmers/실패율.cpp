#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<double, int>& a, pair<double, int>& b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int> > v;
    sort(stages.begin(), stages.end());

    for (int stage = 1; stage <= N; stage++) {
        int notClearPlayer = 0;
        int stagePlayer = 0;
        for (int i = 0; i < stages.size(); i++) {
            if (stage <= stages[i]) stagePlayer++;
            if (stage == stages[i]) notClearPlayer++;
        }

        double failure;
        if (stagePlayer == 0) failure = 0;
        else failure = (double)notClearPlayer / stagePlayer;
        v.push_back({ failure, stage });
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++) {
        answer.push_back(v[i].second);
    }

    return answer;
}