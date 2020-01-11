#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[101];
bool visited[101];
int com, cycle;

int bfs(int start)
{
	int ans = 0;
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < a[cur].size(); i++)
		{
			int next = a[cur][i];
			if (visited[next] == false)
			{
				q.push(next);
				visited[next] = true;
				ans++; // 바이러스에 감염 카운트
			}
		}
	}

	return ans;
}

int main()
{
	cin >> com;
	cin >> cycle;
	for (int i = 0; i < cycle; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	// 바이러스 전파
	int ret = bfs(1);
	cout << ret;
	return 0;
}