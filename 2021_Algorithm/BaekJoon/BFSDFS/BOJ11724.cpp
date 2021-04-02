#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, e;
bool vis[1001];
vector<int> graph[1001];

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	vis[start] = true;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		// now 노드와 연결되어있는 노드를 탐색
		for (int i = 0; i < graph[now].size(); ++i)
		{
			int next = graph[now][i];
			if (!vis[next])
			{
				vis[next] = true;
				q.push(next);
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> v >> e;
	for (int i = 0; i < e; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int cnt = 0;
	for (int i = 1; i <= v; ++i)
	{
		if (!vis[i])
		{
			cnt++;
			bfs(i);
		}
	}

	cout << cnt << '\n';
	return 0;
}