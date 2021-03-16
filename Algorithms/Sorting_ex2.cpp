#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<pair<string, int>> v;

bool compare(pair<string, int>& a, pair<string, int>& b)
{
	return a.second < b.second;
}

int main()
{
	cin >> n;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		string s;
		int x;
		cin >> s >> x;
		v.push_back({ s,x });
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++)
	{
		cout << v[i].first << ' ';
	}

	return 0;
}