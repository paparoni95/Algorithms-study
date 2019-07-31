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
	int a, b;
	cin >> a >> b;
	int g = gcd(a, b);
	cout << g << '\n';
	cout << lcm(a, b, g);
	return 0;
}
