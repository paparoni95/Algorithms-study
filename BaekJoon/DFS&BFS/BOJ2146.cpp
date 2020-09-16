#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;
const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

int N;
int board[MAX][MAX];
bool visited[MAX][MAX];

void Initialize() {
	for (int i = 0; i < N; i++) {
		fill(visited[i], visited[i] + N, false);
	}
}

int LinkedBridge(int mark) {
	Initialize();
	queue<tuple<int, int, int>> q; // x,y,cnt
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == mark) {
				q.push({ i,j,0 });
			}
		}
	}

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int cnt = get<2>(q.front());
		q.pop();

		// 다른 육지를 발견했다면
		if (board[x][y] != 0 && board[x][y] != mark) {
			return cnt - 1;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = true;
			q.push({ nx,ny,cnt + 1 });
		}
	}
	// 다리를 연결할 수 없다면
	return 0;
}

void FindLand(int x, int y, int mark)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	board[x][y] = mark;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny]) continue;
			if (board[nx][ny] == -1) {
				board[nx][ny] = mark;
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

void Show() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) 
				board[i][j] = -1;
		}
	}

	int num = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == -1 && !visited[i][j])
				FindLand(i, j, num++);
		}
	}

	int answer = 987654321;
	for (int i = 1; i < num; i++) {
		//cout << LinkedBridge(i) << '\n';
		answer = min(answer, LinkedBridge(i));
	}
	cout << answer << '\n';
	return 0;
}