#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[1001][1001];
bool visited[1001][1001][2]; // [x][y][벽을 부순 횟수]

const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

int BFS()
{
	// (x, y, 벽을 부순 횟수, 카운트)
	queue<tuple<int, int, int, int>> q;
	q.push({ 0,0,0,1 });
	visited[0][0][0] = true;
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int b = get<2>(q.front());
		int cnt = get<3>(q.front());
		q.pop();

		if (x == n - 1 && y == m - 1) return cnt;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			// 만약 이동하려는 칸이 벽이고, 벽을 아직 부수지 않았다면
			if (board[nx][ny] == 1 && b == 0) {
				// 벽을 부수고 이동
				visited[nx][ny][b + 1] = true;
				q.push({ nx,ny,b + 1,cnt + 1 });
			}
			// 만약 이동하려는 칸이 빈칸이고, 벽을 부수고 왔는지, 아닌지에서도
			// 방문을 했으면 패스하고, 아니라면 다음으로 진행한다.
			if (board[nx][ny] == 0 && visited[nx][ny][b] == false) {
				visited[nx][ny][b] = true;
				q.push({ nx,ny,b,cnt + 1 });
			}
		}
	}

	return -1;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			board[i][j] = str[j] - '0';
		}
	}

	cout << BFS() << '\n';
	return 0;
}