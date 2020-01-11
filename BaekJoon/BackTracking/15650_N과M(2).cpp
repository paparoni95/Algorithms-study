#include <iostream>
using namespace std;

int n, m;
int a[9];

void solve(int index, int start)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
			cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	// 오름차순으로 숫자를 뽑으므로, check배열을 두지 않아도 된다.
	for (int i = start; i <= n; i++)
	{
		a[index] = i;
		solve(index + 1, i + 1);
	}
}

int main()
{
	cin >> n >> m;
	solve(0, 1);
	return 0;
}