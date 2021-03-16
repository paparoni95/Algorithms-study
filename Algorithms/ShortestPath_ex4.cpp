#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// 화성 탐사 문제
int tc, n;
int graph[125][125], d[125][125];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };
const int INF = 1e9;

int main()
{
	freopen("input.txt", "r", stdin);

	cin >> tc;
	while (tc--)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> graph[i][j];

		// 최단 거리 테이블을 모두 무한으로 초기화
		fill(d[0], d[0] + 125 * 125, INF);

		int x = 0, y = 0;
		priority_queue<pair<int, pair<int, int> > > pq; // {(비용), (좌표)}
		pq.push({ -graph[x][y], {0,0} });
		d[x][y] = graph[x][y];
		while (!pq.empty())
		{
			int distance = -pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();

			if (d[x][y] < distance) continue;
			// 현재 노드와 연결된 다른 인접한 노드들을 확인
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				int nextDistance = distance + graph[nx][ny];
				if (nextDistance < d[nx][ny])
				{
					d[nx][ny] = nextDistance;
					pq.push({ -nextDistance, {nx,ny} });
				}
			}
		}

		cout << d[n - 1][n - 1] << '\n';
	}
}