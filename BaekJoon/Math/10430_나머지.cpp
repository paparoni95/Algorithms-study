#include <iostream>
using namespace std;

int a, b, c;

int main()
{
	cin >> a >> b >> c;

	// 덧셈과 곱셈은 성립하지만, 나눗셈은 성립하지 않는다.
	cout << (a + b) % c << '\n';
	cout << ((a % c) + (b % c)) % c << '\n';
	
	cout << (a * b) % c << '\n';
	cout << ((a % c) * (b % c)) % c << '\n';

	/* 뺄셈의 경우는 아래와 같다 */
	// (a - b) % c = (( a % c ) - ( b % c ) + c ) % c
	return 0;
}