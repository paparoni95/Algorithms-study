#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> v;
bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int d, c;
		cin >> d >> c;
		v.push_back({ d,c });
	}
	sort(v.begin(), v.end(), cmp);

	int ret = 1;
	int now_d = v[0].first;
	int now_c = v[0].second;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (v[j].first > now_d && v[j].second < now_c)
			{
				ret++;
				now_d = v[j].first;
				now_c = v[j].second;
				break;
			}
		}
	}
	cout << ret << '\n';
	return 0;
}