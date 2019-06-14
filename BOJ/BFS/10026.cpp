#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int mp1[MAX][MAX]; //정상
int mp2[MAX][MAX]; //비정상
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n;
int ans1, ans2;

void bfsOne(int x, int y, int side) {
	mp1[x][y] = 0;
	queue<pair<int,int> > q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (mp1[nx][ny] == side) {
					q.push(make_pair(nx, ny));
					mp1[nx][ny] = 0;
				}
			}
		}
	}
}

void bfsTwo(int x, int y, int side) {
	mp2[x][y] = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (mp2[nx][ny] == side) {
					q.push(make_pair(nx, ny));
					mp2[nx][ny] = 0;
				}
			}
		}
	}
}

void showMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mp1[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	cin >> n;
	char ch;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ch;
			if (ch == 'R') {
				mp1[i][j] = 1;
				mp2[i][j] = 1;
			}
			else if (ch == 'G') {
				mp1[i][j] = 2;
				mp2[i][j] = 1;
			}
			else {
				mp1[i][j] = 3;
				mp2[i][j] = 3;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mp1[i][j] != 0) {
				ans1++;
				bfsOne(i, j, mp1[i][j]);
			}
			if (mp2[i][j] != 0) {
				ans2++;
				bfsTwo(i, j, mp2[i][j]);
			}
		}
	}
	//정상인 사람, 비정상인 사람
	cout << ans1 << ' ' << ans2;
	return 0;
}