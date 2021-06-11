#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int r, c, t, ans, sx, sy;
char maze[101][101];
bool alpha[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void dfs(int x, int y, int time, int cnt) {
	if (time == t) {
		ans = max(ans, cnt);
		return;
	}

	alpha[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		if (maze[nx][ny] == '#') continue;
		//방문을 한 상태라도 다시 갈 수 있다.
		if (alpha[nx][ny]) {
			dfs(nx, ny, time + 1, cnt);
		}
		else if (maze[nx][ny] == 'S') {
			dfs(nx, ny, time + 1, cnt + 1);
			//고구마를 먹었을 경우를 돌아오게되면 방문을 해제하자.
			alpha[nx][ny] = false;
		}
		else {
			dfs(nx, ny, time + 1, cnt);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'G') {
				sx = i;
				sy = j;
			}
		}
	}

	dfs(sx, sy, 0, 0);
	cout << ans << '\n';
	return 0;
}