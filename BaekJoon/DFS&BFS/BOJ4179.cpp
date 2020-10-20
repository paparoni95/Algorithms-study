#include <iostream>
#include <queue>
#include <string>
using namespace std;

int r, c;
char board[1001][1001];
bool vis[1001][1001];

queue<pair<int, int>> person;
queue<pair<int, int>> fire;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void bfs() {
	int exitTime = 0;
	while (!person.empty()) {
		exitTime++;

		int fireSize = fire.size();
		for (int i = 0; i < fireSize; i++) {
			int x = fire.front().first;
			int y = fire.front().second;
			fire.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (board[nx][ny] == 'F' || board[nx][ny] == '#') continue;
				board[nx][ny] = 'F';
				fire.push({ nx,ny });
			}
		}

		int personSize = person.size();
		for (int i = 0; i < personSize; i++) {
			int x = person.front().first;
			int y = person.front().second;
			person.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
					cout << exitTime << '\n';
					return;
				}
				if (vis[nx][ny]) continue;
				if (board[nx][ny] == '.' || board[nx][ny] == 'J') {
					vis[nx][ny] = true;
					board[nx][ny] = 'J';
					person.push({ nx,ny });
				}
			}
		}


	}

	cout << "IMPOSSIBLE\n";
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			board[i][j] = str[j];
			if (board[i][j] == 'J') person.push({ i,j });
			else if (board[i][j] == 'F') fire.push({ i,j });
		}
	}

	bfs();
	return 0;
}