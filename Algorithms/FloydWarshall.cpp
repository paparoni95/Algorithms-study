#include <iostream>
using namespace std;

const int INF = 1000000000;

// 시간 복잡도 O(N^3)
// 모든 정점에서 모든 정점사이의 최단 경로를 다 구해준다.
int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floydWarshall() {
	// 결과 그래프를 초기화 한다.
	int dist[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			dist[i][j] = a[i][j];
		}
	}

	// k = 거쳐가는 노드
	for (int k = 0; k < 4; k++) {
		// i = 출발 노드
		for (int i = 0; i < 4; i++) {
			// j = 도착 노드
			for (int j = 0; j < 4; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	floydWarshall();
	return 0;
}