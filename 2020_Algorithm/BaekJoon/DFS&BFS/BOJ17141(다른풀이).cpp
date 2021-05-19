// https://yabmoons.tistory.com/231
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, answer = 987654321;
int board[51][51];
bool vis[51][51];
bool choice[10];
vector<pair<int, int>> v;           // 바이러스의 좌표
vector<pair<int, int>> selectVirus; // 조합으로 선택한 바이러스의 좌표

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1) continue;
			// 바이러스가 아직 퍼지지 않은 곳이 있다면
			if (!vis[i][j]) return false;
		}
	}
	return true;
}

void bfs() {
	queue<pair<int, int>> q;
	for (int i = 0; i < selectVirus.size(); i++) {
		int x = selectVirus[i].first;
		int y = selectVirus[i].second;
		q.push({ x,y });
		vis[x][y] = true;
	}

	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (!vis[nx][ny] && board[nx][ny] != 1) {
					vis[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		if (q.size() != 0) cnt++;
	}
	if (check()) answer = min(answer, cnt);
}

void dfs(int index, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, false);
		bfs();
		return;
	}

	for (int i = index; i < v.size(); i++) {
		if (!choice[i]) {
			choice[i] = true;
			selectVirus.push_back(v[i]);
			dfs(index + 1, cnt + 1);
			selectVirus.pop_back();
			choice[i] = false;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) 
				v.push_back({ i,j });
		}
	}

	dfs(0, 0);

	if (answer == 987654321) cout << -1 << '\n';
	else cout << answer << '\n';
	return 0;
}