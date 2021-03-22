#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, ans;
vector<int> v;

bool calc(int len)
{
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > len)
		{
			sum += v[i] - len;
		}
	}

	return M <= sum;
}

int main()
{
	cin >> N >> M;
	v.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	long long left = 0, right = v[N - 1];
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		if (calc(mid))
		{
			left = mid + 1;
			ans = mid;
		}
		else
			right = mid - 1;
	}

	cout << ans << '\n';
	return 0;
}