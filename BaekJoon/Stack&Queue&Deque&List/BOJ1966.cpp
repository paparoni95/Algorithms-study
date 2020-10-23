#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

int t;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		int n, m, cnt = 0;
		cin >> n >> m;
		queue<pair<int, int>> q;
		deque<int> dq;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			dq.push_back(x);
			q.push({ x,i });
		}

		while (!q.empty()) {
			int curPriority = q.front().first;
			int index = q.front().second;
			q.pop();

			int maxPriority = 0;
			if (dq.size() >= 2) {
				maxPriority = *max_element(dq.begin() + 1, dq.end());
			}
			else {
				maxPriority = dq.front();
			}

			if (maxPriority > curPriority) {
				q.push({ curPriority, index });
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else {
				cnt++;
				dq.pop_front();
				if (index == m) {
					cout << cnt << '\n';
					break;
				}
			}
		}
	}
}