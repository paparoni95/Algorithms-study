#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX_SIZE 1001
using namespace std;

vector<int> a[MAX_SIZE];
vector<bool> c(MAX_SIZE, false);
int N, M, S, u, v;

void dfs(int cur)
{
	c[cur] = true;
	int len = a[cur].size();
	printf("%d ", cur);
	for (int i = 0; i < len; i++)
	{
		int next = a[cur][i];
		if (!c[next])
		{
			dfs(next);
		}
	}
}

void bfs(int start)
{
	printf("\n");
	for (int i = 0; i < MAX_SIZE; i++) c[i] = false;
	queue<int> q;
	q.push(start);
	c[start] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		printf("%d ", cur);
		int len = a[cur].size();
		for (int i = 0; i < len; i++)
		{
			int next = a[cur][i];
			if (!c[next])
			{
				c[next] = true;
				q.push(next);
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &S);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}

	// 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것부터 탐색
	for (int i = 1; i <= N; i++)
		sort(a[i].begin(), a[i].end());

	dfs(S);
	bfs(S);
	return 0;
}