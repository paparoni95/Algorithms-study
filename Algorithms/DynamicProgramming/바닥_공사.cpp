#include <bits/stdc++.h>
using namespace std;

// 앞서 계산된 결과를 저장하기 위한 DP 테이블 초기화
int d[1001];
int n;

int main() {
	cin >> n;

	// 다이나믹 프로그래밍 진행(바텀업)
	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + 2 * d[i - 2]) % 796796;
	}

	// 계산된 결과 출력
	cout << d[n] << '\n';
	return 0;
}