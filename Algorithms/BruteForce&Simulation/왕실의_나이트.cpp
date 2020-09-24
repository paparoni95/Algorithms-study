#include <bits/stdc++.h>
using namespace std;

string inputData;

// 나이트가 이동할 수 있는 8가지 방향 정의
int dx[] = { -2,-1,1,2,2,1,-1,-2 };
int dy[] = { -1,-2,-2,-1,1,2,2,1 };

int main() {
	cin >> inputData;
	int row = inputData[1] - '0';
	int column = inputData[0] - 'a' + 1;

	// 8가지 방향에 대하여 각 위치로 이동이 가능한지 확인
	int result = 0;
	for (int i = 0; i < 8; i++) {
		int nextRow = row + dx[i];
		int nextColumn = column + dy[i];
		if (nextRow >= 1 && nextRow <= 8 && nextColumn >= 1 && nextColumn <= 8) result++;
	}

	cout << result << '\n';
	return 0;
}