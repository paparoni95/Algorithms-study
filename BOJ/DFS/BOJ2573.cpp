#include <iostream>
#define MAX_SIZE 301
using namespace std;

int iceBerg[MAX_SIZE][MAX_SIZE];
int copyIceBerg[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

//빙산 탐험
void dfs(int x, int y, int row, int col) {
	visit[x][y] = true;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (visit[nx][ny] == true) continue;
		if (nx < 0 || nx >= row) continue;
		if (ny < 0 || ny >= col) continue;
		if(iceBerg[nx][ny] > 0)
			dfs(nx, ny, row, col);
	}
}

bool solve(int row, int col) {
	int iceBergCnt = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (iceBerg[i][j] > 0 && visit[i][j] == false) {
				iceBergCnt++; //빙산 수 증가
				dfs(i, j, row, col);
			}
			if (iceBergCnt >= 2) return true; //빙산이 2조각 이상이면
		}
	}
	return false;
}

//빙산 녹이기
void melt(int row, int col) {
	int waterCnt = 0; //인접해있는 바닷물의 수
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (iceBerg[i][j] > 0) {
				for (int dir = 0; dir < 4; dir++) { //상하좌우 확인해서 바닷물이면
					int ni = i + dx[dir];
					int nj = j + dy[dir];
					if (ni < 0 || ni >= row) continue;
					if (nj < 0 || nj >= col) continue;
					if (iceBerg[ni][nj] == 0) waterCnt++;
				}
				if (iceBerg[i][j] >= waterCnt) { //빙산이 인접한 바닷물만큼 녹는다.
					copyIceBerg[i][j] -= waterCnt;
					waterCnt = 0;
				}
				else {
					copyIceBerg[i][j] = 0;
					waterCnt = 0;
				}
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			iceBerg[i][j] = copyIceBerg[i][j];
		}
	}
}

//빙산이 남아있는지
bool iceCheck(int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (iceBerg[i][j] > 0)
				return true;
		}
	}
	return false;
}

//방문 초기화
void visitInit(int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			visit[i][j] = false;
		}
	}
}

void showMap(int row, int col) {
	cout << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << iceBerg[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> iceBerg[i][j];
			copyIceBerg[i][j] = iceBerg[i][j];
		}
	}
	int ans = 0;
	bool ret = false;
	while (iceCheck(N, M)) {
		ans++; //1년후
		visitInit(N, M); //초기화
		melt(N, M); //빙산 녹이기
		ret = solve(N, M);
		//showMap(N, M);
		if (ret == true) break;
	}

	if (ret == false) {
		cout << 0;
		return 0;
	}
	else {
		cout << ans;
	}
	return 0;
}