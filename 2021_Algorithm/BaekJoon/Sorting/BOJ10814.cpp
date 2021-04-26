#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
vector<pair<int, string>> v; // (이름, 나이)

bool cmp(pair<int, string> a, pair<int, string> b)
{
	if (a.first < b.first)
		return true;
	else if (a.first == b.first)
		return false;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		string name;
		int age;
		cin >> age >> name;
		v.emplace_back(age, name);
	}

	stable_sort(v.begin(), v.end(), cmp);
	for (auto p : v)
		cout << p.first << ' ' << p.second << '\n';

	return 0;
}