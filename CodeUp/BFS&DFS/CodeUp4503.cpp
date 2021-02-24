#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[101];
bool check[101];
int n, m;

int bfs(int node)
{
	queue<int> q;
	q.push(node);
	check[node] = true;
	int cnt = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			if (check[next]) continue;
			check[next] = true;
			cnt++;
			q.push(next);
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	cout << bfs(1) << endl;
	return 0;
}