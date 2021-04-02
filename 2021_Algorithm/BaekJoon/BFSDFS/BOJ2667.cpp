#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
int house[25][25];
bool vis[25][25];
vector<int> ans;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void bfs(int x, int y)
{
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ x,y });
	vis[x][y] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (house[nx][ny] && !vis[nx][ny])
			{
				vis[nx][ny] = true;
				cnt++;
				q.push({ nx,ny });
			}
		}
	}

	ans.push_back(cnt);
}

int main()
{
	freopen("input.txt", "r", stdin);

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); ++j)
		{
			house[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (house[i][j] && !vis[i][j])
			{
				bfs(i, j);
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << '\n';

	return 0;
}