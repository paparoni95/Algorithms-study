#include <vector>
#include <algorithm>
using namespace std;

int row, col;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool vis[101][101];

int dfs(vector<vector<int>>& picture, int x, int y, int color) {
    int area = 1;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= row || ny >= col) continue;
        if (picture[nx][ny] == color && vis[nx][ny] == false) {
            area += dfs(picture, nx, ny, color);
        }
    }
    return area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    row = m, col = n;
    fill(vis[0], vis[0] + 101 * 101, false);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0 && !vis[i][j]) {
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, dfs(picture, i, j, picture[i][j]));
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}