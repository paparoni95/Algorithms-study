#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int map_size = 250;

char map[map_size][map_size];
int visit[map_size][map_size]; //방문여부
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int row, col;
int wolf_count, sheep_count;
queue<pair<int, int>> wolfs;
queue<pair<int, int>> sheeps;

void Survival(int x, int y) {
	if (visit[x][y]) return; //이미 방문을 했다면 종료

	int wolf = 0, sheep = 0;

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	if (map[x][y] == 'v') ++wolf;
	if (map[x][y] == 'k') ++sheep;
	visit[x][y] = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
				if (map[nx][ny] == 'v' && visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					++wolf;
					q.push(make_pair(nx, ny));
				}
				else if (map[nx][ny] == 'k' && visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					++sheep;
					q.push(make_pair(nx, ny));
				}
				else if (map[nx][ny] == '.' && visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	bool result = sheep > wolf ? true : false;
	if (result) {
		sheep_count += sheep;
	}
	else {
		wolf_count += wolf;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> row >> col;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> map[i][j];

			if (map[i][j] == 'v') {
				wolfs.push(make_pair(i, j));
			}
			else if (map[i][j] == 'k') {
				sheeps.push(make_pair(i, j));
			}
			else if (map[i][j] == '#') {
				visit[i][j] = 2; //벽이면
			}
		}
	}

	while (!wolfs.empty()) {
		int x = wolfs.front().first;
		int y = wolfs.front().second;
		wolfs.pop();
		Survival(x, y);
	}

	while (!sheeps.empty()) {
		int x = sheeps.front().first;
		int y = sheeps.front().second;
		sheeps.pop();
		Survival(x, y);
	}

	cout << sheep_count << ' ' << wolf_count;
	return 0;
}