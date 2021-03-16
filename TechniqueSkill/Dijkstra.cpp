#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/*
	# 다익스트라 알고리즘
	특정한 노드에서 출발하여 다른 모든 노드로 가는 각각의 최단 경로를 구해주는 알고리즘

	# 동작 방식
	1. 출발 노드를 설정
	2. 최단 거리 테이블을 초기화
	3. 방문하지 않은 노드 중에서 최단 거리가 가장 짧은 노드를 선택한다.
	4. 해당 노드를 거쳐 다른 노드로 가는 비용을 계산하여 최단 거리 테이블을 갱신한다.

	# 시간 복잡도
	O(ElogV)
	우선순위 큐에서 꺼낸 노드와 연결된 다른 노드들을 확인하는 총 횟수는 최대 간선의 개수 E만큼 수행
	최대 E개의 간선 데이터를 힙에 넣었다가 빼는 것이므로 O(ElogE)
	
	중복 간선을 포함하지 않는 경우, E는 항상 V^2보다 작다.
	따라서 E는 항상 V^2 이하이므로 전체 시간 복잡도는 O(ElogV)
*/

const int INF = 1e9;

int n, m, start; // 노드, 간선, 시작 노드
vector<pair<int, int>> graph[100001];
int dist[100001];

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq; // (비용, 노드)
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty())
	{
		int distance = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		// 현재 노드가 이미 처리된 적이 있다면 무시
		if (dist[cur] < distance) continue;
		// 현재 노드와 연결된 다른 인접한 노드들을 확인
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int nextDistance = distance + graph[cur][i].second;
			// 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우 갱신해준다.
			if (nextDistance < dist[next])
			{
				dist[next] = nextDistance;
				pq.push({ -nextDistance, next });
			}
		}
	}
}

int main()
{
	cin >> n >> m >> start;

	// 모든 간선 정보 입력
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		// a -> b 가는 비용이 c라고 하면
		graph[a].push_back({ b,c });
	}

	// 최단 거리 테이블 무한으로 초기화
	fill(dist, dist + 100001, INF);

	dijkstra(start);

	// 모든 노드로 가기 위한 최단 거리를 출력
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}

	return 0;
}
