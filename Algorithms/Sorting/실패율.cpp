#include <bits/stdc++.h>
using namespace std;

bool compare(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    sort(stages.begin(), stages.end());
    vector<pair<double, int> > result;
    for (int stage = 1; stage <= N; stage++) {
        int notClear = 0, clear = 0;
        for (int i = 0; i < stages.size(); i++) {
            if (stage <= stages[i]) {
                if (stage == stages[i]) notClear++;
                clear++;
            }
        }

        double fail = (clear == 0) ? 0 : notClear / (double)clear;
        result.push_back({ fail, stage });
    }

    sort(result.begin(), result.end(), compare);
    for (int i = 0; i < result.size(); i++) answer.push_back(result[i].second);
    return answer;
}