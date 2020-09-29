#include <bits/stdc++.h>
using namespace std;

int n;
char board[6][6];
vector<pair<int, int>> teachers;
vector<pair<int, int>> spaces;

bool found; // 학생이 한 명도 감지되지 않도록 설치할 수 있는지의 여부

// 특정 방향으로 감시를 진행 (학생 발견: true, 학생 미발견: false)
bool watch(int x, int y, int direction) {
	// 왼쪽 방향으로 감시
	if (direction == 0) {
		while (y >= 0) {
			// 학생이 있는 경우
			if (board[x][y] == 'S') return true;
			// 장애물이 있는 경우
			if (board[x][y] == 'O') return false;
			y--;
		}
	}
	// 오른쪽 방향으로 감시
	if (direction == 1) {
		while (y < n) {
			// 학생이 있는 경우
			if (board[x][y] == 'S') return true;
			// 장애물이 있는 경우
			if (board[x][y] == 'O') return false;
			y++;
		}
	}
	// 위쪽 방향으로 감시
	if (direction == 2) {
		while (x >= 0) {
			// 학생이 있는 경우
			if (board[x][y] == 'S') return true;
			// 장애물이 있는 경우
			if (board[x][y] == 'O') return false;
			x--;
		}
	}
	// 아래쪽 방향으로 감시
	if (direction == 3) {
		while (x < n) {
			// 학생이 있는 경우
			if (board[x][y] == 'S') return true;
			// 장애물이 있는 경우
			if (board[x][y] == 'O') return false;
			x++;
		}
	}
	return false;
}

// 장애물 설치 이후에, 한 명이라도 학생이 감지되는지 검사
bool process() {
	// 모든 선생의 위치를 하나씩 확인
	for (int i = 0; i < teachers.size(); i++) {
		int x = teachers[i].first;
		int y = teachers[i].second;
		// 4가지 방향으로 학생을 감지할 수 있는지 확인
		for (int j = 0; j < 4; j++) {
			if (watch(x, y, j)) return true;
		}
	}
	return false;
}



int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'T') teachers.push_back({ i,j });
			else if (board[i][j] == 'X') spaces.push_back({ i,j });
		}
	}

	// 빈 공간에서 3개를 뽑는 모든 조합을 확인
	vector<int> order(spaces.size());
	fill(order.end() - 3, order.end(), 1);
	do {
		// 장애물들을 설치해보기
		for (int i = 0; i < spaces.size(); i++) {
			if (order[i]) {
				int x = spaces[i].first;
				int y = spaces[i].second;
				board[x][y] = 'O';
			}
		}

		// 학생이 한 명도 감지되지 않는 경우
		if (!process()) {
			// 원하는 경우를 발견한 것
			found = true;
			break;
		}

		// 설치된 장애물을 다시 없애기
		for (int i = 0; i < spaces.size(); i++) {
			if (order[i]) {
				int x = spaces[i].first;
				int y = spaces[i].second;
				board[x][y] = 'X';
			}
		}
	} while (next_permutation(order.begin(), order.end()));

	if (found) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}