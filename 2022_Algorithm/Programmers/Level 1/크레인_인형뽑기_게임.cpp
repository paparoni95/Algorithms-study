#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

// [0,0,0,0,0] (0, 0)
// [0,0,1,0,3] (1, 0)
// [0,2,5,0,1] (2, 0)
// [4,2,4,4,2] (3, 0)
// [3,5,1,3,1] (4, 0)
// 크레인을 모두 작동시킨 후 터트려져 사라진 인형의 개수를 리턴하자.
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    int n = board.size();
    vector<stack<int>> bucket;
    for(int i = 0; i < n; i++) {
        stack<int> st;
        for(int j = n - 1; j >= 0; j--) {
            if (board[j][i] == 0) continue;
            st.push(board[j][i]);
        }
        bucket.push_back(st);
    }
    
    stack<int> result; // 넣을 장소 
    for(int i = 0; i < moves.size(); i++) {
        int index = moves[i];
        --index; // zero base
        
        if (bucket[index].empty()) continue;
        
        int top_item = bucket[index].top();
        bucket[index].pop();
        
        if (result.empty()) {
            result.push(top_item);
            continue;
        }
        
        if (result.top() == top_item) {
            result.pop();
            answer += 2;
        }
        else {
            result.push(top_item);
        }
    }
    
    return answer;
}
