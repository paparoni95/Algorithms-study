#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
int board[101][101];
bool vis[101][101];

int bfs()
{
	int dx[] = { 0,0,-1,1 };
	int dy[] = { 1,-1,0,0 };

	queue<pair<pair<int, int>, int> > q;
	q.push({ {0,0}, 1 });
	vis[0][0] = true;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == n - 1 && y == m - 1)
			return cnt;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] == 1 && !vis[nx][ny])
			{
				vis[nx][ny] = true;
				q.push({ {nx,ny}, cnt + 1 });
			}
		}
	}

	return -1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); ++j)
		{
			board[i][j] = str[j] - '0';
		}
	}

	cout << bfs() << '\n';
	return 0;
}