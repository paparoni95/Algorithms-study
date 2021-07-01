#include <iostream>
using namespace std;

const int SIZE = 10;
// backtracking
// 다음에 다시 풀어보기
int board[SIZE][SIZE];
bool chk1[SIZE][SIZE]; // 가로 체크
bool chk2[SIZE][SIZE]; // 세로 체크
bool chk3[SIZE][SIZE]; // 3 x 3 체크

void dfs(int cnt) {
	int x = cnt / 9;
	int y = cnt % 9;

	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		// 백트래킹의 경우 여러가지 방면으로 답이 도출될 수 있는데,
		// 이 명령을 사용하면 프로그램 수행을 끝내게 해준다.
		// 즉 다음의 탐색과정 없이 바로 프로그램 종료
		exit(0); 
	}

	if (board[x][y] == 0) {
		for (int i = 1; i <= 9; i++) {
			// x행에서 0 ~ 9 확인
			// y열에서 0 ~ 9 확인
			// 3 x 3 확인
			if (chk1[x][i] == false && chk2[y][i] == false && chk3[(x / 3) * 3 + (y / 3)][i] == false) {
				chk1[x][i] = true;
				chk2[y][i] = true;
				chk3[(x / 3) * 3 + (y / 3)][i] = true;
				board[x][y] = i;
				dfs(cnt + 1);
				chk1[x][i] = false;
				chk2[y][i] = false;
				chk3[(x / 3) * 3 + (y / 3)][i] = false;
				board[x][y] = 0;
			}
		}
	}
	else
		dfs(cnt + 1);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] > 0) {
				chk1[i][board[i][j]] = true;
				chk2[j][board[i][j]] = true;
				chk3[(i / 3) * 3 + (j / 3)][board[i][j]] = true;
			}
		}
	}

	dfs(0);

	return 0;
}