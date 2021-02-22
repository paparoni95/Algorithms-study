#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int tc, n;

void input()
{
	cin >> tc;
}

void solve()
{
	input();

	while (tc--)
	{
		cin >> n;
		if (n == 0)
		{
			cout << 0 << '\n';
			continue;
		}

		map<string, int> mp;

		for (int i = 0; i < n; i++)
		{
			string name, type;
			cin >> name >> type;
			
			mp[type]++;
		}

		vector<int> v;
		for (auto it = mp.begin(); it != mp.end(); it++)
		{
			v.push_back(it->second + 1);
		}

		int ans = v[0];
		for (int i = 1; i < v.size(); i++)
		{
			ans *= v[i];
		}

		cout << ans - 1 << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("input.txt", "r", stdin);

	solve();

	return 0;
}