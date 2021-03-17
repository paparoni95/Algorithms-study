#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// 어두운 길
int n, m;
int parent[200001];
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

	for (int i = 0; i < n; i++) parent[i] = i;

	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		edges.push_back({ z, {x,y} });
	}

	sort(edges.begin(), edges.end());

	int total = 0, result = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		total += cost;
		// 사이클이 발생하지 않는 경우에만 집합에 포함
		if (findParent(a) != findParent(b))
		{
			unionParent(a, b);
			result += cost;
		}
	}

	cout << total - result << '\n';
	return 0;
}