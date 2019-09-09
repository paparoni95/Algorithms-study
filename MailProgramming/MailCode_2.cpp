/*
	피보나치 배열은 0과 1로 시작하며, 다음 피보나치 수는 바로 앞의 두 피보나치 수의 합이다.
	정수 N이 주어지면, N보다 작은 모든 짝수 피보나치 수의 합을 구해라.
*/
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int prev = 0, cur = 1;
	int next = prev + cur;
	int sum = 0;
	while (next < n) {
		if (next % 2 == 0) {
			sum += next;
		}

		int temp = cur + next;
		cur = next;
		next = temp;
	}

	cout << sum;
	return 0;
}