#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int d[1000001];
int n;

int solve(int n)
{
	if (n == 1) return 0;
	if (d[n] != -1) return d[n];

	d[n] = solve(n - 1) + 1;
	if (n % 3 == 0)
	{
		d[n] = min(d[n], solve(n / 3) + 1);
	}

	if (n % 2 == 0)
	{
		d[n] = min(d[n], solve(n / 2) + 1);
	}

	return d[n];
}

int main()
{
	cin >> n;
	memset(d, -1, sizeof(d));
	cout << solve(n);
	return 0;
}