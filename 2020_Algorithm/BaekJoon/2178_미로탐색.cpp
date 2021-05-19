#include <iostream>
#include <queue>
#include <utility>
#define MAX_SIZE 101
using namespace std;

int a[MAX_SIZE][MAX_SIZE];
int ret[MAX_SIZE][MAX_SIZE];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int n, m;

int bfs()
{
	ret[0][0] = 1;
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x < 0 || next_x >= MAX_SIZE) continue;
			if (next_y < 0 || next_y >= MAX_SIZE) continue;
			if (a[next_x][next_y] == 1 && !ret[next_x][next_y])
			{
				ret[next_x][next_y] = ret[cur_x][cur_y] + 1;
				q.push({ next_x, next_y });
			}
		}
	}

	return ret[n - 1][m - 1];
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &a[i][j]);

	int ans = bfs();
	cout << ans;
	return 0;
}