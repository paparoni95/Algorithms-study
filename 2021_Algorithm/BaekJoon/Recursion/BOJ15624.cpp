#include <iostream>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll n;
ll memo[1000001];

ll fibo(ll n)
{
	if (memo[n] > 0) return memo[n];
	if (n <= 1) return n;
	return memo[n] = (fibo(n - 1) % MOD + fibo(n - 2) % MOD) % MOD;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	cout << fibo(n);
	return 0;
}