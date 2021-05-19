#include <iostream>
#include <queue>
#define MAX_SIZE 301
using namespace std;

int dx[] = { -2,-1,-2,-1,1,2,1,2 };
int dy[] = { -1,-2,1,2,-2,-1,2,1 };
int a[MAX_SIZE][MAX_SIZE];  // 체스판
bool c[MAX_SIZE][MAX_SIZE]; // 

void initialize()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			a[i][j] = 0;
			c[i][j] = false;
		}
	}
}

int bfs(int startX, int startY, int endX, int endY, int limit)
{
	queue<pair<int, int>> q;
	q.push({ startX, startY });
	c[startX][startY] = true;
	a[startX][startY] = 0;
	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		if (curX == endX && curY == endY)
			return a[curX][curY];

		for (int i = 0; i < 8; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (nextX < 0 || nextX >= limit) continue;
			if (nextY < 0 || nextY >= limit) continue;
			if (c[nextX][nextY] == false)
			{
				a[nextX][nextY] = a[curX][curY] + 1;
				c[nextX][nextY] = true;
				q.push({ nextX, nextY });
			}
		}
	}

	return -1;
}

void show(int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		initialize();

		int n;
		scanf("%d", &n);

		int startX, startY;
		int endX, endY;
		scanf("%d %d", &startX, &startY);
		scanf("%d %d", &endX, &endY);

		int ret = bfs(startX, startY, endX, endY, n);
		//show(n);
		printf("%d\n", ret);
	}
	return 0;
}
