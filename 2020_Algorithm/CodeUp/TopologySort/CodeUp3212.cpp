#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int v, e;
int indegree[201];
vector<int> graph[201];

void topologySort()
{
	vector<int> ret;
	priority_queue<int, vector<int>, greater<int> > q;

	for (int i = 1; i <= v; i++)
	{
		if (indegree[i] == 0) q.push(i);
	}

	for (int i = 1; i <= v; i++)
	{
		// 위상 정렬 도중에 큐가 비게 된다면 사이클이 존재한다는 의미
		if (q.empty())
		{
			cout << -1 << '\n';
			return;
		}

		int now = q.top(); q.pop();
		ret.push_back(now);

		for (int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i];
			indegree[next]--;
			if (indegree[next] == 0) q.push(next);
		}
	}

	for (int n : ret) cout << n << '\n';
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}

	topologySort();

	return 0;
}