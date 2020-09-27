#include <bits/stdc++.h>
using namespace std;

int cnt;

// 무한히 호출되는 재귀 함수
// VS 기준  ~ 3758 까지 확인
void RecursionFunction() {
	cout << "재귀 함수 호출 " << cnt++ << '\n';
	RecursionFunction();
}

int main() {
	RecursionFunction();
	return 0;
}