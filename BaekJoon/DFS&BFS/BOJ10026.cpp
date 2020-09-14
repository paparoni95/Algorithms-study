#include <bits/stdc++.h>
using namespace std;

char board[101][101];
bool visited[101][101];
int n;

const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };


void DFS(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (visited[nx][ny]) continue;
		if (board[nx][ny] == board[x][y]) DFS(nx, ny);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++)
			board[i][j] = str[j];
	}

	int answer1 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				DFS(i, j);
				answer1++;
			}
		}
	}

	for (int i = 0; i < n; i++)
		fill(visited[i], visited[i] + n, false);

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'G') board[i][j] = 'R';
		}
	}

	int answer2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				DFS(i, j);
				answer2++;
			}
		}
	}

	cout << answer1 << ' ' << answer2;
	return 0;
}