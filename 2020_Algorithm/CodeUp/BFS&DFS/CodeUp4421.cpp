#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[25][25];
bool check[25][25];
vector<int> ans;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int dfs(int x, int y)
{
	int cnt = 1;
	check[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n)
		{
			if (a[nx][ny] && !check[nx][ny])
			{
				cnt += dfs(nx, ny);
			}
		}
	}

	return cnt;
}

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] && !check[i][j])
				ans.push_back(dfs(i, j));
		}
	}

	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int k : ans) printf("%d\n", k);
	return 0;
}