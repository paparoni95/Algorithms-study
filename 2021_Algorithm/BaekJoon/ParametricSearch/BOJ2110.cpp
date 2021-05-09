#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, c;
vector<int> v;

bool calc(int len)
{
	int house = 1;
	int cur = v.front();
	for (int i = 1; i < n; i++)
	{
		if (v[i] >= cur + len)
		{
			house++;
			cur = v[i];
		}
	}

	return c <= house;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());

	long long s = 0;
	long long e = 1e9;
	int ans = 0;
	while (s <= e)
	{
		long long mid = (s + e) / 2;
		
		if (calc(mid))
		{
			ans = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}

	cout << ans << '\n';
	return 0;
}