#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20001;
const int INF = 1e9;
int V, E, K;
vector<pair<int, int >> v[MAX];
int d[MAX];

void input()
{
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		bool found = false;
		for (int j = 0; j < v[a].size(); j++)
		{
			if (v[a][j].first == b)
			{
				found = true;
				v[a][j].second = min(v[a][j].second, c);
			}
		}
		if (!found) v[a].push_back({ b,c });
	}
}

void dijkstra()
{
	priority_queue<pair<int, int >> pq;
	pq.push({ 0, K });
	d[K] = 0;
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

void solve()
{
	input();
	
	fill(d, d + MAX, INF);
	dijkstra();

	for (int i = 1; i <= V; i++)
	{
		if (d[i] == INF)
			cout << "INF\n";
		else
			cout << d[i] << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}