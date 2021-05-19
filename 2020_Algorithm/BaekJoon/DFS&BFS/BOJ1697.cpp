#include <bits/stdc++.h>
using namespace std;

int N, K, answer;
int dist[100'002];

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;

	fill(dist, dist + 100'002, -1);
	
	queue<int> q;
	q.push(N);
	dist[N] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == K) {
			cout << dist[cur];
			break;
		}

		if (cur + 1 >= 0 && cur + 1 <= 100'002) {
			if (dist[cur + 1] == -1) {
				q.push(cur + 1);
				dist[cur + 1] = dist[cur] + 1;
			}
		}

		if (cur - 1 >= 0 && cur - 1 <= 100'002) {
			if (dist[cur - 1] == -1) {
				q.push(cur - 1);
				dist[cur - 1] = dist[cur] + 1;
			}
		}

		if (cur * 2 >= 0 && cur * 2 <= 100'002) {
			if (dist[cur * 2] == -1) {
				q.push(cur * 2);
				dist[cur * 2] = dist[cur] + 1;
			}
		}
	}
	return 0;
}