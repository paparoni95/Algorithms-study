// https://mygumi.tistory.com/243

// 어처피 2개를 뽑는 경우라면 2중 포문으로 구현이 가능하다. 굳이 permutation에 의존하지 않아도...
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int a[21][21];
bool visited[21];
int N, ans = 987654321;

int getStat(vector<int>& v)
{
	int result = 0;
	int len = N / 2;
	for (int i = 1; i <= len; i++)
	{
		for (int j = i + 1; j <= len; j++)
		{
			result += a[v[i]][v[j]];
			result += a[v[j]][v[i]];
		}
	}
	return result;
}

void divideTeam()
{
	vector<int> a(N / 2 + 1);
	vector<int> b(N / 2 + 1);
	int ai = 1, bi = 1;
	// 구해진 경우에서의 두 팀을 배열로 나타낸다.
	for (int i = 1; i <= N; i++)
	{
		if (visited[i]) a[ai++] = i;
		else b[bi++] = i;
	}

	// 두 팀의 능력 차이를 구한다.
	int a_stat = getStat(a);
	int b_stat = getStat(b);
	int diff = abs(a_stat - b_stat);

	ans = min(ans, diff);
}

// 두 팀으로 나눈다.
void dfs(int v, int len)
{
	if (len == N / 2)
	{
		divideTeam();
	}
	else
	{
		for (int i = v + 1; i <= N; i++)
		{
			if (visited[i] == true) continue;
			visited[i] = true;
			dfs(i, len + 1);
			visited[i] = false; // backtracking
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> a[i][j];
		}
	}
	dfs(0, 0);
	cout << ans;
	return 0;
}
