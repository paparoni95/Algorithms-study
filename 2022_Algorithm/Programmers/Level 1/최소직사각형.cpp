#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 가장 큰 길이를 찾고, 모든 명함의 가로 길이를 가장 길게 잡은 상태에서
// 세로 길이 중 가장 큰 길이를 찾는다면 문제를 해결할 수 있다.
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int max_w = 0;
    int max_h = 0;
    for(int i = 0; i < sizes.size(); i++) {
        int w = sizes[i][0];
        int h = sizes[i][1];
        
        max_w = max(max_w, w);
        max_w = max(max_w, h);
        
        sort(sizes[i].begin(), sizes[i].end(), greater<int>());
        
        max_h = max(max_h, sizes[i][1]);
    }
    
    answer = max_w * max_h;
    return answer;
}
