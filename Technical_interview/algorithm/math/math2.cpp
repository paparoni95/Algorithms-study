#include <iostream>
using namespace std;

int main() {
	int num1 = 1e9; // 10억
	int num2 = 2e9; // 20억
	cout << num1 << '\n';
	cout << num2 << '\n';

	// 우선순위 주의
	int mask = 1;
	// == 연산자의 우선순위 > &연산자의 우선순위 => 결과 항상 거짓
	if (mask & 1 == 0) {
		// do something
	}
	return 0;
}