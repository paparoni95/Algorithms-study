#include <iostream>
using namespace std;

char a[21][21];
bool check[26]; // 알파벳을 담을 공간
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int row, col;
int cnt;
int ans;

void solve(int x, int y)
{
	check[a[x][y] - 65] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < row && ny >= 0 && ny < col)
		{
			if (check[a[nx][ny] - 65] == false)
			{
				cnt++; // 한 칸을 지났기 때문에
				if (cnt > ans)
					ans = cnt;
				solve(nx, ny);
			}
		}
	}

	// backtracking
	cnt--;
	check[a[x][y] - 65] = false;
}

int main()
{
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> a[i][j];

	cnt = ans = 1;
	solve(0, 0);
	cout << ans;
	return 0;
}