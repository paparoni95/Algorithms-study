#include <bits/stdc++.h>
using namespace std;

// 많이 틀린 문제, 0초와 1초의 BFS로 생각하자.
// 내가 동생을 찾았더라도 시간이 다를 수 있다.
// 그렇기 때문에 time이라는 변수를 추가로 관리해야 한다.
const int MAX = 200002;
int N, K;
bool dist[MAX];

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fill(dist, dist + MAX, false);
	cin >> N >> K;

	queue<pair<int, int>> q;
	q.push({ N, 0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int time = q.front().second;
		q.pop();

		if (cur == K) {
			cout << time;
			break;
		}

		// 순간이동
		if (cur * 2 < MAX && !dist[cur * 2]) {
			dist[cur * 2] = true;
			q.push({ cur * 2, time });
		}

		if (cur - 1 >= 0 && !dist[cur - 1]) {
			dist[cur - 1] = true;
			q.push({ cur - 1, time + 1 });
		}

		if (cur + 1 < MAX && !dist[cur + 1]) {
			dist[cur + 1] = true;
			q.push({ cur + 1,time + 1 });
		}
	}

	return 0;
}