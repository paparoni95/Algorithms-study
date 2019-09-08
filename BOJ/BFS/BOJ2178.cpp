#include <iostream>
#include <queue>
using namespace std;

int n, m;
int a[100][100];
int b[100][100];
bool check[100][100];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	check[x][y] = true;
	b[x][y] = 1;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (a[nx][ny] == 1 && check[nx][ny] == false) {
					check[nx][ny] = true;
					b[nx][ny] = b[cx][cy] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	bfs(0, 0);
	cout << b[n - 1][m - 1];

	return 0;
}