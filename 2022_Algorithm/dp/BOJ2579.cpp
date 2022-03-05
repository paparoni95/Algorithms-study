#include <iostream>
#include <cmath>
using namespace std;

int n;
int arr[301];
int dp[301]; // d[i] : i번째까지 밟았을 때의 총점

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	// botton-up
	// 값이 n = 1의 크기여도 미리 dp 301개를 선언했기 때문에 range에 적합하다.
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++)
	{
		// i번째까지 밟았을 때의 총점을 구하는 경우
		// i - 2번째 까지 밟고 + 2단계 점프해서 밟기 (oxo)
		// i - 3번째 까지 밟고 + 1단계 + 1단계 점프해서 밟기(oxoo)
		dp[i] = max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
	}

	cout << dp[n] << endl;

	return 0;
}