#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans;
int parent[100001];
vector<pair<int, pair<int, int> > > edges;

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
	freopen("input.txt", "r", stdin);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		edges.push_back({ cost, {a,b} });
	}

	sort(edges.begin(), edges.end());

	int last = 0; // 최소 신장 트리에 포함되는 간선 중에서 가장 비용이 큰 간선 제거를 위해서
	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;

		if (findParent(a) != findParent(b))
		{
			unionParent(a, b);
			ans += cost;
			last = cost;
		}
	}

	cout << ans - last << '\n';
	return 0;
}