#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v[501];
int n, m, ans;
int in[501], out[501];
bool check[501];

int dfs(int node)
{
	int cnt = 1;
	check[node] = true;
	for (int i = 0; i < v[node].size(); i++)
	{
		int next = v[node][i];
		if (check[next]) continue;
		in[next]++;
		cnt += dfs(next);
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	for (int i = 1; i <= n; i++)
	{
		memset(check, false, sizeof(check));
		out[i] = dfs(i);
	}

	for (int i = 1; i <= n; i++)
	{
		if (in[i] + out[i] == n) ans++;
	}

	cout << ans << endl;
	return 0;
}