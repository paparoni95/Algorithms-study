#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// i행 j열의 최고점을 구하려면, 다시말해 land[i][j]의 값은?
// 이전 행에서의 j열을 제외한 나머지 열의 합에서 최대를 고르면 된다.
// 만약 j = 0 이라면,
// land[i-1][j+1], land[i-1][j+2], land[i-1][j+3] 이 중 max 값을 land[i][j]에 넣어준다.

int solution(vector<vector<int> > land)
{
    int value = 0;
    for (int i = 1; i < land.size(); ++i) {
        for (int j = 0; j < land[i].size(); ++j) {
            value = 0;
            for (int k = 0; k < land[i].size(); ++k) {
                if (k == j) continue;
                if (value < land[i - 1][k])
                    value = land[i - 1][k];
            }
            land[i][j] += value;
        }
    }

    int row = land.size() - 1;
    int answer = *max_element(land[row].begin(), land[row].end());
    return answer;
}