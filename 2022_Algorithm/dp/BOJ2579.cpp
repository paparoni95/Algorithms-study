#include <iostream>
#include <cmath>
using namespace std;

int n;
int arr[301];
int dp[301]; // d[i] : i��°���� ����� ���� ����

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
	// ���� n = 1�� ũ�⿩�� �̸� dp 301���� �����߱� ������ range�� �����ϴ�.
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++)
	{
		// i��°���� ����� ���� ������ ���ϴ� ���
		// i - 2��° ���� ��� + 2�ܰ� �����ؼ� ��� (oxo)
		// i - 3��° ���� ��� + 1�ܰ� + 1�ܰ� �����ؼ� ���(oxoo)
		dp[i] = max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
	}

	cout << dp[n] << endl;

	return 0;
}