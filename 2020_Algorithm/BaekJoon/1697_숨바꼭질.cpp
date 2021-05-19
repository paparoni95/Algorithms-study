#include <iostream>
#include <queue>

#define MAX_SIZE 100001
using namespace std;

int N, K;
bool visited[MAX_SIZE];
int cnt[MAX_SIZE];

int bfs()
{
	queue<int> q;
	q.push(N);
	visited[N] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == K) return cnt[K];

		if (cur + 1 >= 0 && cur + 1 < MAX_SIZE)
		{
			if (!visited[cur + 1])
			{
				visited[cur + 1] = true;
				cnt[cur + 1] = cnt[cur] + 1;
				q.push(cur + 1);
			}
		}

		if (cur - 1 >= 0 && cur - 1 < MAX_SIZE)
		{
			if (!visited[cur - 1])
			{
				visited[cur - 1] = true;
				cnt[cur - 1] = cnt[cur] + 1;
				q.push(cur - 1);
			}
		}

		if (cur * 2 >= 0 && cur * 2 < MAX_SIZE)
		{
			if (!visited[cur * 2])
			{
				visited[cur * 2] = true;
				cnt[cur * 2] = cnt[cur] + 1;
				q.push(cur * 2);
			}
		}
	}

	return -1;
}

int main()
{
	cin >> N >> K;
	int ret = bfs();
	cout << ret << '\n';
	return 0;
}