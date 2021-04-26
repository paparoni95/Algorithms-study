#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;

bool cmp(string& a, string& b)
{
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());

	for (string s : v)
		cout << s << '\n';
	return 0;
}