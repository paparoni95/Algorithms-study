#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

// 노드의 개수 n, 간선의 개수 m, 시작 노드 번호 start
int n, m, start;
// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
vector<pair<int, int>> graph[30001];
// 최단 거리 테이블 만들기
int d[30001];

void Dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	// 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
	pq.push({ 0, start });
	d[start] = 0;
	while (!pq.empty()) {
		// 가장 최단 거리가 짧은 노드에 대한 정보를 꺼내기
		int dist = -pq.top().first; // 현재 노드까지의 비용
		int now = pq.top().second;  // 현재 노드
		pq.pop();
		// 현재 노드가 이미 처리된 적이 있는 노드라면 무시
		if (d[now] < dist) continue;
		// 현재 노드와 연결된 다른 인접한 노드들을 확인
		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			// 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push({ -cost, graph[now][i].first });
			}
		}
	}
}

int main() {
	cin >> n >> m >> start;
	// 모든 간선 정보를 입력받기
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		// a번 노드에서 b번 노드로 가는 비용이 c라는 의미
		graph[a].push_back({ b,c });
	}

	// 최단 거리 테이블을 모두 무한으로 초기화
	fill(d, d + 30001, INF);

	// 다익스트라 알고리즘을 수행
	Dijkstra(start);

	// 도달할 수 있는 노드의 개수
	int count = 0;
	// 도달할 수 있는 노드 중에서, 가장 멀리 있는 노드와의 최단 거리
	int max_distance = 0;
	for (int i = 1; i <= n; i++) {
		// 도달할 수 있는 노드인 경우
		if (d[i] != INF) {
			count += 1;
			max_distance = max(max_distance, d[i]);
		}
	}

	// 시작 노드는 제외해야 하므로 count - 1을 출력
	cout << count - 1 << ' ' << max_distance << '\n';

	return 0;
}