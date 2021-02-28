#include <iostream>
using namespace std;

int n;
int a[500][500];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
int ratio[] = { 1,1,2,2,7,7,10,10,5 };
int blowX[4][10] =
{
	{-1,1,-2,2,-1,1,-1,1,0,0},
	{-1,-1,0,0,0,0,1,1,2,1},
	{-1,1,-2,2,-1,1,-1,1,0,0},
	{1,1,0,0,0,0,-1,-1,-2,-1}
};
int blowY[4][10] =
{
	{1,1,0,0,0,0,-1,-1,-2,-1},
	{-1,1,-2,2,-1,1,-1,1,0,0},
	{-1,-1,0,0,0,0,1,1,2,1},
	{-1,1,-2,2,-1,1,-1,1,0,0}
};

bool isRange(int x, int y)
{
	return x >= 0 && y >= 0 && x < n && y < n;
}

// 모래의 흩날림 처리와 격자 밖 모래 반환
int blowSand(int x, int y, int dir)
{
	int ret = 0;
	int init = a[x][y];

	for (int i = 0; i < 10; i++)
	{
		int sand = 0;
		if (i != 9)
		{
			sand = init * ratio[i] / 100;
			a[x][y] -= sand;
		}
		else // 모래가 번지고 남은 모래들이 a에 모인다.
			sand = a[x][y];

		int nx = x + blowX[dir % 4][i];
		int ny = y + blowY[dir % 4][i];

		if (!isRange(nx, ny)) // 격자밖으로 나간다면 흘린 모래를 담는다.
		{
			ret += sand;
			continue;
		}

		a[nx][ny] += sand; // 번진 모래를 더해준다.
	}

	a[x][y] = 0; // 모래가 움직였으니 기존 모래는 지운다.

	return ret;
}

int solve()
{
	int ret = 0, x = n / 2, y = n / 2, dir = 0;

	// 토네이도 이동
	for (double i = 1.0; i <= n; i += 0.5)
	{
		for (int j = 0; j < (int)i; j++)
		{
			x += dx[dir % 4];
			y += dy[dir % 4];

			ret += blowSand(x, y, dir);
		}
		dir++;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	cout << solve() << endl;

	return 0;
}