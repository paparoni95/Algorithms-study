#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int dist[200001];
int n, k;

bool check(int pos)
{
	if (pos == k)
		return true;
	else
		return false;
}

// 거리 별로 시간을 측정해서 배열에 저장한다.
void bfs(int n, int k)
{
	queue<int> q;
	q.push(n);
	dist[n] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		// n - 1
		if (cur - 1 >= 0 && cur - 1 <= 100000)
		{
			if (dist[cur - 1] == -1)
			{
				dist[cur - 1] = dist[cur] + 1; // 1초 증가
				q.push(cur - 1);
			}

			if (check(cur - 1)) // 답을 찾았으면 더 이상 찾지 않고 탈출
				return;
		}

		// n + 1
		if (cur + 1 >= 0 && cur + 1 <= 100000)
		{
			if (dist[cur + 1] == -1)
			{
				dist[cur + 1] = dist[cur] + 1;
				q.push(cur + 1);
			}

			if (check(cur - 1))
				return;
		}

		// 2 * n
		if (cur * 2 >= 0 && cur * 2 <= 100000)
		{
			if (dist[cur * 2] == -1)
			{
				dist[cur * 2] = dist[cur] + 1;
				q.push(cur * 2);
			}

			if (check(cur - 1))
				return;
		}
	}
}

int main()
{
	/* 입력 */
	cin >> n >> k;
	memset(dist, -1, sizeof(dist)); // 방문을 하지않음을 -1로 표시

	/* 탐색 */
	bfs(n, k);

	/* 출력 */
	cout << dist[k];
	return 0;
}
