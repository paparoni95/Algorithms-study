// 출처 : https://blog.naver.com/kks227/220785731077
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph
{
public:
	int N;
	vector<vector<int>> adj; // 인접 리스트
	vector<bool> visited;    // 방문 배열

	Graph() : N(0) { }
	Graph(int n) : N(n)
	{
		adj.resize(N);
		visited.resize(N);
	}
	// 양방향 연결
	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// 모든 리스트의 인접한 정점 번호 정렬
	void sortList()
	{
		for (int i = 0; i < N; i++)
			sort(adj[i].begin(), adj[i].end());
	}

	void dfs()
	{
		fill(visited.begin(), visited.end(), false);
		dfs(0);
	}

private:
	void dfs(int cur)
	{
		visited[cur] = true;
		cout << "node " << cur << " visited" << endl;
		for (int next : adj[cur])
			if (!visited[next])
				dfs(next);
	}
};

int main()
{
	Graph G(9);
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 3);
	G.addEdge(1, 5);
	G.addEdge(3, 4);
	G.addEdge(2, 6);
	G.addEdge(2, 8);
	G.addEdge(6, 7);
	G.addEdge(6, 8);
	G.sortList();
	G.dfs();
	return 0;
}
