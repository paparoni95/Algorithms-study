#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char board[10][10];
bool check[10][10];
int x, y;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void bfs(int i, int j)
{
	if (board[i][j] == '*') return;

	queue<pair<int, int> >q;
	q.push({ i,j });
	board[i][j] = '*';
	check[i][j] = true;
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx >= 0 && ny >= 0 && nx < 10 && ny < 10)
			{
				if (board[nx][ny] == '_' && check[nx][ny] == false)
				{
					board[nx][ny] = '*';
					check[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> board[i][j];
		}
	}
		
			

	cin >> y >> x;

	bfs(x, y);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << board[i][j];
		}
		cout << '\n';
	}

	return 0;
}