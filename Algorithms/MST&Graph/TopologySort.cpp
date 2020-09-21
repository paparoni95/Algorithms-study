#include <bits/stdc++.h>
using namespace std;

// 위상 정렬은 순서가 정해져 있는 일련의 작업을 차례대로 수행해야 할 때 사용하는 알고리즘
// 차례대로 모든 노드를 확인하면서, 해당 노드에서 출발하는 간선을 차례대로 제거해야 하기 때문에
// 위상 정렬의 시간 복잡도 O(V + E)

// 노드의 개수 v, 간선의 개수 e
// 노드의 개수는 최대 100,000개라고 가정
int v, e;
// 모든 노드에 대한 진입차수는 0으로 초기화
int indegree[100001];
// 각 노드에 연결된 간선 정보를 담기 위한 연결 리스트 초기화
vector<int> graph[100001];

// 위상 정렬 함수
void TopologySort() {
	vector<int> result; // 알고리즘 수행 결과를 담을 리스트
	queue<int> q;

	// 처음 시작할 때는 진입차수가 0인 노드를 큐에 삽입
	for (int i = 1; i <= v; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		result.push_back(now);
		// 해당 원소와 연결된 노드들의 진입차수에서 1 빼기
		for (int i = 0; i < graph[now].size(); i++) {
			indegree[graph[now][i]] -= 1;
			// 새롭게 진입차수가 0이 되는 노드를 큐에 삽입
			if (indegree[graph[now][i]] == 0) {
				q.push(graph[now][i]);
			}
		}
	}

	// 위상 정렬을 수행한 결과 출력
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
}

int main() {
	cin >> v >> e;

	// 방향 그래프의 모든 간선 정보를 입력 받기
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b); // 정점 a에서 b로 이동 가능
		// 진입 차수를 1 증가
		indegree[b] += 1;
	}

	// 위상정렬 수행
	TopologySort();
	
	return 0;
}