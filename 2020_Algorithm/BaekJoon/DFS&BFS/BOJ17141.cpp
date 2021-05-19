#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, answer = 987654321;
int board[51][51];
int copyBoard[51][51];
bool vis[51][51];

vector<pair<int, int>> virus;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void bfs(vector<int>& picked) {
	for (int i = 0; i < n; i++)
		fill(vis[i], vis[i] + n, false);

	queue<pair<int, int>> q;
	for (int i = 0; i < picked.size(); i++) {
		int x = virus[picked[i]].first;
		int y = virus[picked[i]].second;
		vis[x][y] = true;
		q.push({ x,y });
	}

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
				if (copyBoard[nx][ny] == 0 && !vis[nx][ny]) {
					copyBoard[nx][ny] = copyBoard[x][y] + 1;
					vis[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}

	int cnt = 0;
	bool isRight = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cnt < copyBoard[i][j])
				cnt = copyBoard[i][j];
			if (board[i][j] == 0 && !vis[i][j])
				isRight = false;
		}
	}

	if (isRight) {
		answer = min(answer, cnt);
	}
	return;
}

void dfs(int cnt, int index, vector<int>& picked, vector<int>& check) {
	if (cnt == m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				copyBoard[i][j] = board[i][j];
			}
		}
		bfs(picked);
		return;
	}

	for (int i = index; i < virus.size(); i++) {
		if (!check[i]) {
			check[i] = 1;
			picked.push_back(i);
			dfs(cnt + 1, index + 1, picked, check);
			picked.pop_back();
			check[i] = 0;
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
			if (board[i][j] == 1) board[i][j] = -1;
			if (board[i][j] == 2) {
				board[i][j] = 0;
				virus.push_back({ i,j });
			}
		}
	}

	vector<int> picked;
	vector<int> check(virus.size());
	dfs(0, 0, picked, check);

	if (answer == 987654321) cout << -1 << '\n';
	else cout << answer << '\n';
	return 0;
}