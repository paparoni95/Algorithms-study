#include <iostream>
using namespace std;

int d[1001]; // d[i] : 2 x i 타일링을 채우는 방법의 수

int solve(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;

	if (d[n]) // memoization
		return d[n];
	else
	{
		d[n] = (solve(n - 1) + solve(n - 2)) % 10007;
	}

	return d[n];
}

int main()
{
	int n;
	cin >> n;
	cout << solve(n);
	return 0;
}