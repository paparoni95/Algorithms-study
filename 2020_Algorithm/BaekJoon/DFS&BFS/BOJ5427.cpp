#include <bits/stdc++.h>
using namespace std;

int w, h;
char board[1001][1001];
bool visited[1001][1001];

pair<int, int> man;
queue<pair<int, int>> fire;

const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

int BFS() {
	visited[man.first][man.second] = true;
	queue<tuple<int,int,int>> q; // (x,y,cnt)
	q.push({ man.first, man.second, 1 });

	while (!q.empty()) { 
		// 불 먼저 번지게 하고,
		int fire_size = fire.size();
		for (int i = 0; i < fire_size; i++) {
			int x = fire.front().first;
			int y = fire.front().second;
			fire.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (board[nx][ny] == '.' || board[nx][ny] == '@') {
					board[nx][ny] = '*';
					fire.push({ nx,ny });
				}
			}
		}
		
		// 상근이 이동
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int x = get<0>(q.front());
			int y = get<1>(q.front());
			int cnt = get<2>(q.front());
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				// 탈출한다면
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
					return cnt;
				}
				if (visited[nx][ny]) continue;
				if (board[nx][ny] == '.') {
					visited[nx][ny] = true;
					board[nx][ny] = '@';
					q.push({ nx,ny,cnt + 1 });
				}
			}
		}
	}

	// 상근이가 탈출할 수 없다면
	return -1;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 1001; i++) fill(visited[i], visited[i] + 1001, false);
		fire = queue<pair<int, int>>();

		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < str.length(); j++) {
				board[i][j] = str[j];
				if (str[j] == '@') {
					man = { i,j };
				}
				else if (str[j] == '*') {
					fire.push({ i,j });
				}
			}
		}

		int sec = BFS();
		if (sec == -1) cout << "IMPOSSIBLE\n";
		else cout << sec << '\n';
	}
	
	return 0;
}