#include <bits/stdc++.h>
#define INF	1e9 // 무한을 의미하는 값으로 10억을 설정
using namespace std;

// 시간 복잡도 O(V^2)
// 총 O(V)번에 걸쳐서 최단 거리가 가장 짧은 노드를 매번 선형 탐색으로 찾아야 한다.
// 현재 노드와 연결된 노드를 매번 일일이 확인해야 한다.

// 노드의 개수 n, 간선의 개수 m, 시작 노드 번호 start
// 노드의 개수는 최대 100,000개라고 가정
int n, m, start;
// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
vector<pair<int, int>> graph[100001];
// 방문한 적이 있는지 체크하는 목적의 배열 만들기
bool visited[100001];
// 최단 거리 테이블 만들기
int d[100001];

// 방문하지 않은 노드 중에서, 가장 최단 거리가 짧은 노드의 번호를 반환
int GetSmallestNode() {
	int min_value = INF;
	int index = 0; // 가장 최단 거리가 짧은 노드(인덱스)
	for (int i = 1; i <= n; i++) {
		if (d[i] < min_value && !visited[i]) {
			min_value = d[i];
			index = i;
		}
	}
	return index;
}

void Dijkstra(int start) {
	// 시작 노드에 대해서 초기화
	d[start] = 0;
	visited[start] = true;
	// 시작 노드와 연결된 모든 간선을 하나씩 확인
	for (int j = 0; j < graph[start].size(); j++) {
		d[graph[start][j].first] = graph[start][j].second;
	}
	// 시작 노드를 제외한 전체 n-1개의 노드에 대해 반복
	for (int i = 0; i < n - 1; i++) {
		// 현재 최단 거리가 가장 짧은 노드를 꺼내서, 방문 처리
		int now = GetSmallestNode();
		visited[now] = true;
		// 현재 노드와 연결된 다른 노드를 확인
		for (int j = 0; j < graph[now].size(); j++) {
			int cost = d[now] + graph[now][j].second;
			// 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
			if (cost < d[graph[now][j].first]) {
				d[graph[now][j].first] = cost;
			}
		}
	}
}

int main() {
	cin >> n >> m >> start;

	// 모든 간선의 정보를 입력 받기
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

	// 모든 노드로 가기 위한 최단거리를 출력
	for (int i = 1; i <= n; i++) {
		// 도달할 수 없는 경우, 무한(INFINITY)출력
		if (d[i] == INF)
			cout << "INFINITY\n";
		// 도달할 수 있는 경우 거리를 출력
		else
			cout << d[i] << '\n';
	}
	return 0;
}
