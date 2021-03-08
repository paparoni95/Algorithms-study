#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

const int MAX = 100001;
const int INF = INT_MAX;

int n, k;
int dist[MAX];

// X -> 2X 0초이므로, 단순히 방문했다는 true/false가 아니고,
// 더 빠른 시간내에 동생을 찾으면 되므로 더 빠른 경우를 찾았다면 그것이 정답이다.

void input()
{
	cin >> n >> k;
	fill(dist, dist + MAX, INF);
}

void findBrother()
{
	queue<int> q;
	q.push(n);
	dist[n] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == k) return;

		// 더 빠른 경로를 찾았다면 갱신하기
		if (cur * 2 < MAX && dist[cur * 2] > dist[cur])
		{
			dist[cur * 2] = dist[cur];
			q.push(cur * 2);
		}

		if (cur + 1 < MAX && dist[cur + 1] > dist[cur])
		{
			dist[cur + 1] = dist[cur] + 1;
			q.push(cur + 1);
		}

		if (cur - 1 >= 0 && dist[cur - 1] > dist[cur])
		{
			dist[cur - 1] = dist[cur] + 1;
			q.push(cur - 1);
		}
	}
}

void solve()
{
	input();
	findBrother();
	cout << dist[k] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}