#include <iostream>
#include <queue>
#define MAX 101
#define INF 987654321
using namespace std;

int N, M;
int friends[MAX][MAX];
int visited[MAX];
int dist[MAX];
int ans[MAX];

void init()
{
	for (int i = 0; i <= N; i++) {
		dist[i] = INF;
		visited[i] = 0;
	}

}

int bfs(int cur)
{
	int cnt = 0;
	queue<int> q;
	q.push(cur);
	visited[cur] = 1; dist[cur] = 0;
	while (!q.empty()) {
		int cur_node = q.front();
		q.pop();
		/* 인접된 노드의 수만큼 */
		for (int k = 1; k <= N; k++) {
			if (visited[k] == 0 && dist[k] == INF) {
				if (friends[cur_node][k] == 1 && friends[k][cur_node] == 1) {
					visited[k] = 1;
					dist[k] = dist[cur_node] + 1;
					q.push(k);
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (dist[i] != INF)
			cnt += dist[i];
	}
	return cnt;
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int x, y;
		cin >> x >> y;
		/* 양방향 표시 */
		friends[x][y] = friends[y][x] = 1;
	}
	/* 각 노드의 케빈 베이컨의 수 구하기 */
	for (int i = 1; i <= N; i++) {
		init();
		ans[i] = bfs(i);
	}
	int result = ans[1]; int idx = 1;
	for (int i = 1; i <= N; i++) {
		if (result > ans[i]) {
			result = ans[i];
			idx = i;
		}
	}
	cout << idx;
	return 0;
}