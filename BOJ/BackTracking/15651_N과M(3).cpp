#include <iostream>
using namespace std;

int n, m;
int a[8];

void solve(int index)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
			cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		a[index] = i;
		solve(index + 1);
	}
}

int main()
{
	cin >> n >> m;
	solve(0);
	return 0;
}