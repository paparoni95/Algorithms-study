#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, M, C;
vector<pair<int, int >> graph[30001];
int d[30001];
const int INF = 1e9;

void dijkstra()
{
	priority_queue<pair<int, int> > pq;
	pq.push({ 0, C });
	while (!pq.empty())
	{
		int distance = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (d[cur] < distance) continue;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int nextDistance = distance + graph[cur][i].second;
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
	cin >> N >> M >> C;
	for (int i = 0; i < M; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		graph[x].push_back({ y,z });
	}

	fill(d, d + 30001, INF);

	dijkstra();

	int city = 0;
	int finishTime = 0;
	for (int i = 1; i <= N; i++) // 메시지를 받는 도시들을 확인
	{
		if (d[i] != INF && i != C)
		{
			city++;
			finishTime = max(finishTime, d[i]);
		}
	}

	cout << city << ' ' << finishTime << '\n';
	return 0;
}