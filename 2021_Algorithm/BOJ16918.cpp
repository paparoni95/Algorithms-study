#include <iostream>
#include <vector>

#define endl "\n";
#define MAX 201
using namespace std;

int r, c, n;
int time[MAX][MAX];
char board[MAX][MAX];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void print()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void input()
{
	cin >> r >> c >> n;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'O')
				time[i][j] = 3;
		}
	}
}

void installBomb(int t) // 폭탄이 없는 위치에 폭탄을 설치
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 'O') continue;
			board[i][j] = 'O';
			time[i][j] = t + 3;
		}
	}
}

void explosionBomb(int t) // t초인 폭탄들을 터트린다.
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (time[i][j] == t)
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
					if (board[nx][ny] == '.') continue;
					board[nx][ny] = '.';
				}
				board[i][j] = '.';
				time[i][j] = 0;
			}
		}
	}
}

void solve()
{
	int t = 2;
	while (1)
	{
		if (t == n + 1) break; // 1초 까지는 영향이 없으므로

		if (t % 2 == 0)
			installBomb(t);
		else
			explosionBomb(t);

		t++;
	}
	print();
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	input();
	solve();
	return 0;
}