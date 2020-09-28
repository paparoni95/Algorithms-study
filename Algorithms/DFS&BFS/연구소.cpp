#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8][8];
int temp[8][8];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int result;

// DFS를 이용해 각 바이러스가 사방으로 퍼지도록 하기
void virus(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		// 상,하,좌,우 중에서 바이러스가 퍼질 수 있는 경우
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (temp[nx][ny] == 0) {
				// 해당 위치에 바이러스 배치하고, 다시 재귀적
				temp[nx][ny] = 2;
				virus(nx, ny);
			}
		}
	}
}

// 현재 맵에서 안전 영역의 크기를 계산하는 메서드
int GetScore() {
	int score = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) {
				score++;
			}
		}
	}

	return score;
}

// DFS를 이용해 울타리를 설치하면서, 매 번 안전 영역의 크기 계산
void DFS(int count) {
	// 울타리가 3개 설치된 경우
	if (count == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = arr[i][j];
			}
		}

		// 각 바이러스의 위치에서 전파 진행
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j] == 2) {
					virus(i, j);
				}
			}
		}

		// 안전 영역의 최대값 계산
		result = max(result, GetScore());
		return;
	}
	// 빈 공간에 울타리를 설치
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				DFS(count + 1);
				arr[i][j] = 0;
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	DFS(0);
	cout << result << '\n';
	return 0;
}