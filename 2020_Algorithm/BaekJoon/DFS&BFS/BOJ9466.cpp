// https://bcp0109.tistory.com/32
// 나중에 다시 풀어보자.(생각보다 어려움)
#include <bits/stdc++.h>
using namespace std;

int n, cnt;
bool visited[100001];  // 방문여부 체크
bool finished[100001]; // 방문한 노드에서 싸이클을 이미 뽑았는지
int arr[100001];

void DFS(int now) {
	if (visited[now]) return;

	visited[now] = true;
	int next = arr[now];

	if (visited[next] != true) DFS(next);
	else {
		if (finished[next] != true) {
			// 노드가 끝나려면 싸이클을 무조건 거쳐야한다.
			// 따라서 현재 노드가 아닌 다음 노드 기준으로 하면 싸이클이 무조건 존재
			cnt++; // 자기 자신
			for (int i = next; i != now; i = arr[i])
				cnt++;
		}
	}

	// 모든 작업이 끝나서 더이상 사용 x 
	finished[now] = true;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		fill(visited, visited + 100001, false);
		fill(finished, finished + 100001, false);
		cnt = 0;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		for (int i = 1; i <= n; i++) {
			DFS(i);
		}

		cout << n - cnt << '\n';
	}
	return 0;
}