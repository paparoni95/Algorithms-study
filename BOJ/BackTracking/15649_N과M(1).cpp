#include <iostream>
using namespace std;

int a[9]; // 선택한 숫자를 담을 공간
bool check[9];
int n, m;

void solve(int index, int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (check[i] == false)
			{
				a[index] = i;
				check[i] = true;
				solve(index + 1, k + 1);
				check[i] = false;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	solve(0, 0);
	return 0;
}