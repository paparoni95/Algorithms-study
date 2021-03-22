#include <iostream>
#include <vector>
using namespace std;

int n, ans = -1;
vector<int> v;

int main()
{
	cin >> n;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	// 인덱스가 크면 left 이동
	// 작으면 right 이동
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (mid == v[mid])
		{
			ans = v[mid];
			break;
		}
		else if (mid > v[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}

	if (ans == -1) cout << -1;
	else cout << ans;
	return 0;
}