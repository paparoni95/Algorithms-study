#include <iostream>
#include <cmath>
using namespace std;

int n, ans;
int col[15]; // col[i] = j : (i,j)에 Queen을 배치

bool isPromising(int row)
{
	// [0 ~ row) 단계 같은 열, 대각선 체크
	for (int i = 0; i < row; i++)
	{
		if (col[i] == col[row]) return false;
		if (abs(i - row) == abs(col[i] - col[row])) return false;
	}

	return true;
}

// row행 까지는 퀸을 놓은 상태,
void dfs(int row)
{
	if (row == n)
	{
		ans++;
		return;
	}
	// row+1행에 퀸을 놓을 수 있는지 없는지 확인 (유망한지?)
	for (int i = 0; i < n; i++)
	{
		col[row] = i;
		if (isPromising(row))
			dfs(row + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	dfs(0);
	cout << ans << '\n';
	return 0;
}