#include <iostream>
#define SIZE 50
using namespace std;

int dx[] = { 0,1,1 };
int dy[] = { 1,0,1 };
int a[SIZE][SIZE];

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%1d", &a[i][j]);
		}
	}

	int ans = 1, temp = 0;
	//사각형을 만들 수 있는지 체크
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int cx = i, cy = j; //현재 위치
			temp = 0; //구한 면적의 값
			for (int k = 1; k <= N - 1; ++k) {
				int nx1 = cx + (dx[0] * k);
				int ny1 = cy + (dy[0] * k);
				int nx2 = cx + (dx[1] * k);
				int ny2 = cy + (dy[1] * k);
				int nx3 = cx + (dx[2] * k);
				int ny3 = cy + (dy[2] * k);
				if (nx1 < 0 || nx1 >= N) continue;
				if (nx2 < 0 || nx2 >= N) continue;
				if (nx3 < 0 || nx3 >= N) continue;
				if (ny1 < 0 || ny1 >= M) continue;
				if (ny2 < 0 || ny2 >= M) continue;
				if (ny3 < 0 || ny3 >= M) continue;
				if (a[cx][cy] == a[nx1][ny1] && a[cx][cy] == a[nx2][ny2] && a[cx][cy] == a[nx3][ny3]) {
					temp = (k + 1) * (k + 1);
					if (ans < temp) ans = temp;
				}
			}
		}
	}
	cout << ans;
	return 0;
}