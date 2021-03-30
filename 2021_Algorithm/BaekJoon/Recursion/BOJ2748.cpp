#include <iostream>
using namespace std;

long long memo[91];

long long fibo(long long n)
{
	if (memo[n] > 0) return memo[n];
	if (n == 0 || n == 1) return n;
	else return memo[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long n;
	cin >> n;
	cout << fibo(n);
	return 0;
}