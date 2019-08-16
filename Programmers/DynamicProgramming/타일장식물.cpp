#include <string>
#include <vector>

using namespace std;

long long dp[81]; //dp[i] : 타일의 개수가 i개일 때, 둘레의 길이

long long solution(int N) {
    
    dp[1] = 4, dp[2] = 6;
    for(int i = 3; i <= 80; ++i){
        dp[i] = dp[i - 1]+dp[i - 2];
    }
    return dp[N];
}
