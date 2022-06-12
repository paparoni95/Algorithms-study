#include <iostream>
#include <vector>
using namespace std;

int N, M, S;
vector<int> graph[100001];
bool fans[100001];
bool found = false;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}

	cin >> S;
	for (int i = 0; i < S; i++)
	{
		int x;
		cin >> x;
		fans[x] = true;
	}
}

void dfs(int cur)
{
	// 팬을 만나지 않는 루트가 있다면 탈출 혹은 이미 팬이라면 우회하자.
	if (found || fans[cur]) return;

	// 팬을 만나지 않는 루트를 발견했다.
	if (graph[cur].size() == 0)
	{
		found = true;
		return;
	}

	// 우선 계속 경로가 있다면 가본다.
	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next = graph[cur][i];
		dfs(next);
	}
}

void solve()
{
	input();
	dfs(1);

	if (found == false)
		cout << "Yes\n";
	else
		cout << "yes\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}
