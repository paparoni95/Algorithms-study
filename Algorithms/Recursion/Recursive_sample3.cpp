#include <bits/stdc++.h>
using namespace std;

// func(a,b,n) n개의 원판을 a에서 b로 옮기는 과정
void func(int a, int b, int n) {
	if (n == 1) { // a에 있는 원판 1개를 b로 옮기기만 하면 됨
		cout << a << ' ' << b << '\n';
		return;
	}
	int c = 6 - a - b; // a, b가 아닌 나머지 기둥의 번호
	func(a, c, n - 1); // a에 있던 1 to n-1번째 원판을 a -> c로 옮김
	cout << a << ' ' << b << '\n'; // a에 남아있던 n번째 원판을 b로 이동
	func(c, b, n - 1); // c에 있던 1 to n-1번째 원판을 c -> b로 옮김
}

int main() {
	func(1, 3, 3);
	return 0;
}