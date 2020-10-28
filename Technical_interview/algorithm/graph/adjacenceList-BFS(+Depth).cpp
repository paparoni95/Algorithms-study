// [출처] https://blog.naver.com/kks227/220785747864
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 같은 BFS 탐색이지만, 깊이를 알아내는 방법

class Graph
{
public:
	int n;
	vector<vector<int>> adj;

	Graph() : n(0) {}
	Graph(int n) : n(n)
	{
		adj.resize(n);
	}

	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void sortList()
	{
		for (int i = 0; i < n; i++)
			sort(adj[i].begin(), adj[i].end());
	}

	void bfs()
	{
		vector<bool> visited(n, false);
		queue<int> q;
		q.push(0);
		visited[0] = true;
		
		int level = 0; // 현재 퍼진 단계, 약간 불이 퍼져나가는 방식으로 할 수 있다.
		while (!q.empty())
		{
			int qSize = q.size(); // 그 단계에서 할 수 있는 것들을 사이즈로 저장을 해놓고
			cout << "------ level " << level << " ------" << endl;
			for (int i = 0; i < qSize; i++) // 그것만큼 돌린다.
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
			level++;
		}
	}
};

int main() {
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
