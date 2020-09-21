#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

// 시간복잡도 O(ElogV), 우선순위 큐를 이용하는 방식이 훨씬 더 빠르다.
// 한 번 처리된 노드는 더 이상 처리하지 않으며,
// 현재 우선순위 큐에서 꺼낸 노드와 연결된 다른 노드들을 확인하는 총 횟수는 O(E)
// 전체 다익스트라 알고리즘은 E개의 원소를 우선순위 큐에 넣었다가 모두 빼내는 연산
// 즉, 최대 간선 E개의 간선 데이터를 힙에 넣었다가 다시 빼는 것으로 볼 수 있으므로 O(ElogE)
// 중복 간선을 포함하지 않는 경우 E는 항상 V^2보다 작다.
// 이는 logE는 logV^2Q보다 작다.
// 다익스트라 알고리즘의 전체 시간 복잡도는 간단히 O(ElogV)
// 다익스트라 알고리즘은 그리디 알고리즘의 유형 중 하나이다.

// 노드의 개수 n, 간선의 개수 m, 시작 노드 번호 start
// 노드의 개수는 최대 100,000개라고 가정
int n, m, start;
// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
vector<pair<int, int>> graph[100001];
// 최단 거리 테이블 만들기
int d[100001];

void Dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	// 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
	pq.push({ 0,start });
	d[start] = 0;
	while (!pq.empty()) {
		// 가장 최단 거리가 짧은 노드에 대한 정보 가져오기
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

	// 모든 간선 정보를 입력 받기
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		// a번 노드에서 b번 노드로 가는 비용이 c라는 의미
		graph[a].push_back({ b,c });
	}

	// 최단 거리 테이블을 모두 무한으로 초기화
	fill(d, d + 100001, INF);

	// 다익스트라 알고리즘을 수행
	Dijkstra(start);

	// 모든 노드로 가기 위한 최단 거리를 출력
	for (int i = 1; i <= n; i++) {
		// 도달할 수 없는 경우, 무한(INFINITY) 출력
		if (d[i] == INF)
			cout << "INFINITY\n";
		else
			cout << d[i] << '\n';
	}
	return 0;
}
