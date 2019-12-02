#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int sum = 0, ans = 0;
	do
	{
		sum = 0;
		for (int i = 0; i < n - 1; i++)
		{
			sum += abs(v[i] - v[i + 1]);
		}

		if (sum > ans)
			ans = sum;

	} while (next_permutation(v.begin(), v.end()));

	cout << ans;
	return 0;
}