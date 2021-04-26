#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	sort(v.begin(), v.end());

	for (auto m : v)
		cout << m.first << ' ' << m.second << '\n';

	return 0;
}