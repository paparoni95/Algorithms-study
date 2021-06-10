#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
//자주 틀린 요인 : calc 판단 함수, 오버플로우, 초깃값 셋팅

int n, m;
vector<int> v;
bool calc(int mid) {
	int group = 1;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] > mid) return false;
		cnt += v[i];
		if (cnt > mid) {
			cnt = v[i];
			group++;
		}
	}

	return m >= group;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	ll left = 0;
	ll right = 1e9;
	ll ans = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (calc(mid)) {
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << ans << '\n';
	return 0;
}