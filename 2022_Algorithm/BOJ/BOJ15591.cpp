#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, Q;
vector<pair<int, int> > graph[5005];
bool visited[5005];

int bfs(int startNode, int k)
{
	fill(visited, visited + 5005, false);
	int cnt = 0;
	queue<pair<int, int> > q;
	q.push({ startNode, 0 });
	visited[startNode] = true;
	while (!q.empty())
	{
		int cur = q.front().first;
		int cost = q.front().second;
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int nextCost = graph[cur][i].second;
			if (nextCost >= k && visited[next] == false)
			{
				cnt++;
				visited[next] = true;
				q.push({ next, nextCost });
			}
		}
	}

	return cnt;
}

void solve()
{
	cin >> N >> Q;
	for (int i = 0; i < N - 1; i++)
	{
		int p, q, r;
		cin >> p >> q >> r;
		graph[p].emplace_back(q, r);
		graph[q].emplace_back(p, r);
	}

	int ans = 0;
	for (int i = 0; i < Q; i++)
	{
		int k, v;
		cin >> k >> v;

		ans = 0;
		ans = bfs(v, k);
		cout << ans << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}
