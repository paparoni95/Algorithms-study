#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

ll n, p, q;
map<ll, ll> memo;

ll f(ll n)
{
	if (memo[n]) return memo[n];
	memo[n] = f(n / p) + f(n / q);
	return memo[n];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p >> q;

	memo[0] = 1;
	memo[1] = 2;
	cout << f(n) << '\n';
	return 0;
}
