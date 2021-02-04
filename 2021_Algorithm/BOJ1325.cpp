#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 10001;

int N, M;
vector<vector<int>> graph;
vector<int> v;
bool visit[MAX];

int BFS(int start)
{
	fill(visit, visit + MAX, false);
	int cnt = 1;
	queue<int> q;
	q.push(start);
	visit[start] = true;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			if (!visit[next])
			{
				visit[next] = true;
				cnt++;
				q.push(next);
			}
		}
	}

	return cnt;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	graph.resize(N + 1);
	v.reserve(N + 1);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		int cnt = BFS(i);
		v.push_back(cnt);
	}

	int target = *max_element(v.begin(), v.end());
	vector<int> ans;
	for (int i = 0; i < v.size(); i++)
	{
		if (target == v[i])
		{
			ans.push_back(i + 1);
		}
	}

	sort(ans.begin(), ans.end());
	for (int n : ans) cout << n << ' ';
	cout << '\n';
	return 0;
}