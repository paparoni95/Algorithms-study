#include <iostream>
using namespace std;

// 간단한 문제를 얼마나 정확하게 풀 수 있는지?

int r, c;
int a[101][101]; // 모두 키는 필드
int b[101][101]; // 모두 끄는 필드

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void turnOn(int x, int y)
{
	a[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < r && ny < c)
		{
			if (a[nx][ny] == 0)
			{
				turnOn(nx, ny);
			}
		}
	}
}

void turnOff(int x, int y)
{
	b[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < r && ny < c)
		{
			if (b[nx][ny] == 1)
			{
				turnOff(nx, ny);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	}

	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] == 0)
			{
				turnOn(i, j);
				cnt1++;
			}
			if (b[i][j] == 1)
			{
				turnOff(i, j);
				cnt2++;
			}
		}
	}

	cout << cnt1 << ' ' << cnt2 << endl;
	return 0;
}