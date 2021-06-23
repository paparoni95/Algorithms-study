#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int W, H, K;
int maze[200][200];
bool vis[200][200][31];

int hx[] = { -1,-2,-2,-1,1,2,2,1 };
int hy[] = { -2,-1,1,2,-2,-1,1,2 };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct Monkey {
	int x, y, k, cost;
};

int move() {
	queue<Monkey> q;
	q.push({ 0,0,0,0 });
	vis[0][0][0] = 0;
	while (!q.empty()) {
		Monkey cur = q.front();
		q.pop();

		if (cur.x == H - 1 && cur.y == W - 1)
			return cur.cost;

		if (cur.k < K) {
			for (int i = 0; i < 8; i++) {
				int nx = cur.x + hx[i];
				int ny = cur.y + hy[i];
				if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
				if (maze[nx][ny]) continue;
				if (vis[nx][ny][cur.k + 1] == false) {
					vis[nx][ny][cur.k + 1] = true;
					q.push({ nx,ny,cur.k + 1,cur.cost + 1 });
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
			if (maze[nx][ny]) continue;
			if (vis[nx][ny][cur.k] == false) {
				vis[nx][ny][cur.k] = true;
				q.push({ nx,ny,cur.k,cur.cost + 1 });
			}
		}
	}

	return -1;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> maze[i][j];
		}
	}

	cout << move() << '\n';
	return 0;
}