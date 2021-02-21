#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100000 + 1];
int n, c, ans;

bool calc(int mid)
{
	int cnt = 1;
	int prev = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] - prev >= mid)
		{
			cnt++;
			prev = arr[i];
		}
	}

	return cnt >= c;
}

int main()
{
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &c);

	int left = 0, right = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		right = right < arr[i] ? arr[i] : right;
	}

	sort(arr, arr + n);

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (calc(mid))
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
			
	}

	printf("%d\n", ans);
	return 0;

}