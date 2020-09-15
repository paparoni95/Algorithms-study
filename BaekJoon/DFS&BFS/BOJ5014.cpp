#include <bits/stdc++.h>
using namespace std;

int F, S, G, U, D;
int dist[1000001];

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> F >> S >> G >> U >> D;
	fill(dist, dist + 1000001, -1);

	queue<int> q;
	q.push(S);
	dist[S] = 0;
	bool ok = false;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == G) {
			cout << dist[cur] << '\n';
			ok = true;
			break;
		}

		// up 버튼을 눌렀을 때
		if (cur + U <= F) {
			if (dist[cur + U] == -1) {
				dist[cur + U] = dist[cur] + 1;
				q.push(cur + U);
			}
		}
		// down 버튼을 눌렀을 때
		if (cur - D >= 1) {
			if (dist[cur - D] == -1) {
				dist[cur - D] = dist[cur] + 1;
				q.push(cur - D);
			}
		}
	}

	if (!ok) cout << "use the stairs\n";
	return 0;
}