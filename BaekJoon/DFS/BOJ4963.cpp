#include <iostream>
#include <cstring>
using namespace std;

int a[50][50];
bool check[50][50];
int dx[] = { 1,-1,0,0,-1,-1,1,1 };
int dy[] = { 0,0,1,-1,-1,1,-1,1 };
int w, h;

void dfs(int x, int y) {
	check[x][y] = true;
	for (int k = 0; k < 8; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
			if (a[nx][ny] == 1 && check[nx][ny] == false) {
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		memset(a, 0, sizeof(a));
		memset(check, false, sizeof(check));
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> a[i][j];
			}
		}

		int ans = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i][j] == 1 && check[i][j] == false) {
					dfs(i, j);
					ans++;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}