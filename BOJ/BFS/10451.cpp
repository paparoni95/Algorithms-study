#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int mp[MAX];
int visit[MAX];
int N;

void bfs(int start)
{
	visit[start] = 1;
	queue<int> q;
	q.push(mp[start]);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (visit[cur] == 1) break;
		visit[cur] = 1;
		q.push(mp[cur]);
	}
}

void initArray()
{
	for (int k = 1; k <= N; k++) {
		visit[k] = 0;
		mp[k] = 0;
	}
}

int main()
{
	int tc, cnt = 0;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cnt = 0;
		initArray();
		cin >> N;
		for (int j = 1; j <= N; j++) {
			cin >> mp[j];
		}
		for (int k = 1; k <= N; k++) {
			if (visit[k] == 0) {
				bfs(k);
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}