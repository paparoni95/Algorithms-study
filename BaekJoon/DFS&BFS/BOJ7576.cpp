#include <bits/stdc++.h>
using namespace std;

int m, n; // 가로,세로
int board[1001][1001];
bool visited[1001][1001];

const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.push({ i,j });
				board[i][j] = 0;
				visited[i][j] = true;
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] != 0 || visited[nx][ny]) continue;
			visited[nx][ny] = true;
			board[nx][ny] = board[x][y] + 1;
			q.push({ nx,ny });
		}
	}

	int answer = 0;
	bool ok = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (answer < board[i][j] && visited[i][j])
				answer = board[i][j];

			if (!visited[i][j] and board[i][j] == 0) {
				ok = false;
				break;
			}
		}
		if (!ok) break;
	}
	
	if (ok) cout << answer;
	else cout << -1;
	return 0;
}
