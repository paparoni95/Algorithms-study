#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001][4];
int solution(vector<vector<int> > land)
{
    int ans = 0;
    int row = land.size();
    for (int i = 0; i < 4; i++) {
        dp[0][i] = land[0][i];
    }

    for (int i = 1; i < row; i++) {
        for (int j = 0; j < 4; j++) {
            if (j == 0)
                dp[i][j] = max(dp[i - 1][1], max(dp[i - 1][2], dp[i - 1][3])) + land[i][j];
            else if (j == 1)
                dp[i][j] = max(dp[i - 1][0], max(dp[i - 1][2], dp[i - 1][3])) + land[i][j];
            else if (j == 2)
                dp[i][j] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][3])) + land[i][j];
            else
                dp[i][j] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + land[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        ans = max(dp[row - 1][i], ans);
    }

    return ans;
}