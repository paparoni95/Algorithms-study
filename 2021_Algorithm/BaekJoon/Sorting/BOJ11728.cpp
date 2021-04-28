#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> a, b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	a.reserve(n);
	b.reserve(m);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}

	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		b.push_back(x);
	}

	a.insert(a.end(), b.begin(), b.end());
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << '\n';
	return 0;
}