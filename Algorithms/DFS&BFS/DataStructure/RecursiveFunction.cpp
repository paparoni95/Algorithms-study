#include <bits/stdc++.h>
using namespace std;

void RecursionFunction(int i) {
	// 5번째 호출을 했을 때 종료되도록 종료 조건 명시
	if (i == 5) return;
	cout << i << "번째 재귀 함수에서 " << i + 1 << "번째 재귀함수를 호출" << '\n';
	RecursionFunction(i + 1);
	cout << i << "번째 재귀 함수를 종료합니다." << '\n';
}

int main() {
	RecursionFunction(1);
	return 0;
}