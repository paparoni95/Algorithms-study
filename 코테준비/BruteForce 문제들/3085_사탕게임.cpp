#include <iostream>
#include <algorithm>

#define MAX_SIZE 50 + 1
using namespace std;

char a[MAX_SIZE][MAX_SIZE];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int n;

void swap(int x1, int y1, int x2, int y2)
{
	char temp = a[x1][y1];
	a[x1][y1] = a[x2][y2];
	a[x2][y2] = temp;
}

int solve(int row, int col)
{
	int ret = 0;
	// 행 확인
	int cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[row][i - 1] == a[row][i])
		{
			cnt++;
		}
		else
		{
			ret = max(ret, cnt);
			cnt = 1;
		}
	}
	ret = max(ret, cnt);

	// 열 확인
	cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i - 1][col] == a[i][col])
		{
			cnt++;
		}
		else
		{
			ret = max(ret, cnt);
			cnt = 1;
		}
	}
	ret = max(ret, cnt);
	return ret;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int x = i + dx[k];
				int y = j + dy[k];
				if (x >= 0 && y >= 0 && x < n && y < n)
				{
					if (a[i][j] != a[x][y])
					{
						swap(i, j, x, y);
						ans = max(ans, solve(i, j));
						swap(i, j, x, y);
					}
				}
			}
		}
	}

	// 바꾼 행과 열이 아닌 곳에 최대 길이가 있을 수도 있다.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ans = max(ans, solve(i, j));
		}
	}

	cout << ans << '\n';
	return 0;
}