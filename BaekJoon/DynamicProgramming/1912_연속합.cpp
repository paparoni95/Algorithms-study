#include <iostream>
#include <algorithm>
using namespace std;

int a[100001];
int d[100001]; // d[i] : a[1] ~ a[i]까지의 연속합 최대
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	d[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		d[i] = max(d[i - 1] + a[i], a[i]);
	}

	int ans = -1000;
	for (int i = 0; i < n; i++)
		if (d[i] > ans)
			ans = d[i];

	cout << ans;
	return 0;
}
