#include <bits/stdc++.h>
using namespace std;

int board[301][301];
int copy_board[301][301];
bool visited[301][301];

const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };
int n, m;

void DFS(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (visited[nx][ny] || board[nx][ny] == 0) continue;
		DFS(nx, ny);
	}
}

int GetComponent() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] > 0 && !visited[i][j]) {
				DFS(i, j);
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int year = 0;
	while (1) {
		year++;

		for (int i = 0; i < n; i++)
			fill(visited[i], visited[i] + m, false);

		// 복사
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				copy_board[i][j] = board[i][j];
			}
		}

		// 빙산을 녹이기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] > 0) {
					int cnt = 0;
					// 해당 빙산을 기준으로 상하좌우 바다인지 확인
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (board[nx][ny] == 0) cnt++;
					}

					// 빙산 - 인접해있는 바다의 수
					copy_board[i][j] -= cnt;
					if (copy_board[i][j] < 0) copy_board[i][j] = 0;
				}
			}
		}
		
		// 복사
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j] = copy_board[i][j];
			}
		}

		// 빙산이 두 덩어리 이상으로 쪼개지는지 확인
		int cnt = GetComponent();
		if (cnt > 1) {
			cout << year;
			break;
		}
		// 빙산이 다 녹아 없어지면 이것은 예외처리
		if (cnt == 0) {
			cout << 0;
			break;
		}
	}
	return 0;
}