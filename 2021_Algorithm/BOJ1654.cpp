#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int k, n;
vector<int> v;

// 범위에 따른 자료형을 주의하자.

void input()
{
	cin >> k >> n;
	v.resize(k);
	for (int i = 0; i < k; i++) cin >> v[i];
}

void solve()
{
	input();

	long long left = 0, right = INT_MAX;
	int answer = 0;
	while (left <= right)
	{
		long long cnt = 0;
		long long mid = (left + right) / 2;
		for (int i = 0; i < k; i++)
		{
			cnt += v[i] / mid;
		}

		if (cnt >= n)
		{
			answer = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("input.txt", "r", stdin);

	solve();

	return 0;
}