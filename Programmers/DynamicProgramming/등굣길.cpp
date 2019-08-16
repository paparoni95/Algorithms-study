#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dp[101][101]; // dp[i][j] : i행 j열의 최단 경로
int map[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            map[i][j] = 1;
        }
    }
    
    //폭우 표시
    for(int i = 0; i < puddles.size(); ++i){
        int col = puddles[i][0];
        int row = puddles[i][1];
        map[row][col] = 0;
    }
    //밑작업
    dp[0][1] = 0;
    dp[1][0] = 1;
    //아래서부터 채워나간다.
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(map[i][j] != 0)
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
            else
                dp[i][j] = 0;
        }
    }
    
    /*
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    */
    
    return dp[n][m] % 1000000007;
}
