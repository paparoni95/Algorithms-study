#include <iostream>
using namespace std;

int solve(int sum, int goal) {

	// 불가능한 경우
	if (sum > goal) return 0;
	// 종료조건
	if (sum == goal) {
		return 1;
	}

	// 다음에 올 수 있는 경우
	// 1을 더하거나, 2를 더하거나, 3을 더하는 경우를 모두 구해서 저장한다.
	int ans = 0;
	for (int number = 1; number <= 3; number++) {
		ans += solve(sum + number, goal);
	}

	// 나올 수 있는 경우의 수를 반환한다.
	return ans;
}

int main() {
	int tc;
	cin >> tc;

	for (int test_case = 0; test_case < tc; test_case++) {
		int make_number;
		cin >> make_number;
		cout << solve(0, make_number) << '\n';
	}
	return 0;
}