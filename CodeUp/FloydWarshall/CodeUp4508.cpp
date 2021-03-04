#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int n, m;
int dist[101][101];
int maxi[101];
bool check[101];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = (i == j) ? 0 : INF;

	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		dist[a][b] = dist[b][a] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (dist[i][j] < INF && dist[i][j] > maxi[i])
				maxi[i] = dist[i][j];

	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		if (!check[i])
		{
			int node = i;
			for (int j = i; j <= n; j++)
			{
				if (dist[i][j] < INF)
				{
					check[j] = true;
					if (maxi[node] > maxi[j])
						node = j;
				}
			}
			ans.push_back(node);
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
	return 0;
}