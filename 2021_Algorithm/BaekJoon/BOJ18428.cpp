#include <iostream>
#include <iostream>
#include <vector>
using namespace std;

int n;
char maze[6][6];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<pair<int, int>> teacher;
bool ok;
void dfs(int cnt) {
	if (cnt == 3) {
		bool found = false;
		for (int i = 0; i < teacher.size(); i++) {
			int x = teacher[i].first;
			int y = teacher[i].second;
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				while (true) {
					if (nx < 0 || ny < 0 || nx >= n || ny >= n || maze[nx][ny] == 'O') break;
					if (maze[nx][ny] == 'S') {
						found = true;
						break;
					}

					nx = nx + dx[j];
					ny = ny + dy[j];
				}
			}
		}

		if (!found) ok = true;
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (maze[i][j] == 'X') {
				maze[i][j] = 'O';
				dfs(cnt + 1);
				maze[i][j] = 'X';
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'T') {
				teacher.push_back({ i,j });
			}
		}
	}
	dfs(0);
	if (ok) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}