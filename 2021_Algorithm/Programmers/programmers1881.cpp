#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp1[100001]; // 첫번째 스티커를 뜯은 경우
int dp2[100001]; // 첫번째 스티커를 뜯지 않는 경우
int solution(vector<int> sticker)
{
    int n = sticker.size();
    if (n == 1) return sticker[0];

    //첫 번째 스티커를 뜯은 경우
    dp1[0] = sticker[0];
    dp1[1] = sticker[0];
    for (int i = 2; i < n - 1; i++) {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + sticker[i]);
    }

    //첫 번째 스티커를 뜯지 않는 경우
    dp2[0] = 0;
    dp2[1] = sticker[1];
    for (int i = 2; i < n; i++) {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[i]);
    }

    return max(dp1[n - 2], dp2[n - 1]);
}