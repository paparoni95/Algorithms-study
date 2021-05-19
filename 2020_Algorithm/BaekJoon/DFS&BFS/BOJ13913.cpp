#include <bits/stdc++.h>
using namespace std;

const int MAX = 100002;

int N, K, ans;
bool visited[MAX];
int parent[MAX];  // 해당 지점 방문 직전 지점 저장
vector<int> path; // 경로 저장

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fill(visited, visited + MAX, false);
	cin >> N >> K;

	queue<pair<int,int>> q;
	q.push({ N, 0 });
	visited[N] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int time = q.front().second;
		q.pop();

		if (cur == K) {
			ans = time;
			int idx = cur;
			while (idx != N) {
				path.push_back(idx);
				idx = parent[idx];
			}
			path.push_back(N);
			break;
		}

		if (cur + 1 < MAX && !visited[cur + 1]) {
			q.push({ cur + 1,time + 1 });
			visited[cur + 1] = true;
			parent[cur + 1] = cur;
		}

		if (cur - 1 >= 0 && !visited[cur - 1]) {
			q.push({ cur - 1,time + 1 });
			visited[cur - 1] = true;
			parent[cur - 1] = cur;
		}

		if (cur * 2 < MAX && !visited[cur * 2]) {
			q.push({ cur * 2,time + 1 });
			visited[cur * 2] = true;
			parent[cur * 2] = cur;
		}
	}

	reverse(path.begin(), path.end());
	cout << ans << '\n';
	for (auto n : path) cout << n << ' ';
	cout << '\n';
	return 0;
}