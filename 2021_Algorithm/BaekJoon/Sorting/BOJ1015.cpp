#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> a;
vector<int> sorted_a;
vector<bool> vis;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	a.reserve(n);
	sorted_a.reserve(n);
	vis.resize(n, false);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
		sorted_a.push_back(x);
	}

	sort(sorted_a.begin(), sorted_a.end());
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < sorted_a.size(); j++)
		{
			if (a[i] == sorted_a[j] && !vis[j])
			{
				vis[j] = true;
				cout << j << ' ';
				break;
			}
		}
	}
	cout << '\n';
	return 0;
}