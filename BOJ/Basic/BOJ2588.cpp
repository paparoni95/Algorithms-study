#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;

	// 각 자리의 숫자
	int b1, b2, b3;

	b1 = b / 100;
	b2 = (b % 100) / 10;
	b3 = (b % 100) % 10;

	// (3), (4), (5)에 들어갈 숫자
	int num3, num4, num5;
	num3 = a * b3;
	num4 = a * b2;
	num5 = a * b1;

	cout << num3 << endl;
	cout << num4 << endl;
	cout << num5 << endl;
	cout << num3 + num4 * 10 + num5 * 100;
	return 0;
}