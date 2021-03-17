#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 501;
int tc, n, m;
int indegree[MAX];
bool graph[MAX][MAX];

void topologySort()
{
	vector<int> result;
	queue<int> q;

	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			q.push(i);

	bool isUnique = true;
	bool cycle = false;

	for (int i = 0; i < n; i++)
	{
		if (q.empty())
		{
			cycle = true;
			break;
		}

		// 가능한 정렬 결과가 여러 가지라는 의미
		// 팀의 출력은 유일해야됨.
		if (q.size() >= 2)
		{
			isUnique = false;
			break;
		}

		int now = q.front();
		q.pop();
		result.push_back(now);
		for (int j = 1; j <= n; j++)
		{
			// now -> j 로 가는 간선이 존재한다면, now가 없어지고
			// 해당 진입 차수를 감소시켜준다.
			if (graph[now][j])
			{
				indegree[j]--;
				if (indegree[j] == 0)
					q.push(j);
			}
		}
	}

	// 사이클이 발생했다는 것은 위상 정렬의 위배된다.
	if (cycle)
		cout << "IMPOSSIBLE\n";
	// 확실한 순위가 아닌 여러 가지의 순위 결과가 나온다면 모호하다.
	else if (isUnique == false)
		cout << "?\n";
	else
	{
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << ' ';
		cout << '\n';
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	cin >> tc;
	while (tc--)
	{
		fill(indegree, indegree + MAX, 0);
		fill(graph[0], graph[0] + MAX * MAX, false);

		cin >> n;
		vector<int> lastRank(n, 0);
		for (int i = 0; i < n; i++) cin >> lastRank[i];

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				// 자신보다 낮은 등수 팀을 모두 가리킨다.
				graph[lastRank[i]][lastRank[j]] = true;
				indegree[lastRank[j]]++;
			}
		}

		cin >> m;
		// 변경된 사항들 반영하기
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			// 간선 방향 뒤집기
			if (graph[a][b])
			{
				graph[a][b] = false;
				graph[b][a] = true;
				indegree[a]++;
				indegree[b]--;
			}
			else
			{
				graph[a][b] = true;
				graph[b][a] = false;
				indegree[b]++;
				indegree[a]--;
			}
		}

		topologySort();
	}
	return 0;
}