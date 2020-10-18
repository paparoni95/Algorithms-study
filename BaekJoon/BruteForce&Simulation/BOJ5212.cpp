#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c;
char board[13][13];
char copyBoard[13][13];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 13; i++) fill(board[i], board[i] + 13, '.');
	
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < r + 2; i++) {
		for (int j = 0; j < c + 2; j++) {
			copyBoard[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < r + 2; i++) {
		for (int j = 0; j < c + 2; j++) {
			if (board[i][j] == 'X') {
				int countSea = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= r + 2 || ny >= c + 2) continue;
					if (board[nx][ny] == '.') countSea++;
				}

				if (countSea >= 3) copyBoard[i][j] = '.';
			}
		}
	}

	int maxRow = -1, minRow = 100;
	int maxCol = -1, minCol = 100;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (copyBoard[i][j] == 'X') {
				maxRow = max(maxRow, i);
				minRow = min(minRow, i);
				maxCol = max(maxCol, j);
				minCol = min(minCol, j);
			}
		}
	}

	for (int i = minRow; i <= maxRow; i++) {
		for (int j = minCol; j <= maxCol; j++) {
			cout << copyBoard[i][j];
		}
		cout << '\n';
	}

	return 0;
}