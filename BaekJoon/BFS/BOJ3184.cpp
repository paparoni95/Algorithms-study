#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

const int map_size = 250;

char map[map_size][map_size];
int visit[map_size][map_size];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> wolfs;
queue<pair<int, int>> sheeps;
int row, col;
int sheep_count, wolf_count;

void Survival(int x, int y) {
	//이미 방문했다면 종료
	if (visit[x][y] == 1) return;

	int sheep = 0, wolf = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = 1;
	if (map[x][y] == 'v') wolf++;
	if (map[x][y] == 'o') sheep++;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
				if (map[nx][ny] == 'o' && visit[nx][ny] == 0) { //양
					++sheep;
					visit[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
				else if (map[nx][ny] == 'v' && visit[nx][ny] == 0) { //늑대
					++wolf;
					visit[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
				else {
					if (map[nx][ny] == '.' && visit[nx][ny] == 0) {
						visit[nx][ny] = 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}

	//양과 늑대가 싸움을 해서 승리한 쪽이 추가된다.
	bool win = sheep > wolf ? true : false;
	if (win) {
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
			else if (map[i][j] == 'o') {
				sheeps.push(make_pair(i, j));
			}
			else if (map[i][j] == '#') {
				visit[i][j] = 2;
			}
		}
	}
	/*
	cout << endl;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cout << visit[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	*/
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