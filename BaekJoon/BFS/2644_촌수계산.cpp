#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, s, e, cycle;
vector<int> a[101];
bool visited[101];
int dist[101];

bool bfs(int start, int end)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
	dist[start] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < a[cur].size(); i++)
		{
			int neighbor = a[cur][i];

			if (visited[neighbor] == false)
			{
				dist[neighbor] = dist[cur] + 1; // 촌수 증가
				visited[neighbor] = true;
				q.push(neighbor);
				if (neighbor == end) // 만약에 내가 찾는 이웃이라면?
				{
					return true;
				}
			}
		}
	}

	return false; // 촌수의 관계가 아니라면
}

int main()
{
	cin >> n;       // 총 사람수
	cin >> s >> e;  // 두 사람의 관계를 몇 촌일까?
	cin >> cycle;   // 관계 수 
	for (int i = 0; i < cycle; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}

	bool ret = bfs(s, e);
	if (ret)
		cout << dist[e];
	else
		cout << -1;

	return 0;
}