#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, ans;
int a[101][101];
bool check[101][101];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

void dfs(int x, int y)
{
	check[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n && check[nx][ny] == false)
		{
			dfs(nx, ny);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n;

	int maxH = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			maxH = max(maxH, a[i][j]);
		}
	}


	for (int h = 0; h <= maxH; h++)
	{
		memset(check, false, sizeof(check));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (a[i][j] <= h) 
					check[i][j] = true;

		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (check[i][j] == false)
				{
					cnt++;
					dfs(i, j);
				}
			}
		}

		ans = max(ans, cnt);
	}

	cout << ans << endl;
	return 0;
}