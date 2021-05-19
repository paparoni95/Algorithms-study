#include <iostream>
#include <vector>
using namespace std;

int w, h, ans;
int a[100][100];
bool check[100][100];
const int dx[] = { 0,0,-1,1,-1,-1,1,1 };
const int dy[] = { 1,-1,0,0,-1,1,-1,1 };

void dfs(int x, int y)
{
	check[x][y] = true;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < h && ny < w)
		{
			if (a[x][y] && !check[nx][ny])
				dfs(nx, ny);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> w >> h;
	char ch;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> ch;
			if (ch == '.') a[i][j] = 0;
			else a[i][j] = 1;
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (a[i][j] && !check[i][j])
			{
				dfs(i, j);
				ans++;
			}
		}
	}

	cout << ans << endl;
	return 0;
}