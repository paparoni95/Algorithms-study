#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int N, M, K, X;
int graph[101][101];

int main()
{
	freopen("input.txt", "r", stdin);

	cin >> N >> M;

	fill(graph[0], graph[0] + 101 * 101, INF);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (i == j) graph[i][j] = 0;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	cin >> X >> K;

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	// A가 K번 회사를 거쳐서 X번 회사로 가는 최단 경로
	long long ans = graph[1][K] + graph[K][X];
	if (ans >= INF) cout << -1;
	else cout << ans << '\n';
	return 0;
}