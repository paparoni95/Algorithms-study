#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans;
vector<int> v;

bool calc(int mid)
{
	int cnt = 1, sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += v[i];
		if (sum > mid)
		{
			sum = v[i];
			cnt++;
		}
	}

	if (cnt <= m) return true;
	else return false;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	v.resize(n);

	int left = 0, right = 0, mid;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		left = left < v[i] ? v[i] : left;
		right += v[i];
	}

	ans = right;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (calc(mid))
		{
			right = mid - 1;
			ans = min(ans, mid);
		}
			
		else
		{
			left = mid + 1;
		}
			
	}

	cout << ans << '\n';

	return 0;
}