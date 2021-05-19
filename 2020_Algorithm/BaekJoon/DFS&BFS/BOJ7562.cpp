#include <bits/stdc++.h>
using namespace std;

int board[301][301];
bool visited[301][301];

const int dx[] = { -1,-2,-2,-1,1,2,1,2 };
const int dy[] = { -2,-1,1,2,2,1,-2,-1 };
int n;

int BFS(pair<int, int> start, pair<int, int> end){
	queue<pair<int, int>> q;
	visited[start.first][start.second] = true;
	q.push({ start.first,start.second });
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		if (cx == end.first && cy == end.second) {
			return board[cx][cy];
		}

		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = true;
			board[nx][ny] = board[cx][cy] + 1;
			q.push({ nx,ny });
		}
	}

	return -1;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		pair<int, int> start, end;
		cin >> start.first >> start.second;
		cin >> end.first >> end.second;
		cout << BFS(start, end) << '\n';

		for (int i = 0; i < n; i++){
			fill(board[i], board[i] + n, 0);
			fill(visited[i], visited[i] + n, false);
		}
	}

	return 0;
}