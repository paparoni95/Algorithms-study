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
	for (int i = start; i <= n; i++)
	{
		a[index] = i;
		solve(index + 1, i);
	}
}

int main()
{
	cin >> n >> m;
	solve(0, 1);
	return 0;
}