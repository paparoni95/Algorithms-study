#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[500][500]; // dp[i][j] : i번째 높이에 j번째 인덱스에 올 수 있는 최대값을 저장

int solution(vector<vector<int>> triangle) {
    
    //밑작업
    dp[0][0] = triangle[0][0];
    dp[1][0] = triangle[1][0] + dp[0][0];
    dp[1][1] = triangle[1][1] + dp[0][0];
    
    int triangle_height = triangle.size();
    
    for(int i = 2; i < triangle_height; ++i){          //현재 트리의 높이
        for(int j = 0; j < triangle[i].size(); ++j){   //해당 높이의 몇 번째 칸인지
            if(j == 0 || j == triangle[i].size() - 1){
                //첫번째나 맨 끝이면 위와 아래 더해주면 된다.
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }else{
                //그게 아니라면 2가지 중 max를 선택해서 저장한다.
                int temp = 0;
                for(int k = j - 1; k <= j; ++k){
                    temp = temp > dp[i - 1][k] ? temp : dp[i - 1][k];
                }
                dp[i][j] = temp + triangle[i][j];
            }
        }
    }
    
    int ans = 0;
    //가장 마지막 트리높이에서 가장 최대값이 정답이므로
    for(int i = 0; i < triangle_height; ++i){
        ans = ans > dp[triangle_height - 1][i] ? ans : dp[triangle_height - 1][i]; 
    }
    
    return ans;
}
