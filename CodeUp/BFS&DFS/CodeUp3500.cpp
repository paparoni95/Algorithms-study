#include <iostream>
#include <vector>
using namespace std;

char board[10][10];
bool check[10][10];
int cnt[10][10];
int r, c;

int dx[] = { -1,-1,-1,0,1,1,1,0 };
int dy[] = { -1,0,1,1,1,0,-1,-1 };

// 주위 8칸을 탐색해서 지뢰가 없으면 계속 탐색하고, 지뢰가 있다면 지뢰 개수를 표시
void dfs(int x, int y)
{
	if (x == 0 || y == 0 || x == 10 || y == 10) return;

	check[x][y] = true;
	int mineCount = 0;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && ny >= 1 && nx <= 9 && ny <= 9 && cnt[nx][ny] == 1)
			mineCount++;
	}

	if (mineCount == 0)
	{
		board[x][y] = '0';
		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && ny >= 1 && nx <= 9 && ny <= 9)
			{
				if (check[nx][ny] == false)
					dfs(nx, ny);
			}
		}
	}
	else
	{
		board[x][y] = mineCount + 48;
		return;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cin >> cnt[i][j];
			board[i][j] = '_';
		}
	}

	cin >> r >> c;
	bool isMine = false;
	if (cnt[r][c] == 1) isMine = true;
	else dfs(r, c);

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (isMine && i == r && j == c) cout << -1 << ' ';
			else cout << board[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}