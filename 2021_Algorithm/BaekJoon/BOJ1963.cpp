#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

// bfs + eratosthenes
bool prime[10000];
bool vis[10000];

void init() {
	for (int i = 2; i < 10000; i++) {
		if (prime[i] == false) {
			for (int j = i + i; j < 10000; j += i) {
				prime[j] = true;
			}
		}
	}
}

int bfs(int start, int end) {
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	vis[start] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (cur == end) return cost;
		for (int i = 0; i < 4; i++) {
			for (char j = '0'; j <= '9'; j++) {
				string str = to_string(cur);
				str[i] = j;
				int next = stoi(str);

				if (next < 1000 || next > 9999) continue;
				if (vis[next] || prime[next]) continue;
				vis[next] = true;
				q.push({ next, cost + 1 });
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	init();

	int tc, start, end;
	cin >> tc;
	while (tc--) {
		cin >> start >> end;
		fill(vis, vis + 10000, false);
		cout << bfs(start, end) << '\n';
	}
	return 0;
}