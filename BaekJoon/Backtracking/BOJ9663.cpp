#include <iostream>
#include <vector>
using namespace std;

int n, answer;
int col[16]; // 1 ~ 15

// 1행 ~ row-1행까지 같은 열 혹은 대각선에 위치하는 퀸이 있는지 확인한다.
bool Promising(int row) {
	for (int i = 1; i < row; ++i) {
		// i행과 row행의 열 값이 같으면 퀸을 놓을 수 없다.
		if (col[i] == col[row])
			return false;

		// i행과 row행의 열 값이 대각선에 위치하는 절대값이면 안된다.
		if (abs(i - row) == abs(col[i] - col[row]))
			return false;
	}

	return true;
}

// row행까지는 퀸을 놓은 상태
// row+1행에 퀸을 놓을 수 있는지 없는지 확인
// 만약 row 값이 n과 같다면 모든 행에 퀸을 놓았다는 뜻이므로 answer + 1
void DFS(int row) {
	if (row == n) {
		++answer;
		return;
	}

	for (int i = 1; i <= n; ++i) {
		col[row + 1] = i; // row+1행 i열에 둔다.
		if (Promising(row + 1)) {
			DFS(row + 1);
		}
		col[row + 1] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	// 각 1행에 1열 ~ n열까지 돌면서 퀸을 놓았을 때 가능한 여부를 확인한다.
	for (int i = 1; i <= n; ++i) {
		// 1행 i열에 퀸을 놓았다.
		col[1] = i;
		// 1행 i열에 퀸을 놓았을 경우 가능한 횟수를 구한다.
		DFS(1);
	}


	cout << answer;
	return 0;
}