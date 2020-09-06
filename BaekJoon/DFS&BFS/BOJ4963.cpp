#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 50;
const int dx[] = { 0,0,-1,1,-1,-1,1,1 };
const int dy[] = { -1,1,0,0,-1,1,-1,1 };
int board[MAX][MAX];
bool visited[MAX][MAX];
int w, h;

void DFS(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 8; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!board[nx][ny]) continue;
		if (visited[nx][ny]) continue;
		if (nx < 0 || nx >= h) continue;
		if (ny < 0 || ny >= w) continue;
		
		DFS(nx, ny);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		memset(board, 0, sizeof(board));
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> board[i][j];
			}
		}

		int answer = 0;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (!visited[i][j] && board[i][j]) {
					DFS(i, j);
					++answer;
				}
			}
		}
		cout << answer << '\n';
	}
	return 0;
}