// 꽤나 애먹은 문제 -> 시간초과
// 출처 : https://blog.naver.com/kks227/220785731077
#include <iostream>
#include <algorithm>

#define MAX_SIZE 100000 + 1
using namespace std;

int N, cnt;
int student[MAX_SIZE];
bool visited[MAX_SIZE], finished[MAX_SIZE];

void dfs(int cur)
{
	visited[cur] = true;
	int next = student[cur];
	if (!visited[next]) dfs(next);
	else if (!finished[next])
	{
		// 연결되어있는 팀원만큼 카운터 (사이클에 속한 정점의 개수)
		for (int i = next; i != cur; i = student[i])
			cnt++;

		cnt++; // 자기 자신
	}

	finished[cur] = true;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
			scanf("%d", &student[i]);

		fill(visited, visited + N + 1, false);
		fill(finished, finished + N + 1, false);
		cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			if (!visited[i]) dfs(i);
		}
		printf("%d\n", N - cnt);
	}
	return 0;
}