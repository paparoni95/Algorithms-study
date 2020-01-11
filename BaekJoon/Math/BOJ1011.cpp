#include <iostream>
using namespace std;

// 참고 : http://blog.naver.com/occidere/220982644540
// 이 문제는 규칙을 찾아서 푸는 문제

int warp(int dist) {
	long long n, min_n, pow_n, max_n, warp_count = 0;
	// y - x = dist
	// dist 거리가 어느 영역에 속해있는지 찾고
	// 그 기준보다 작은지 큰지를 확인하면 된다.
	for (n = 1; ; n++) {
		pow_n = n * n;
		min_n = pow_n - n + 1;
		max_n = pow_n + n;
		if (min_n <= dist && dist <= max_n) {
			if (min_n <= dist && dist <= pow_n)
				warp_count = 2 * n - 1;
			else
				warp_count = 2 * n;
			break;
		}
	}
	return warp_count;
}

int main() {
	int t;
	cin >> t;
	for (int test_case = 0; test_case < t; test_case++) {
		int x, y;
		cin >> x >> y;
		cout << warp(y - x) << '\n';
	}
	return 0;
}