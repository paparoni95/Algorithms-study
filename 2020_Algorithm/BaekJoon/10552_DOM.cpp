// 출처 : https://withallmy.tistory.com/187
// 잘 풀리지 않아서 참고함.
#include <iostream>

#define MAX_SIZE 100000 + 1
using namespace std;

int person[MAX_SIZE];
bool visited[MAX_SIZE];
int N, M, P, ans;

void dfs(int node)
{
	if (!visited[node])
	{
		visited[node] = true;
		if (person[node] != 0)
		{
			ans++; // 채널을 한 번 변경했으니까
			dfs(person[node]);
		}
	}
	else
		ans = -1;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> P;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		// 가장 어린 사람이 좋아하는 채널을 바꾸므로
		if (person[b] == 0)
			person[b] = a;
	}

	// 현재 틀어져있는 채널부터 탐색시작
	dfs(P);
	cout << ans << '\n';
	return 0;
}