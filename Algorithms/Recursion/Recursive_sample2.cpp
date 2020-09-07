#include <bits/stdc++.h>
using namespace std;

// n을 입력 받아 n부터 1까지 곱한 결과 n!
int func(int n) {
	if (n == 1) return 1; // base condition
	return n * func(n - 1);
}

int main() {
	cout << func(5);
	return 0;
}