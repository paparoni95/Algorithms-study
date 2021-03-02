#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
	# 위상 정렬(TopologySort)
	순서가 정해져 있는 일련의 작업을 차례대로 수행해야 할 때 사용하는 알고리즘

	# 시간 복잡도
	차례대로 모든 노드를 확인하면서, 해당 노드에서 출발하는 간선을 차례대로 제거해야 하기 때문에
	O(V + E), V : 노드의 수, E : 간선의 수
*/

int v, e;
int indegree[100001];
vector<int> graph[100001];

void topologySort()
{
	vector<int> ret; // 위상 정렬 수행 결과를 담을 배열
	queue<int> q;

	// 처음 시작할 때는 진입차수가 0인 노드들을 큐에 삽입한다.
	for (int i = 1; i <= v; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int now = q.front(); q.pop();
		ret.push_back(now);

		// 해당 원소와 연결된 노드들의 진입차수에서 1 빼기
		for (int i = 0; i < graph[now].size(); i++)
		{
			indegree[graph[now][i]]--;
			// 새롭게 진입차수가 0이 되는 노드들을 큐에 삽입한다.
			if (indegree[graph[now][i]] == 0)
				q.push(graph[now][i]);
		}
	}

	// 위상 정렬을 수행한 결과를 출력한다.
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << ' ';
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> v >> e;

	// 방향 그래프의 모든 간선의 정보를 입력받는다.
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b); // a -> b
		indegree[b]++; // 진입차수 추가
	}

	// 위상정렬 수행
	topologySort();
	return 0;
}