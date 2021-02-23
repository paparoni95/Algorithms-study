#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, s;
vector<int> v[1001];
bool vis[1001];

void dfs(int node)
{
	cout << node << ' ';
	vis[node] = true;
	for (int i = 0; i < v[node].size(); i++)
	{
		int next = v[node][i];
		if (vis[next]) continue;
		dfs(next);
	}
}

void bfs(int node)
{
	queue<int> q;
	q.push(node);
	vis[node] = true;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		cout << node << ' ';

		for (int i = 0; i < v[node].size(); i++)
		{
			int next = v[node][i];
			if (vis[next]) continue;
			vis[next] = true;
			q.push(next);
		}
	}
}



int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> n >> m >> s;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end());

	dfs(s); cout << endl;

	fill(vis, vis + 1001, false);

	bfs(s); cout << endl;

	return 0;
}