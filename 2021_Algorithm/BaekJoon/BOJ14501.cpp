#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
int t[16];
int p[16];

void go(int day, int sum) {
	if (day >= n + 1) {
		ans = max(ans, sum);
		return;
	}

	if(day + 1 <= n + 1)
		go(day + 1, sum);
	if(day + t[day] <= n + 1)
		go(day + t[day], sum + p[day]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	go(1, 0);
	cout << ans << '\n';
	return 0;
}