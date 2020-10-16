#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 인접리스트로 구현하면 O(V+E)

class Graph
{
public:
	int n;
	vector<vector<int>> adj; // 인접 리스트

	// 생성자
	Graph() : n(0) { }
	Graph(int n) : n(n)
	{
		adj.resize(n);
	}

	// 간선 추가(양방향)
	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// 모든 리스트의 인접한 정점 번호 정렬
	void sortList()
	{
		for (int i = 0; i < n; i++)
			sort(adj[i].begin(), adj[i].end());
	}

	// 너비 우선 탐색
	void bfs()
	{
		vector <bool> visited(n, false); // 방문 배열
		queue<int> q;
		q.push(0);
		visited[0] = true;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			cout << "node " << cur << " visited" << endl;
			for (int next : adj[cur])
			{
				if (!visited[next])
				{
					visited[next] = true;
					q.push(next);
				}
			}
		}
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
	G.addEdge(4, 5);
	G.addEdge(2, 6);
	G.addEdge(2, 8);
	G.addEdge(6, 7);
	G.addEdge(6, 8);
	G.sortList();
	G.bfs();
	return 0;
}
