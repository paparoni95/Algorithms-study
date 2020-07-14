#include <iostream>
#include <vector>

#define MAX_SIZE 1000 + 1
using namespace std;

int N, M, cnt;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node)
{
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++)
	{
		int next = graph[node][i];
		if (!visited[next]) dfs(next);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	graph.resize(N + 1);
	visited.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			dfs(i);
			cnt++;
		}
	}

	cout << cnt << '\n';
	return 0;
}