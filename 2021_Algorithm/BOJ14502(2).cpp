#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, ans;
int maze[8][8];
int temp[8][8];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<pair<int, int> > virus;

void go(int cnt) {
	if (cnt == 3) {
		queue<pair<int, int>> q = virus;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				temp[i][j] = maze[i][j];
			}
		}
		while (!q.empty()) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (temp[nx][ny] == 0) {
					temp[nx][ny] = 2;
					q.push({ nx,ny });
				}
			}
		}

		int safe = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] == 0) safe++;
			}
		}

		ans = max(ans, safe);
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (maze[i][j] == 0) {
				maze[i][j] = 1;
				go(cnt + 1);
				maze[i][j] = 0;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 2) {
				virus.push({ i,j });
			}
		}
	}
	go(0);
	cout << ans << '\n';
	return 0;
}