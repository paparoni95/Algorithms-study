#include <iostream>
#include <algorithm>
using namespace std;

int a[9];
int b[9];
bool check[9];
int n, m;

void solve(int index, int start)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
			cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i < n; i++)
	{
		a[index] = b[i];
		solve(index + 1, i + 1);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(b, b + n);
	solve(0, 0);
	return 0;
}