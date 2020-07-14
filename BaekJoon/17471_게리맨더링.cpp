#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int person[11];                // 각 구역의 인구수
vector<vector<int>> graph;     // 양방향 연결 그래프

bool sel[11];                  // 구역 선택
bool visited[11];              // 방문 여부

vector<int> v1, v2;            // 구역 v1, v2
int v1_cnt, v2_cnt, city_cnt;
int ans = 987654321;

void init_select()
{
	for (int i = 1; i <= N; i++)
	{
		sel[i] = false;
	}
}

void init_visit()
{
	for (int i = 1; i <= N; i++)
	{
		visited[i] = false;
	}
}

// 구역이 서로 연결되어있는지 그래프를 탐색한다.
void dfs(int x)
{
	city_cnt++;
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++)
	{
		int next = graph[x][i];
		if (visited[next] == false)
		{
			dfs(next);
		}
	}
}

void select_city(int idx, int cnt, int goal)
{
	if (cnt == goal)
	{
		v1.clear();
		v2.clear();
		// 구역을 v1과 v2로 나눈다.
		for (int i = 1; i <= N; i++)
		{
			if (sel[i] == true) v1.push_back(i);
			else v2.push_back(i);
		}

		// v1 검증
		city_cnt = 0;
		init_visit();
		for (int i = 0; i < v2.size(); i++) visited[v2[i]] = true;
		dfs(v1.front());
		if (v1.size() != city_cnt) return; // 해당 v1 구역이 서로 연결되어 있는지? 아니라면 종료.

		// v2 검증
		city_cnt = 0;
		init_visit();
		for (int i = 0; i < v1.size(); i++) visited[v1[i]] = true;
		dfs(v2.front());
		if (v2.size() != city_cnt) return;

		// 두 선거구의 인구 차이를 구해서 갱신시킨다.
		int v1_total = 0, v2_total = 0;
		for (int i = 0; i < v1.size(); i++) v1_total += person[v1[i]];
		for (int i = 0; i < v2.size(); i++) v2_total += person[v2[i]];

		ans = min(ans, abs(v1_total - v2_total));
		return;
	}

	// 조합 구하기
	for (int i = idx; i <= N; i++)
	{
		if (sel[i] == true) continue;
		sel[i] = true;
		select_city(i, cnt + 1, goal);
		sel[i] = false;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	graph.resize(N + 1);
	for (int i = 1; i <= N; i++) cin >> person[i];
	for (int i = 1; i <= N; i++)
	{
		int len;
		cin >> len;
		for (int j = 0; j < len; j++)
		{
			int u;
			cin >> u;
			// 양뱡향 연결
			graph[i].push_back(u);
			graph[u].push_back(i);
		}
	}

	// 구역을 [i] , [N - i] 두 구역으로 나눠서 확인한다.
	for (int i = 1; i < N; i++)
	{
		init_select();
		select_city(1, 0, i);
	}

	if (ans == 987654321) cout << -1;
	else cout << ans;

	return 0;
}