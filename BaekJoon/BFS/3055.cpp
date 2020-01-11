#include <iostream>
#include <queue>
using namespace std;

int pathMap[51][51];     //고슴도치 이동경로
int waterMap[51][51];    //물의 이동경로
int visited[51][51];     //고슴도치 방문경로
char originMap[51][51];  //지도
int dx[] = { 0,0,-1,1 }; //방향
int dy[] = { 1,-1,0,0 };
int R, C;                //행렬
int start_x, start_y;    //고슴도치 시작경로
int end_x, end_y;        //동굴 도착경로
bool check = false;      //동굴 도착여부
queue<pair<int, int>> water; //물 시작위치 저장

void waterBfs()
{
	while (!water.empty()) {
		int cx = water.front().first;
		int cy = water.front().second;
		water.pop();

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				/* 경로가 비어있는 곳이면 */
				if (originMap[nx][ny] == '.' && originMap[nx][ny] != 'D') {
					if (waterMap[nx][ny] == 0) {
						/* 그 경로를 카운터를 올려서 물로 채운다. */
						waterMap[nx][ny] = waterMap[cx][cy] + 1; //카운터 올려주기
						water.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

void HedgehogBfs(int start_x, int start_y)
{
	queue<pair<int, int>> hog;
	hog.push(make_pair(start_x, start_y));
	visited[start_x][start_y] = 1;
	while (!hog.empty()) {
		int cx = hog.front().first;
		int cy = hog.front().second;
		hog.pop();

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (originMap[nx][ny] == '.' || originMap[nx][ny] == 'D') {
					/* 이동하려는 경로가 물이 없는 곳이며, 방문하지 않았다면 */
					if (pathMap[nx][ny] == 0 && waterMap[nx][ny] == 0 && visited[nx][ny] == 0) {
						pathMap[nx][ny] = pathMap[cx][cy] + 1;
						visited[nx][ny] = 1;
						hog.push(make_pair(nx, ny));
					}
					/* 물이 퍼지는 속도가 고슴도치가 이동한 속도보다 크다면 동시에 방문하지 않았다면
					물이 퍼지기 전에 고슴도치가 이동할 수 있기 때문에 */
					else if ((waterMap[nx][ny] > pathMap[cx][cy] + 1) && visited[nx][ny] == 0) {
						pathMap[nx][ny] = pathMap[cx][cy] + 1;
						visited[nx][ny] = 1;
						hog.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

void printWaterMap()
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << waterMap[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}
void printPathMap()
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << pathMap[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> originMap[i][j];
			/* 고슴도치 시작 경로 저장 */
			if (originMap[i][j] == 'S') {
				start_x = i; start_y = j;
			}
			/* 물의 시작 경로 저장 */
			if (originMap[i][j] == '*') {
				water.push(make_pair(i, j));
			}
			/* 동굴의 도착 경로 저장 */
			if (originMap[i][j] == 'D') {
				end_x = i; end_y = j;
			}
		}
	}
	/* 물 이동 BFS */
	waterBfs();
	//printWaterMap();
	/* 고슴도치 이동 BFS */
	HedgehogBfs(start_x, start_y);
	//printPathMap();

	int ans = 0;
	/* 고슴도치가 동굴까지 간 거리 측정 */
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			/* 고슴도치가 동굴로 가지 못했다면 */
			if (end_x == i && end_y == j) {
				if (pathMap[i][j] == 0) {
					check = false;
				}
				else {
					ans = pathMap[i][j];
					check = true;
				}
			}
		}
	}
	/* 동굴을 도착했다면 값을 출력하고, 아니면 문자 출력 */
	if (check == false) {
		cout << "KAKTUS";
		return 0;
	}
	else {
		cout << ans;
	}

	return 0;
}