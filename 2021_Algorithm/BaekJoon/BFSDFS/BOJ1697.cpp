#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100000;
int n, k;
int dist[MAX + 1];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;

	fill(dist, dist + 100001, -1);

	dist[n] = 0;

	queue<int> q;
	q.push(n);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == k)
		{
			cout << dist[cur] << '\n';
			break;
		}

		if (cur + 1 <= MAX && dist[cur + 1] == -1)
		{
			dist[cur + 1] = dist[cur] + 1;
			q.push(cur + 1);
		}

		if (cur - 1 >= 0 && dist[cur - 1] == -1)
		{
			dist[cur - 1] = dist[cur] + 1;
			q.push(cur - 1);
		}

		if (cur * 2 <= MAX && dist[cur * 2] == -1)
		{
			dist[cur * 2] = dist[cur] + 1;
			q.push(cur * 2);
		}
	}

	return 0;
}