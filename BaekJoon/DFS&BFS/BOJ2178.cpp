#include <bits/stdc++.h>
using namespace std;

int board[101][101];
bool visited[101][101];
int n, m;

const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };
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

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = true;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny] || board[nx][ny] == 0) continue;
			q.push({ nx,ny });
			visited[nx][ny] = true;
			board[nx][ny] = board[cx][cy] + 1;
		}
	}

	cout << board[n - 1][m - 1];
	return 0;
}