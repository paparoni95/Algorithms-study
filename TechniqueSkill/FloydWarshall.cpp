#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int MAX = 501;

/*
	# 플로이드워셜 알고리즘
	모든 노드에서 다른 모든 노드까지의 최단 경로를 구하는 알고리즘
	다이나믹 프로그래밍 기법이기도 함.

	# 시간 복잡도
	O(N^3)

	# 핵심은
	k가 거쳐가는 노드라고 하면, 점화식은 다음과 같다.
	D[a][b] = min(D[a][b], D[a][k] + D[k][b])
*/

int n, m; // 노드의 개수, 간선의 개수
int graph[MAX][MAX];

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	// 최단 거리 테이블을 모두 무한으로 초기화
	for (int i = 0; i < MAX; i++) fill(graph[i], graph[i] + MAX, INF);

	// 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				graph[i][j] = 0;
		}
	}

	// 각 간선에 대한 정보를 입력 받아, 그 값으로 초기화
	for (int i = 0; i < m; i++)
	{
		// a에서 b로 가는 비용을 c라고 가정하면
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// 도달할 수 없는 경우, 무한 출력
			if (graph[i][j] == INF) cout << "INF ";
			else cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}