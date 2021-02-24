#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int m, n, k;
int block[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

vector<int> v;

int bfs(int x, int y)
{
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ x,y });
	block[x][y] = 1;
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			{
				if (block[nx][ny] == 0)
				{
					block[nx][ny] = 1;
					cnt++;
					q.push({ nx,ny });
				}
			}
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> m >> n >> k;
	while(k--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = x1; i < x2; i++)
		{
			for (int j = y1; j < y2; j++)
			{
				block[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (block[i][j] == 0)
			{
				v.push_back(bfs(i, j));
			}
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	return 0;
}