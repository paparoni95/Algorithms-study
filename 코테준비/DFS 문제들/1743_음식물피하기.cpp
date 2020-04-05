#include <iostream>
#include <vector>

#define MAX_SIZE 100 + 1
using namespace std;

vector<pair<int, int>> pos;
int a[MAX_SIZE][MAX_SIZE];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int N, M, K, ans, cnt;

void dfs(int x, int y)
{
	cnt++;
	a[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < M)
		{
			if (a[nx][ny] == 1) dfs(nx, ny);
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		int r, c;
		cin >> r >> c;
		a[r - 1][c - 1] = 1;
		pos.push_back({ r - 1,c - 1 });
	}

	for (int i = 0; i < pos.size(); i++)
	{
		cnt = 0;

		int x = pos[i].first;
		int y = pos[i].second;

		if (a[x][y] == 1) dfs(x, y);
		if (cnt > ans) ans = cnt;
	}

	cout << ans << '\n';
	return 0;
}