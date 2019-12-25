#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
bool check[9];
int a[9];
int b[9];

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
		if (check[i]) 
			continue;

		check[i] = true;
		a[index] = b[i];
		solve(index + 1);
		check[i] = false;
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