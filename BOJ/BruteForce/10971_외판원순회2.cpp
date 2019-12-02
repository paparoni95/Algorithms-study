#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[11][11];

bool IsRightRoute(vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (a[v[i]][v[i + 1]] <= 0)
			return false;
	}

	if (a[v[v.size() - 1]][v[0]] <= 0)
		return false;

	return true;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		v[i] = i;

	int ans = 100000000; // 최소 비용을 찾는 문제라서

	do
	{
		if (IsRightRoute(v))
		{
			int sum = 0;
			for (int i = 0; i < n - 1; i++)
			{
				sum += (a[v[i]][v[i + 1]]); // w[i][j] : i -> j
			}
			sum += (a[v[n - 1]][v[0]]);

			if (ans > sum)
				ans = sum;
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << ans;
	return 0;
}