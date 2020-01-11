#include <iostream>
using namespace std;

int a[1001];
int d1[1001]; // d[i] : a[i]를 마지막으로 가지는 lis 길이 (증가하는 부분 수열)
int d2[1001]; // d[i] : a[i]를 시작으로 가지는 lis 길이 (감소하는 부분 수열)

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	// 증가하는 부분 수열을 구해주자.
	for (int i = 0; i < n; i++)
	{
		d1[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j] && d1[j] + 1 > d1[i])
				d1[i] = d1[j] + 1;
		}
	}

	// 감소하는 부분 수열을 구해주자.
	for (int i = n - 1; i >= 0; i--)
	{
		d2[i] = 1;
		for (int j = n - 1; j > i; j--)
		{
			if (a[i] > a[j] && d2[j] + 1 > d2[i])
				d2[i] = d2[j] + 1;
		}
	}

	// 증가 수열 + 감소 수열 - 1(중복되는 가운데 숫자)이 max가 되는 값이 정답.
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (d1[i] + d2[i] - 1 > ans)
			ans = d1[i] + d2[i] - 1;
	}

	cout << ans;
	return 0;
}