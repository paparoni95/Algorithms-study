#include <iostream>
using namespace std;

// 참고 : https://mygumi.tistory.com/325

// 최소 공배수는 유클리드 호제법으로 구한다.
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		// x를 고정시키고 m만큼 점프하면서 y를 찾아준다.
		int cnt = x;
		int move_y = x;

		for (int i = 0; i < n; i++) {
			int temp = move_y % n == 0 ? n : move_y % n;
			if (temp == y)
				break;

			move_y = temp + m;
			cnt += m;
		}
		// 두 수의 최소 공배수 보다 크다면 답이 없는 경우이므로
		if (cnt > lcm(m, n)) {
			cout << -1 << '\n';
		}
		else {
			cout << cnt << '\n';
		}
	}
	return 0;
}