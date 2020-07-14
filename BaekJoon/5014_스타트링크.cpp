#include <iostream>
#include <queue>
#include <cstring>

#define MAX_SIZE 1000001
using namespace std;

int F, S, G, U, D;
int dist[MAX_SIZE];

int bfs()
{
	queue<int> q;
	q.push(S);
	dist[S] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == G) return dist[cur];

		if (cur + U >= 1 && cur + U <= F)
		{
			if (dist[cur + U] == -1)
			{
				dist[cur + U] = dist[cur] + 1;
				q.push(cur + U);
			}
		}

		if (cur - D >= 1 && cur - D <= F)
		{
			if (dist[cur - D] == -1)
			{
				dist[cur - D] = dist[cur] + 1;
				q.push(cur - D);
			}
		}
	}

	return -1;
}

int main()
{
	cin >> F >> S >> G >> U >> D;
	memset(dist, -1, sizeof(dist));

	int ret = bfs();

	if (ret == -1)
		cout << "use the stairs" << '\n';
	else
		cout << ret << '\n';
	return 0;
}