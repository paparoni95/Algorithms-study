#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 숨바꼭질 문제

const int INF = 1e9;
int N, M;
vector<pair<int, int>> v[20001];
int d[20001];

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	d[start] = 0;
	while (!pq.empty())
	{
		int distance = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (d[cur] < distance) continue;

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i].first;
			int nextDistance = distance + v[cur][i].second;
			if (nextDistance < d[next])
			{
				d[next] = nextDistance;
				pq.push({ -nextDistance, next });
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back({ b,1 });
		v[b].push_back({ a,1 });
	}

	fill(d, d + 20001, INF);

	dijkstra(1);

	int maxNode = 0;
	int maxDistance = 0;
	vector<int> ans;

	for (int i = 1; i <= N; i++)
	{
		if (maxDistance < d[i])
		{
			maxNode = i;
			maxDistance = d[i];
			ans.clear();
			ans.push_back(maxNode);
		}
		else if (maxDistance == d[i])
		{
			ans.push_back(maxNode);
		}
	}

	cout << maxNode << ' ';
	cout << maxDistance << ' ';
	cout << ans.size() << '\n';
	return 0;
}