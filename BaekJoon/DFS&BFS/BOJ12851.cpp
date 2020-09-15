#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int N, K, cnt, min_time;
bool visited[MAX];

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	fill(visited, visited + MAX, false);

	queue<pair<int, int>> q;
	q.push({ N, 0 });
	visited[N] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int time = q.front().second;
		q.pop();

		// 핵심은 큐에 집어 넣을 때, 방문 지점을 표시하는 것이 아닌,
		// pop을 할 때, 방문 지점을 표시하면 여러 가지 경우의 수를 도출 할 수 있다.
		visited[cur] = true;

		// 이미 목적지에 한번 도달했을 경우
		if (min_time && min_time == time && cur == K) cnt++;

		// 최초로 목적지 도달시 최소 시간 기록하고 cnt++
		if (!min_time && cur == K) {
			min_time = time;
			cnt++;
		}

		if (cur + 1 < MAX && !visited[cur + 1]) {
			q.push({ cur + 1,time + 1 });
		}
		if (cur - 1 >= 0 && !visited[cur - 1]) {
			q.push({ cur - 1,time + 1 });
		}
		if (cur * 2 < MAX && !visited[cur * 2]) {
			q.push({ cur * 2, time + 1 });
		}
	}

	cout << min_time << '\n' << cnt << '\n';
	return 0;
}