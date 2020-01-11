#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[8];
int b[8];
void solve(int index)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
			cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++)
	{
		a[index] = b[i];
		solve(index + 1);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(b, b + n);
	solve(0);
	return 0;
}