#include <iostream>
using namespace std;

const int INF = 1000000000;

// 선형탐색으로 다익스트라 구현
// 시간 복잡도 O(N^2)
// 이유 : 아직 방문하지 않는 노드들 중에서 최소 거리를 가지는 노드를
//        선택하는 비용이 O(N)이 들기 때문

// 그래프 표시
int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
    {2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};
bool check[6];  // 방문한 노드
int dist[6];    // 최단 거리

// 가장 최소 거리를 가지는 정점을 반환한다.
// 이는 아직 방문하지 않은 노드들 중에서 최소 거리를 가지는 노드를 선택
int getSmallIndex() {
	int min = INF;
	int index = 0;
	for (int i = 0; i < 6; i++) {
		if (dist[i] < min && !check[i]) {
			min = dist[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	for (int i = 0; i < 6; i++) {
		dist[i] = a[start][i];
	}
	check[start] = true;
	for (int i = 0; i < 6 - 2; i++) {
		int current = getSmallIndex();
		check[current] = true;
		for (int j = 0; j < 6; j++) {
			if (!check[j]) {
				if (dist[current] + a[current][j] < dist[j]) {
					dist[j] = dist[current] + a[current][j];
				}
			}
		}
	}
}

int main() {
	dijkstra(0);
	for (int i = 0; i < 6; i++) {
		cout << dist[i] << ' ';
	}
	return 0;
}