#include <iostream>
using namespace std;

// 기존의 피보나치 수열을 구할 때
// 메모이제이션을 이용해서 다이나믹 프로그래밍 기법을 적용시키자.
// 시간 복잡도 O(N)
// 다이나믹 프로그래밍은 모든 문제는 1번씩만 푼다.
// 모든 문제 * 1문제를 푸는 시간
// N번 호출 * O(1)
// O(N)
int memo[100];

int fibonacci(int x) {
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (memo[x] != 0) return memo[x]; // 이미 답을 풀었다면 그 답을 반환
	return memo[x] = fibonacci(x - 1) + fibonacci(x - 2);
}

int main() {
	cout << fibonacci(10) << '\n';
	cout << fibonacci(30) << '\n';
	//cout << fibonacci(50) << '\n'; 오버플로우 (int형을 벗어난다)
	return 0;
}