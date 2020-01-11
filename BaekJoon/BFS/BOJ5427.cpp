#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

#define SIZE 1000
using namespace std;

char map[SIZE][SIZE];    //빌딩 지도
int visit[SIZE][SIZE];   //방문 표시
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int h, w;

//맵 표시
void show(int time);
//bfs탐색
int mission(queue<pair<int, int>>& fires, int x, int y);

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;

	for (int testCase = 0; testCase < t; ++testCase) {
		cin >> w >> h;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));

		queue<pair<int, int>> fires; //불의 위치 저장
		int sx = 0, sy = 0;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> map[i][j];

				if (map[i][j] == '*') {
					fires.push(make_pair(i, j));
					visit[i][j] = 2; //불이라고 표시
				}
				else if (map[i][j] == '@') {
					sx = i, sy = j;
					visit[i][j] = 1; //사람이라고 표시
				}
			}
		}
		//불의 위치, 상근이의 출발점을 놓고 미션을 한다.
		int res = mission(fires, sx, sy);
		if (res > 0) { //탈출한다면 몇 초에 탈출 했는지
			cout << res << '\n';
		}
		else { //탈출을 하지 못했으면 불가능 표시
			cout << "IMPOSSIBLE" << '\n';
		}
	}
	return 0;
}

void show(int time) {
	cout << time << "초후" << endl;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cout << visit[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int mission(queue<pair<int, int>>& fires, int x, int y) {

	queue<pair<int, int>> human;
	human.push(make_pair(x, y));
	int time = 0;

	while (!human.empty()) {
		++time; // 1초 후

		//상근이 이동
		int size = human.size();
		for (int i = 0; i < size; ++i) {
			int cx = human.front().first;
			int cy = human.front().second;
			human.pop();

			//현재 위치가 만약에 불이라면 상근이는 갈 수 없는 곳이다.
			if (map[cx][cy] == '*') continue;

			//상근 이동
			for (int k = 0; k < 4; ++k) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				//탈출구는 경계 밖을 벗어나야 탈출했다고 할 수 있다.
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
					return time;
				}
				//상근이가 갈 수 있는 경로는 빈 공간이며, 방문하지 않았을 때
				if (map[nx][ny] == '.' && visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					human.push(make_pair(nx, ny));
				}
			}
		}

		//불의 이동도 해야한다.
		int cycle = fires.size();

		for (int i = 0; i < cycle; ++i) {
			int cx = fires.front().first;
			int cy = fires.front().second;
			fires.pop();

			for (int k = 0; k < 4; ++k) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				//경계 체크
				if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
					//불의 이동은 빈공간이면 이동한다.
					if (map[nx][ny] == '.') {
						map[nx][ny] = '*';
						visit[nx][ny] = 2;
						fires.push(make_pair(nx, ny));
					}
				}
			}
		}
		//show(time);
		//cout << '\n';
	}
	return 0;
}