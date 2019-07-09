#include <iostream>
#define MAX_SIZE 2190
using namespace std;

int mp[MAX_SIZE][MAX_SIZE];
int minusOneCnt, zeroCnt, oneCnt;

//한 번에 카운트가 가능한지
bool check(int x, int y, int size) {
	int target = mp[x][y];
	for (int i = x; i < x + size; i++) { //그 좌표로 부터 사이즈만큼 탐색
		for (int j = y; j < y + size; j++) {
			if (target != mp[i][j]) return false;//종이가 하나라도 다르다면
		}
	}
	return true;
}

//종이 커팅
void cutting(int x, int y, int size) {
	if (check(x, y, size) == true) {
		if (mp[x][y] == -1) minusOneCnt++;
		else if (mp[x][y] == 0) zeroCnt++;
		else oneCnt++;
		return;
	}
	else { //한 번에 종이를 카운트 못했으면 종이를 분할
		int newSize = size / 3;
		for (int i = 0; i < 3; i++) { //그 좌표로 부터 사이즈만큼 탐색
			for (int j = 0; j < 3; j++) {
				cutting(x + i * newSize, y + j * newSize, newSize); //재귀
			}
		}
	}
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) { //입력
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
		}
	}

	cutting(0, 0, n); //종이 커팅

	cout << minusOneCnt << '\n';
	cout << zeroCnt << '\n';
	cout << oneCnt << '\n';
	return 0;
}