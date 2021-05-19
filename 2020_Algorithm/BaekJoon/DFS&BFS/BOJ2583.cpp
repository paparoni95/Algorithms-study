#include <bits/stdc++.h>
using namespace std;

int m, n, k;
int board[101][101];

const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> k;

	while (k--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				board[i][j] = 1;
			}
		}
	}

	vector<int> answer;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0) {
				queue<pair<int, int>> q;
				q.push({ i,j });
				board[i][j] = 1;
				int cnt = 1;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
						if (board[nx][ny]) continue;
						board[nx][ny] = 1;
						cnt++;
						q.push({ nx,ny });
					}
				}
				answer.push_back(cnt);
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (auto n : answer) cout << n << ' ';
	return 0;
}