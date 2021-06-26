#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// greedy, or bruteforce
// 봉우리를 선택한 다음에 오른쪽의 봉우리를 확인하면서 나보다 작은 봉우리의 수를 계속해서 갱신해나간다.
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	int ans = 0;
	int i = 0, j = 0;
	while (1) {
		if (i >= n || j >= n) break;
		while (j + 1 < n && v[i] > v[j + 1]) j++;

		ans = max(ans, j - i);
		i++;
		j = i;
	}

	cout << ans << '\n';
	return 0;
}