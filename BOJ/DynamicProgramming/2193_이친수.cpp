#include <iostream>
using namespace std;

long long d[91][2]; // d[N][i] : N자리의 이친수, 단 마지막 숫자는 i라고 하면

int main()
{
	int n;
	cin >> n;

	d[1][0] = 0;
	d[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}

	long long ans = d[n][0] + d[n][1];
	cout << ans;
	return 0;
}