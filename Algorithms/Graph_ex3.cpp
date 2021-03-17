#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int v;
int indegree[501];
int times[501];
vector<int> graph[501];

void topologySort()
{
	vector<int> result(501);
	for (int i = 1; i <= v; i++) result[i] = times[i];
	queue<int> q;

	for (int i = 1; i <= v; i++)
		if (indegree[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i];
			result[next] = max(result[next], result[now] + times[next]);
			indegree[next]--;
			if (indegree[next] == 0)
				q.push(next);
		}
	}

	for (int i = 1; i <= v; i++)
		cout << result[i] << '\n';
}

int main()
{
	freopen("input.txt", "r", stdin);

	cin >> v;
	for (int i = 1; i <= v; i++)
	{
		int x;
		cin >> x;
		times[i] = x;
		while (1)
		{
			cin >> x;
			if (x == -1) break;
			indegree[i]++;
			graph[x].push_back(i);
		}
	}

	topologySort();

	return 0;
}