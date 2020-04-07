#include <iostream>
#include <algorithm>

#define MAX_SIZE 100 + 1
using namespace std;

int N, max_height;
int a[MAX_SIZE][MAX_SIZE];
int b[MAX_SIZE][MAX_SIZE];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void dfs(int x, int y)
{
	a[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N)
		{
			if (a[nx][ny]) dfs(nx, ny);
		}
	}
}

void copyMap()
{
	for(int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
			if (a[i][j] > max_height)
				max_height = a[i][j];

			b[i][j] = a[i][j];
		}
	}

	int ans = 0, cnt = 0;
	for (int h = 0; h <= max_height; h++)
	{
		copyMap();
		cnt = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (a[i][j] <= h)
					a[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (a[i][j])
				{
					cnt++;
					dfs(i, j);
				}
			}
		}

		ans = max(ans, cnt);
	}

	cout << ans << '\n';
	return 0;
}