#include <bits/stdc++.h>
using namespace std;

// 피보나치 수열 : 이전 두 항의 합을 현재의 항으로 설정하는 수열


// 시간 복잡도 O(2^N) 지수 시간이 소요
// N = 30, 10억 가량의 연산을 수행
// F(n)에서 n이 커지면 커질수록 반복해서 호출하는 수가 많아진다.

// 피보나치 함수를 재귀함수로 구현
int Fibo(int x) {
	if (x == 1 || x == 2)  return 1;
	return Fibo(x - 1) + Fibo(x - 2);
}

int main() {
	cout << Fibo(4) << '\n';
	return 0;
}