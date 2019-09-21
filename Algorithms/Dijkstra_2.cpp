#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 다익스트라를 힙 구조를 이용해서 구현
// 힙 구조 -> 우선순위 큐
// 우선순위 큐로 인해서 아직 방문하지 않은 노드들 중 가장 비용이 적은
// 노드를 선택하는 비용이 logE밖에 되지 않기 때문에 시간을 단축시킬 수 있다.
// 시간 복잡도 O(ElogE)

const int INF = 1000000000;

vector<pair<int, int>> a[7]; // 간선 정보
int dist[7];

void dijkstra(int start) {
	dist[start] = 0;
	priority_queue<pair<int, int>> pq; // (first : 비용, second : 노드)
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		// 최단 거리가 아닌 경우 스킵
		if (dist[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			int next = a[current][i].first;
			int nextDistance = distance + a[current][i].second;
			// 기존의 최소 비용보다 더 값이 작다면 갱신한다.
			if (nextDistance < dist[next]) {
				dist[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));
			}
		}
	}
}

int main() {
	// 기본적으로 연결되지 않은 경우 비용은 무한으로 설정한다.
	for (int i = 1; i <= 6; i++) {
		dist[i] = INF;
	}

	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));

	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));

	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));

	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));

	dijkstra(1);
	for (int i = 1; i <= 6; i++) {
		cout << dist[i] << ' ';
	}
	return 0;
}