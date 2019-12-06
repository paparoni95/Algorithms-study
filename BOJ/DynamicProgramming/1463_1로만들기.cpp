#include <iostream>
#include <algorithm>
using namespace std;

int d[1000001];

int solve(int n)
{
	if (n == 1) return 0;

	// memoization
	if (d[n]) return d[n];

	// 일단 1을 빼고 본다. (여기서는 가장 최소값이라 생각하고 저장하는 방식)
	d[n] = solve(n - 1) + 1;

	if (n % 3 == 0)
		d[n] = min(d[n], solve(n / 3) + 1); // 기존에 구한 d[n]과 3으로 나눈 값과 비교해서 더 작은 값을 저장한다.

	if (n % 2 == 0)
		d[n] = min(d[n], solve(n / 2) + 1);

	return d[n];
}

int main()
{
	int n;
	cin >> n;
	cout << solve(n);
	return 0;
}