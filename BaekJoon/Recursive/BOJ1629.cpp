#include <iostream>
using namespace std;

long long a, b, c;

long long Pow(long long a, long long b, long long c) {
	if (b == 1) return a % c;
	long long val = Pow(a, b / 2, c);
	val = val * val % c;
	if (b % 2 == 0) return val;
	return val * a % c;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;
	cout << Pow(a, b, c) << '\n';
	return 0;
}