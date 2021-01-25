#include <iostream>
#include <string>
using namespace std;

// 문제 접근법
// 새로운 풀이였다.
// 수직으로 지나갔는지 표시하는 r배열과, 수평으로 지나갔는지 표시하는 c배열을 통해서
// 둘 다 지나갔다면 '+',
// 수직으로만 지나갔다면 '|'
// 수평으로만 지나갔다면 '-'
// 그 외의 것들은 '.'
// 복잡한 것을 간단하게 지나간 경로를 체크해서 확인하는 것이 색다른 경험이였다.

int n;
string s;
bool r[101][101]; // 수직으로 지나간 위치
bool c[101][101]; // 수평으로 지나간 위치
int x, y;

// 경계 체크
bool isValidLocation(int nx, int ny)
{
	if (nx < 0 || ny < 0 || nx >= n || ny >= n)
		return false;

	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'U')
		{
			if (!isValidLocation(x - 1, y)) continue;

			r[x][y] = true;
			r[--x][y] = true;
		}
		else if (s[i] == 'D')
		{
			if (!isValidLocation(x + 1, y)) continue;

			r[x][y] = true;
			r[++x][y] = true;
		}
		else if (s[i] == 'L')
		{
			if (!isValidLocation(x, y - 1)) continue;

			c[x][y] = true;
			c[x][--y] = true;
		}
		else
		{
			if (!isValidLocation(x, y + 1)) continue;

			c[x][y] = true;
			c[x][++y] = true;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (r[i][j] && c[i][j]) cout << '+';
			else if (r[i][j]) cout << '|';
			else if (c[i][j]) cout << '-';
			else cout << '.';
		}
		cout << '\n';
	}

	return 0;
}