/*
	피보나치 배열은 0과 1로 시작하며, 다음 피보나치 수는 바로 앞의 두 피보나치 수의 합이 된다.
	정수 N이 주어지면, N보다 작은 모든 짝수 피보나치 수의 합을 구하여라.
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	int prev_num = 0, cur_num = 1;
	int next_num = prev_num + cur_num;
	int sum = 0;
	while (next_num < n) {
		if (next_num % 2 == 0) {
			sum += next_num;
		}
		int temp = cur_num + next_num;
		cur_num = next_num;
		next_num = temp;
	}

	cout << sum;

	return 0;
}