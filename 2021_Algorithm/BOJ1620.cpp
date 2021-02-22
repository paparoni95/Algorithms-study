#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> mp1;
map<int, string> mp2;
int n, m;

void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;

		mp1[s] = i;
		mp2[i] = s;
	}
}

void solve()
{
	input();

	for (int i = 1; i <= m; i++)
	{
		string s;
		cin >> s;

		if (mp1.find(s) != mp1.end())
			cout << mp1[s] << '\n';
		else
			cout << mp2[stoi(s)] << '\n';
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