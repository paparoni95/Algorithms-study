// https://yabmoons.tistory.com/596?category=944371 ÂüÁ¶
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> board;

void dfs(int x, int y, int size, vector<int>& answer) {
    bool isZero = true, isOne = true;
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (board[i][j] == 0) isOne = false;
            if (board[i][j] == 1) isZero = false;
        }
    }

    if (isZero) {
        answer[0]++;
        return;
    }
    if (isOne) {
        answer[1]++;
        return;
    }

    dfs(x, y, size / 2, answer);
    dfs(x, y + size / 2, size / 2, answer);
    dfs(x + size / 2, y, size / 2, answer);
    dfs(x + size / 2, y + size / 2, size / 2, answer);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    board = arr;
    dfs(0, 0, arr.size(), answer);
    return answer;
}