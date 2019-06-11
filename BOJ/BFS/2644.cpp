#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
vector<int> friends[101];
int cnt[101];
int visit[101];

void bfs(int s)
{
	visit[s] = 1;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int cycle = friends[cur].size();
		for (int k = 0; k < cycle; k++) {
			int next = friends[cur][k];
			if (visit[next] == 0) {
				visit[next] = 1;
				cnt[next] = cnt[cur] + 1; //촌수 증가
				q.push(next);
			}
		}
	}
}

int main()
{
	cin >> n;
	int start, end, m;
	cin >> start >> end;
	cin >> m;
	for (int j = 0; j < m; j++) {
		int u, v;
		cin >> u >> v;
		friends[u].push_back(v); //양방향
		friends[v].push_back(u);
	}

	bfs(start);

	if (cnt[end] == 0) {
		cout << -1;
		return 0;
	}
	else {
		cout << cnt[end];
	}
	return 0;
}