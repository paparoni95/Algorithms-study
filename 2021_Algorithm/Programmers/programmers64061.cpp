#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

stack<int> st[31];
stack<int> ret;
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int len = board.size();
    for (int i = len - 1; i >= 0; i--) {
        for (int j = 0; j < len; j++) {
            if (board[i][j] != 0)
                st[j + 1].push(board[i][j]);
        }
    }

    for (int i = 0; i < moves.size(); i++) {
        int idx = moves[i];
        if (!st[idx].empty()) {
            if (!ret.empty() && ret.top() == st[idx].top()) {
                ret.pop();
                answer += 2;
            }
            else {
                ret.push(st[idx].top());
            }
            st[idx].pop();
        }
    }
    return answer;
}