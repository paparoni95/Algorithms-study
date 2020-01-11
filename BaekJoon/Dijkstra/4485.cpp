#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 126
#define INF 987654321
using namespace std;

int cave[MAX][MAX];
int total[MAX][MAX];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int findCaveExit(int x, int y, int size) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	total[x][y] = cave[x][y];
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nextDistance = cave[nx][ny];
			if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
				if (total[nx][ny] > total[cx][cy] + nextDistance) {
					total[nx][ny] = total[cx][cy] + nextDistance;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return total[size - 1][size - 1];
}
void init(void) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			total[i][j] = 0;
			cave[i][j] = 0;
		}
	}
}

void setTotal(void) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			total[i][j] = INF;
		}
	}
}

int main() {
	int testCase = 0;
	while(1){
		testCase++;
		int n, result = 0;
		cin >> n;
		init();
		setTotal();
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> cave[i][j];
			}
		}
		result = findCaveExit(0, 0, n);
		printf("Problem %d: %d\n", testCase, result);
	}
	return 0;
}