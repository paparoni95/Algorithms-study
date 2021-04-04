#include <iostream>
#include <queue>
using namespace std;

int r, c, wolf, sheep;
char field[251][251];
bool vis[251][251];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void findSheepAndWolf(int x, int y)
{
	int w = 0, s = 0;
	queue<pair<int, int >> q;
	q.push({ x,y });
	vis[x][y] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (field[x][y] == 'v') w++;
		if (field[x][y] == 'k') s++;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (field[nx][ny] != '#' && !vis[nx][ny])
			{
				vis[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}

	if (s > w) 
		sheep += s;
	else 
		wolf += w;
}

int main()
{
	freopen("input.txt", "r", stdin);

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin >> field[i][j];

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (field[i][j] != '#' && !vis[i][j])
			{
				findSheepAndWolf(i, j);
			}
		}
	}

	cout << sheep << ' ' << wolf << '\n';
	return 0;
}