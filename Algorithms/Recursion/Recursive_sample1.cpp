#include <bits/stdc++.h>
using namespace std;

// n을 입력받아 n부터 1까지 차례대로 출력
void func(int n) {
	cout << n << ' ';
	if (n == 1) return; // base condition;
	func(n - 1);
}

int main() {
	func(5);
	return 0;
}