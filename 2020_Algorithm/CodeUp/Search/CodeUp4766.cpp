#include <iostream>
using namespace std;

int n, m, ans;
int arr[10000 + 1];

bool calc(int mid)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > mid)
			sum += mid;
		else
			sum += arr[i];
	}

	return sum <= m;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> n;
	int left = 0, right = 0, mid = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		right = right < arr[i] ? arr[i] : right;
	}
	cin >> m;

	while (left <= right)
	{
		mid = (left + right) / 2;
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