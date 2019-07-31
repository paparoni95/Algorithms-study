#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int lcm(int a, int b, int g) {
	return g * (a / g) * (b / g);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		int ans = lcm(a, b, gcd(a, b));
		cout << ans << '\n';
	}
	return 0;
}
