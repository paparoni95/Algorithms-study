#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dfs
int m, n, k;
int block[102][102];
bool vis[102][102];
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

int dfs(int x, int y) {
	int cnt = 1;
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		if (vis[nx][ny] == false && block[nx][ny] == 0) {
			cnt += dfs(nx, ny);
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				block[i][j] = 1;
			}
		}
	}

	vector<int> ans;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == false && block[i][j] == 0) {
				ans.push_back(dfs(i, j));
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}