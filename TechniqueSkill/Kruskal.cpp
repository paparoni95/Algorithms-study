#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
	# 크루스칼 알고리즘 (최소 신장 트리 = MST)
	신장 트리 중에서 최소 비용으로 만들 수 있는 신장트리를 찾는 알고리즘
	모든 도시를 '연결'할 때, 최소한의 비용으로 연결하려고 할 때

	최소 신장 트리는 일종의 트리 자료구조이므로,
	신장 트리에 포함되는 간선의 개수가 노드의 개수 - 1와 같다.
	V - 1 = E

	# 동작 방식
	핵심은 가장 거리가 짧은 간선부터 차례대로 집합에 추가하면 된다.

	1. 간선 데이터를 비용에 따라 오름차순으로 정렬한다.
	2. 간선을 하나씩 확인하며 현재의 간선이 사이클이 발생하는지 확인한다.
	2-1. 사이클이 발생하지 않는 경우 최소 신장 트리에 포함시킨다.
	2-2. 사이클이 발생하는 경우 최소 신장 트리에 포함시키지 않는다.

	# 시간 복잡도
	간서의 개수가 E개일 때, O(ElogE)
	시간이 가장 오래 걸리는 부분이 간선을 정렬하는 작업이며,
	크루스칼 내부에서 사용되는 서로소 집합 알고리즘의 시간 복잡도는 정렬 알고리즘의 시간 복잡도보다 작으므로 무시
*/

int v, e;
int parent[100001];
vector<pair<int, pair<int, int> > > edges;
int ans;

int findParent(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	cin >> v >> e;

	for (int i = 1; i <= v; i++) parent[i] = i;

	for (int i = 0; i < e; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		// 비용 순으로 정렬하기 위해서 튜플의 첫 번째 원소를 비용으로 설정한다.
		edges.push_back({ cost, {a,b} });
	}

	// 간선을 비용 순으로 정렬한다.
	sort(edges.begin(), edges.end());

	// 간선을 하나씩 확인하면서 최소 신장 트리를 완성시킨다.
	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		// 사이클이 발생하지 않는 경우에만 집합에 포함시킨다.
		if (findParent(a) != findParent(b))
		{
			unionParent(a, b);
			ans += cost;
		}
	}

	cout << ans << '\n';
	return 0;
}