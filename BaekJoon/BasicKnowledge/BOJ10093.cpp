#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a, b;
	cin >> a >> b;

	if (a > b) swap(a, b);
	if (a != b) {
		cout << b - a - 1 << '\n';
		for (long long i = a + 1; i < b; i++)
			cout << i << ' ';
		cout << '\n';
	}
	else
		cout << 0 << '\n';
	return 0;
}