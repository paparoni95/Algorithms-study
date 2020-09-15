#include <bits/stdc++.h>
using namespace std;

const int MAX = 201;
int K, W, H;
int board[MAX][MAX];
bool visited[MAX][MAX][31]; // [x][y][능력을 사용한 횟수]

const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };
const int sdx[] = { -1,-2,-2,-1,1,2,1,2 };
const int sdy[] = { -2,-1,1,2,-2,-1,2,1 };

int BFS() {
	queue<tuple<int,int,int,int>> q; // x,y,cnt,k
	q.push({ 0,0,0,0 });
	visited[0][0][0] = true;

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int cnt = get<2>(q.front());
		int k = get<3>(q.front());
		q.pop();

		if (x == H - 1 && y == W - 1) return cnt;

		// 능력을 아직 사용할 수 있다면
		if (k < K) {
			for (int i = 0; i < 8; i++) {
				int nx = x + sdx[i];
				int ny = y + sdy[i];
				if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
				// 능력을 사용하고 갈 수 있다면?
				if (board[nx][ny] == 0 && visited[nx][ny][k + 1] == false) {
					visited[nx][ny][k + 1] = true;
					q.push({ nx,ny,cnt + 1,k + 1 });
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
			if (board[nx][ny] == 0 && visited[nx][ny][k] == false) {
				visited[nx][ny][k] = true;
				q.push({ nx,ny,cnt + 1, k });
			}
		}
	}

	return -1;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> board[i][j];
		}
	}

	int answer = BFS();
	if (answer == -1) cout << -1 << '\n';
	else cout << answer << '\n';
	return 0;
}