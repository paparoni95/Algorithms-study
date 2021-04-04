#include <iostream>
#include <queue>
using namespace std;

int r, c;
char board[501][501];
bool vis[501][501];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void print()
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << board[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}

bool findSheep(int x, int y)
{
	queue<pair<int, int >> q;
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
			if (nx >= 0 && ny >= 0 && nx < r && ny < c)
			{
				if (board[nx][ny] == 'S' && !vis[nx][ny]) 
					return true;
				else if (board[nx][ny] != 'D' && !vis[nx][ny])
				{
					vis[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}

	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin >> board[i][j];

	bool find = false;
	// 양의 4방향으로 울타리를 설치하자.
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (board[i][j] == 'S')
			{
				for (int k = 0; k < 4; ++k)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 0 && ny >= 0 && nx < r && ny < c)
					{
						if (board[nx][ny] == '.')
							board[nx][ny] = 'D';
					}
				}
			}
		}
	}

	// 늑대가 양을 찾는다.
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (board[i][j] == 'W' && !vis[i][j])
			{
				find = findSheep(i, j);
			}
		}
	}

	if (find)
		cout << 0 << '\n';
	else
	{
		cout << 1 << '\n';
		print();
	}

	return 0;
}