#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_SIZE 100 + 1
using namespace std;

int M, N, K;
int a[MAX_SIZE][MAX_SIZE];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int dfs(int x, int y)
{
	int cnt = 1;
	a[x][y] = 1; // 방문한 곳은 색칠하기
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < M && ny < N)
		{
			if (!a[nx][ny]) 
				cnt += dfs(nx, ny);
		}
	}

	return cnt;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> M >> N >> K;
	
	while(K--)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
			{
				a[i][j] = 1;
			}
		}
	}

	vector<int> ans;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!a[i][j])
			{
				ans.push_back(dfs(i, j));
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	return 0;
}
