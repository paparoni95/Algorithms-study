#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	cout << v[k - 1] << '\n';
	return 0;
}