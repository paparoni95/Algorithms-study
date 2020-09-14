#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[501][501];
bool visited[501][501];

const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

int BFS(int x, int y) {
	int cnt = 1; // 넓이
	queue<pair<int, int>> q; 
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny] || board[nx][ny] == 0) continue;

			cnt++;
			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}

	return cnt;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int max_area = 0, area_cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && board[i][j]) {
				max_area = max(max_area, BFS(i, j));
				area_cnt++;
			}
		}
	}

	cout << area_cnt << '\n' << max_area;
	return 0;
}
