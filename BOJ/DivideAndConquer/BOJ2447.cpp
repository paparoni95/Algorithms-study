#include <iostream>
#include <cstring>
using namespace std;
//0, 3, 6, 9, 12, 15, 18, 21, 24

// 규칙은 다음과 같다.
/*

	3 * 3
	***
	* *
	***

	9 * 9
	*********
	* ** ** *
	*********
	***   ***
	* *   * *
	***   ***
	*********
	* ** ** *
	*********

	3 * 3의 경우에 8번만 더 붙여주면 9 * 9 가된다.
	27 * 27의 경우는 9 * 9에 8번만 더 붙여주면 27 * 27 이 된다.
	... 이후 반복
*/

/*
// 1번째 풀이 (분할 정복 풀이)
// 참조 링크 : https://m.blog.naver.com/PostView.nhn?blogId=moonsoo5522&logNo=220706431458&proxyReferer=https%3A%2F%2Fwww.google.com%2F

char mat[2201][2201];

void solve(int x, int y, int num) {
	if (num == 1) { // 한 칸이면 별로 색칠한다
		mat[x][y] = '*';
		return;
	}

	// 27 * 27 => 9 * 9 => 3 * 3 => 1 * 1
	int div = num / 3;
	// 판을 9분할로 나눈다.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				continue;
			else // 하나의 판을 다시 들어가서 9개로 분할한다.
				solve(x + (i * div), y + (j * div), div);
		}
	}
}

int main() {
	int n;
	cin >> n;

	memset(mat, ' ', sizeof(mat));

	solve(0, 0, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j];
		}
		cout << '\n';
	}
	return 0;
}

*/

// 2번째 풀이 (분할 정복)
// 참조 링크 : https://blockdmask.tistory.com/231

void Draw(int dx, int dy) {
	while (dy != 0) {
		if (dx % 3 == 1 && dy % 3 == 1) {
			cout << ' ';
			return;
		}
		dx /= 3;
		dy /= 3;
	}
	cout << '*';
}

int main() {
	int n;
	cin >> n;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			Draw(x, y);
		}
		cout << '\n';
	}
	return 0;
}