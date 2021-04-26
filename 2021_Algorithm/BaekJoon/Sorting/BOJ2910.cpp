#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n, c, x;
map<int, int> mp1; // 빈도수
map<int, int> mp2; // 들어온 순서
vector<pair<int, int>> v;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first == b.first)
		return mp2[a.second] < mp2[b.second];
	else
		return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		mp1[x]++;
		if (!mp2[x])
			mp2[x] = i + 1;
	}

	for (auto p : mp1)
		v.push_back({ p.second, p.first }); // (빈도수, 숫자)
	sort(v.begin(), v.end(), cmp);
	for (auto p : v)
	{
		for (int j = 0; j < p.first; j++)
			cout << p.second << ' ';
	}
	cout << '\n';
	return 0;
}