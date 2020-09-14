#include <bits/stdc++.h>
using namespace std;

int m, n, h; // 가로, 세로, 높이
int board[101][101][101];
bool visited[101][101][101];

const int dx[] = { 0,0,1,-1,0,0 };
const int dy[] = { 1,-1,0,0,0,0 };
const int dz[] = { 0,0,0,0,1,-1 };
queue<tuple<int, int, int>> q;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> h;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) {
					q.push({ i,j,k });
					visited[i][j][k] = true;
					board[i][j][k] = 0;
				}
			}
		}
	}

	while (!q.empty()) {
		int z = get<0>(q.front());
		int x = get<1>(q.front());
		int y = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
			if (visited[nz][nx][ny] || board[nz][nx][ny] != 0) continue;
			visited[nz][nx][ny] = true;
			board[nz][nx][ny] = board[z][x][y] + 1;
			q.push({ nz,nx,ny });
		}
	}

	bool ok = true;
	int answer = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (!visited[i][j][k] && board[i][j][k] == 0) {
					ok = false;
					break;
				}
				if (visited[i][j][k] and answer < board[i][j][k])
					answer = board[i][j][k];
			}
			if (!ok) break;
		}
		if (!ok) break;
	}

	if (!ok) cout << -1;
	else cout << answer;
	return 0;
}