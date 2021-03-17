#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

/* 
	# 위상 정렬
	방향 그래프의 모든 노드를 방향성에 거스르지 않도록 순서대로 나열하는 것

	# 동작 방식
	1. 진입차수가 0인 노드를 큐에 넣는다.
	2. 큐가 빌 때까지 다음의 과정을 반복한다.
	2-1. 큐에서 원소를 꺼내 해당 노드에서 출발하는 간선을 그래프에서 제거한다.
	2-2. 새롭게 진입차수가 0이 된 노드를 큐에 넣는다.

	중요, 모든 원소를 방문하기 전에 큐가 빈다면 사이클이 존재한다고 판단할 수 있다.
	사이클이 존재하는 경우 사이클에 포함되어 있는 원소 중에서 어떠한 원소도 큐에 들어가지 못하기 때문이다.

	큐에서 빠져나간 노드를 순서대로 출력하면, 그것이 바로 위상 정렬을 수행한 결과이다.
	위상 정렬의 답안은 여러 가지가 될 수 있다는 점이 특징이다.
	만약에 한 단계에서 큐에 새롭게 들어가는 원소가 2개 이상인 경우가 있다면, 여러 가지 답이 존재하게 된다.

	# 시간 복잡도
	O(V + E)
	차례대로 모든 노드를 확인하면서, 해당 노드에서 출발하는 간선을 차례대로 제거한다.
	결과적으로 노드와 간선을 모두 확인하므로 V + E 이다.
*/

int v, e;
int indegree[100001];
vector<int> graph[100001];

void topologySort()
{
	vector<int> ret; // 알고리즘 수행 결과를 담을 리스트
	queue<int> q;

	// 처음 시작할 때는 진입차수가 0인 노드를 큐에 넣는다.
	for (int i = 1; i <= v; i++)
		if (indegree[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		ret.push_back(now);

		// 해당 원소와 연결된 노드들의 진입차수에서 1 빼기
		for (int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i];
			indegree[next]--;
			// 새롭게 진입차수가 0이 되는 노드는 큐에 넣어준다.
			if (indegree[next] == 0)
				q.push(next);
		}
	}

	// 위상 정렬을 수행한 결과 출력
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << ' ';
}

int main()
{
	cin >> v >> e;
	
	// 방향 그래프의 모든 간선 정보를 입력 받기
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}

	topologySort();

	return 0;
}