#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 25;
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

int board[MAX][MAX];
bool visited[MAX][MAX];
int n;

int DFS(int x, int y) {
	int cnt = 1;
	visited[x][y] = 1;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!board[nx][ny]) continue;
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (!visited[nx][ny]) {
				cnt += DFS(nx, ny);
			}
		}
	}
	return cnt;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%1d", &board[i][j]);
		}
	}

	vector<int> answer;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visited[i][j] && board[i][j]) {
				answer.push_back(DFS(i, j));
			}
		}
	}

	sort(answer.begin(), answer.end());
	printf("%d\n", answer.size());
	for (int i = 0; i < answer.size(); ++i)
		printf("%d\n", answer[i]);

	return 0;
}