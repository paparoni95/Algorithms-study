#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100001;

int N;
vector<vector<int>> graph;
int parent[MAX];
bool visit[MAX];

void findParentNode()
{
	queue<int> q;
	q.push(1);
	visit[1] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			if (!visit[next])
			{
				parent[next] = cur; // 부모 노드 저장
				visit[next] = true;
				q.push(next);
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	graph.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	findParentNode();

	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << '\n';
	}

	return 0;
}