#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int M, N, H;
int maze[101][101][101];
int vis[101][101][101];
int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };

struct Pos {
	int z, x, y;
};

void init() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			for (int k = 0; k < 101; k++) {
				vis[i][j][k] = -1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	init();
	cin >> M >> N >> H;
	int zeroTomato = 0;
	queue<Pos> q;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> maze[i][j][k];
				if (maze[i][j][k] == 1) {
					q.push({ i,j,k });
					vis[i][j][k] = 1;
				}
				else if (maze[i][j][k] == 0) {
					zeroTomato++;
				}
			}
		}
	}

	if (zeroTomato == 0) {
		cout << "0\n";
		return 0;
	}

	while (!q.empty()) {
		int sz = q.size();
		for (int tomato = 0; tomato < sz; tomato++) {
			Pos cur = q.front();
			q.pop();

			for (int i = 0; i < 6; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				int nz = cur.z + dz[i];
				if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;
				if (maze[nz][nx][ny] == 0 && vis[nz][nx][ny] == -1) {
					vis[nz][nx][ny] = vis[cur.z][cur.x][cur.y] + 1;
					maze[nz][nx][ny] = 1;
					q.push({ nz,nx,ny });
				}
			}
		}
	}

	int day = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (maze[i][j][k] == 0) {
					cout << "-1\n";
					return 0;
				}
				day = max(day, vis[i][j][k]);
			}
		}
	}

	cout << day - 1 << '\n';
	return 0;
}
