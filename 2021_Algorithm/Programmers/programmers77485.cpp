#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int> > board(rows + 1, vector<int>(columns + 1));
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            board[i][j] = ((i - 1) * columns + j);
        }
    }

    vector<int> answer;
    for (int i = 0; i < queries.size(); i++) {
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];
        int temp = board[x1][y1];
        int num = temp;

        for (int i = x1; i < x2; i++) {
            board[i][y1] = board[i + 1][y1];
            num = min(num, board[i][y1]);
        }

        for (int i = y1; i < y2; i++) {
            board[x2][i] = board[x2][i + 1];
            num = min(num, board[x2][i]);
        }

        for (int i = x2; i > x1; i--) {
            board[i][y2] = board[i - 1][y2];
            num = min(num, board[i][y2]);
        }

        for (int i = y2; i > y1; i--) {
            board[x1][i] = board[x1][i - 1];
            num = min(num, board[x1][i]);
        }

        board[x1][y1 + 1] = temp;

        answer.push_back(num);
    }
    return answer;
}