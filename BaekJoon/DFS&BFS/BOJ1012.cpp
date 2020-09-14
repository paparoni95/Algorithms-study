#include <bits/stdc++.h>
using namespace std;

int board[51][51];
bool visited[51][51];
int T, M, N, K; // tc, 가로, 세로, 배추위치

const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		for (int i = 0; i < 51; i++) {
			fill(board[i], board[i] + 51, 0);
			fill(visited[i], visited[i] + 51, false);
		}

		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int x, y; cin >> x >> y;
			board[y][x] = 1;
		}

		
		int answer = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] and !visited[i][j]) {
					answer++;
					queue<pair<int, int>> q;
					q.push({ i,j });
					visited[i][j] = true;
					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();

						for (int k = 0; k < 4; k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
							if (visited[nx][ny] || board[nx][ny] == 0) continue;
							q.push({ nx,ny });
							visited[nx][ny] = true;
						}
					}
				}
			}
		}

		cout << answer << '\n';
		
	} // end of TestCase
	return 0;
}