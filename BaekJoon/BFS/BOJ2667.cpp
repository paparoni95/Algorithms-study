#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[26][26];
int check[26][26];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

// 탐색하면서 num으로 색칠해주기
void bfs(int x, int y, int num) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = num;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (a[nx][ny] == 1 && check[nx][ny] == 0) {
					check[nx][ny] = num;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0 && a[i][j] == 1) {
				bfs(i, j, ++cnt);
			}
		}
	}

	cout << cnt << '\n';
	vector<int> v(cnt + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v[check[i][j]]++;
		}
	}

	// 집의 수를 오름차순으로
	sort(v.begin() + 1, v.end());
	for (int i = 1; i < v.size(); i++)
		cout << v[i] << '\n';
	return 0;
}