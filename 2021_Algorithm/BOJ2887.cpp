#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n;
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

	cin >> n;

	for (int i = 1; i <= n; i++) parent[i] = i;

	vector<pair<int, int> > x; // (좌표, 노드)
	vector<pair<int, int> > y;
	vector<pair<int, int> > z;

	for (int i = 1; i <= n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		x.push_back({ a,i });
		y.push_back({ b,i });
		z.push_back({ c,i });
	}
	
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());

	// 간선을 추출한다.
	for (int i = 0; i < n - 1; i++)
	{
		edges.push_back({ x[i + 1].first - x[i].first,{x[i].second, x[i + 1].second} });
		edges.push_back({ y[i + 1].first - y[i].first, {y[i].second, y[i + 1].second} });
		edges.push_back({ z[i + 1].first - z[i].first, {z[i].second, z[i + 1].second} });
	}

	sort(edges.begin(), edges.end());

	long long total = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		if (findParent(a) != findParent(b))
		{
			unionParent(a,b);
			total += cost;
		}
	}

	cout << total << '\n';
	return 0;
}