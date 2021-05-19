#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, a, b, m;
vector<vector<int>> g;

int bfs(int start)
{
	vector<bool> visited(n + 1, false);
	visited[start] = true;
	queue<int> q;
	q.push(start);
	
	int level = 0;
	while (!q.empty())
	{
		int qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			int cur = q.front();
			q.pop();

			for (int next : g[cur])
			{
				if (!visited[next])
				{
					if (next == b) return level + 1; // ¼­·Î ÀÌ¿ôÀÌ¶ó¸é?
					visited[next] = true;
					q.push(next);
				}
			}
		}
		level++;
	}

	return -1; // ¼­·Î Ä£Ã´ÀÌ ¾Æ´Ô.
}

int main()
{
	cin >> n;
	cin >> a >> b;
	cin >> m;

	g.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int res = bfs(a);

	if (res == -1)
		cout << -1;
	else
		cout << res;
	return 0;
}