#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 25 + 1
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int a[MAX_SIZE][MAX_SIZE];
int N, house_cnt, cnt;

vector<int> ans;

void dfs(int x, int y)
{
	cnt++;
	a[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N)
		{
			if (a[nx][ny]) dfs(nx, ny);
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &a[i][j]);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i][j])
			{
				cnt = 0;

				dfs(i, j);          
				house_cnt++;        // 단지 추가
				ans.push_back(cnt); // 각 단지내의 집의 수 저장
			}
		}
	}

	cout << house_cnt << '\n';
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';

	return 0;
}