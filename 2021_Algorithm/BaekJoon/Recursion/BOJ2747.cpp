#include <iostream>
using namespace std;

int memo[46];

int fibo(int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else if (memo[n] > 0) return memo[n];
	else return memo[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n; // 1 ~ 45
	cout << fibo(n);
	return 0;
}