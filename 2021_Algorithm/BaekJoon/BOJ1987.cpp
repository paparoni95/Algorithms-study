#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int r, c, ans;
char maze[21][21];
bool vis[26];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void dfs(int x, int y, int cnt) {
	ans = max(ans, cnt);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		if (vis[maze[nx][ny] - 'A'] == false) {
			vis[maze[nx][ny] - 'A'] = true;
			dfs(nx, ny, cnt + 1);
			vis[maze[nx][ny] - 'A'] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> maze[i][j];
		}
	}
	vis[maze[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << ans << '\n';
	return 0;
}