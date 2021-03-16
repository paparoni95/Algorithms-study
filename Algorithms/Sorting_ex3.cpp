#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> a, b;

int main()
{
	cin >> n >> k;

	a.reserve(n);
	b.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		b.push_back(x);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	for (int i = 0; i < k; i++)
	{
		if (a[i] < b[i]) swap(a[i], b[i]);
		else break;
	}

	long long sum = 0;
	for (int i = 0; i < n; i++) sum += a[i];

	cout << sum << endl;
	return 0;
}