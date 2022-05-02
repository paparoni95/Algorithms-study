#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int scoreResult = -1;
vector<int> ryan, apeach, ryanResult;

pair<int, int> calculate() {
    pair<int, int> score = {0, 0}; // (ryan 점수, apeach 점수)
    for(int i = 0; i < 11; i++) {
        if (ryan[i] == apeach[i]) {
            if (ryan[i] == 0 && apeach[i] == 0)
                continue;
            else
                score.second += (10 - i);
        }
        else {
            if (ryan[i] > apeach[i])
                score.first += (10 - i);
            else
                score.second += (10 - i);
        }
    }
    return score;
}

void check() {
    pair<int, int> score = calculate();
    int ryanScore = score.first;
    int apeachScore = score.second;
    int diff = ryanScore - apeachScore;
    
    if (diff <= 0) return;
    
    if (scoreResult == -1) {
        scoreResult = diff;
        ryanResult = ryan;
    }
    else {
        // 같은 정답이지만 더 낮은 점수로만 모여있는지 체크한다.
        if (scoreResult == diff) {
            for(int i = 10; i >= 0; i--) {
                if (ryan[i] != 0 && ryanResult[i] == 0) {
                    ryanResult = ryan;
                    break;
                }
                else if (ryan[i] == 0 && ryanResult[i] != 0) {
                    break;
                }
                else if (ryan[i] != 0 && ryanResult[i] != 0) {
                    if (ryan[i] != ryanResult[i]) {
                        ryanResult = ryan[i] > ryanResult[i] ? ryan : ryanResult;
                        break;
                    }
                }
            }
        }
        else if (scoreResult < diff) {
            scoreResult = diff;
            ryanResult = ryan;
        }
    }
}

// cnt : 쏜 화살 갯수
// idx : 몇점 과녁 인지
// n   : base conditon 체크 (총 화살의 갯수)
void dfs(int cnt, int idx, int n) {
    if (cnt == n) {
        check();
        return;
    }
    
    int now = n - cnt;
    // 0점 과녁이라면 모두 소진하자.
    if (idx == 10) {
        ryan[idx] = now;
        dfs(cnt + now, idx + 1, n);
        ryan[idx] = 0;
    }
    // 어피치를 반드시 이겨야 하는 조건에서만 화살을 소비하자.
    else {
        if (apeach[idx] + 1 <= now) {
            // 라이언은 무조건 어피치보다는 1발 더 쏴야 한다.
            ryan[idx] = apeach[idx] + 1;
            dfs(cnt + apeach[idx] + 1, idx + 1, n);
            ryan[idx] = 0;
        }
        
        // 화살을 소비하지 않고 넘어가는 경우도 생각해야 한다.
        dfs(cnt, idx + 1, n);
    }
}

// 라이언이 어떻게 하면 가장 큰 점수차로 이길 수 있을지 구하여야 한다.
// '얍문'님의 풀이 방법을 참고.
// 순열을 생각했는데, 그게 아니고 DFS(재귀)로 접근하자.
// 주말에 다시 풀어보기.
vector<int> solution(int n, vector<int> info) {
    ryan.resize(11, 0);
    apeach = info;
    dfs(0, 0, n);
    
    if (scoreResult == -1) {
        ryanResult.push_back(-1);
    }
    
    return ryanResult;
}
