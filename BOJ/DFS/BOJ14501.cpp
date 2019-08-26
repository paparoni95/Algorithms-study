#include <iostream>
#include <algorithm>
using namespace std;

int n;
int T[15], P[15];
int ans;

void go(int day, int sum) {
	// 정답
	if (day == n) {
		ans = max(ans, sum);
		return;
	}
	// 불가능한 경우
	if (day > n) {
		return;
	}
	go(day + T[day], sum + P[day]);
	go(day + 1, sum);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> T[i] >> P[i];
	}
	go(0, 0);
	cout << ans;
	return 0;
}