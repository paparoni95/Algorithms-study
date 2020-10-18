#include <iostream>
#include <string>
using namespace std;

int r, c, startR, startC, endR, endC;
string arr[10], arr2[10];

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> arr[i];
		arr2[i] = arr[i];
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'X') {
				int cnt = 0;
				if (i - 1 < 0) cnt++;
				else if (arr[i - 1][j] == '.') cnt++;

				if (i + 1 >= r) cnt++;
				else if (arr[i + 1][j] == '.') cnt++;

				if (j - 1 < 0) cnt++;
				else if (arr[i][j - 1] == '.') cnt++;

				if (j + 1 >= c) cnt++;
				else if (arr[i][j + 1] == '.') cnt++;

				if (cnt >= 3) arr2[i][j] = '.';
			}
		}
	}

	startR = r - 1, startC = c - 1;
	endR = endC = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr2[i][j] == 'X') {
				startR = startR > i ? i : startR;
				startC = startC > j ? j : startC;
				endR = endR < i ? i : endR;
				endC = endC < j ? j : endC;
			}
		}
	}

	for (int i = startR; i <= endR; i++) {
		for (int j = startC; j <= endC; j++) {
			cout << arr2[i][j];
		}
		cout << '\n';
	}
	return 0;
}