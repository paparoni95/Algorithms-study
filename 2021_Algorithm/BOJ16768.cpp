#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 문제 접근법
// 문제 자체를 잘못 이해함 -> 마지막 줄을 기준으로 터지는 줄 알았는데
// 그게 아니라 인접한 애들이 k이상이면 터질 수 있음.
// 시간 초과가 나서 해결법을 통해 작성함.

char mp[100][11];
char visit[100][11];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

queue<pair<int, int>> q;
vector<pair<int, int>> v;

int removeBlock(int n, int k); // 블록들을 제거한다
void bfs(int x, int y, int n); // 제거할 블록을 찾아서 마킹
void moveBlock(int n);         // 중력 이동
void print(int n);             // 출력

int main()
{
	freopen("input.txt", "r", stdin);

	int n, k;
	scanf("%d %d\n", &n, &k);
	for (int i = 0; i < n; i++) // 문자열로 받는 방법도 배움.
		scanf("%s\n", mp[i]);

	// 시간 복잡도 1000 * 1000 = 1,000,000
	while (removeBlock(n, k)) // 작업을 했다면
	{
		moveBlock(n); // 중력으로 블록들을 떨어트린다.
	}

	print(n);
	return 0;
}

int removeBlock(int n, int k)
{
	int ret = 0;
	fill(visit[0], visit[0] + 100 * 11, false);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (mp[i][j] == '0' || visit[i][j]) continue;

			bfs(i, j, n); // (i,j)를 기준으로 인접한 애들을 찾는다.

			if ((int)v.size() < k) continue; // k개 이상이면

			for (int a = 0; a < v.size(); a++) // 해당 블록들을 터트린다.
			{
				int x = v[a].first;
				int y = v[a].second;
				mp[x][y] = '0';
				ret++;
			}
		}
	}

	return ret;
}

void bfs(int x, int y, int n)
{
	v.clear();
	char color = mp[x][y];
	visit[x][y] = true;
	q.push({ x,y });

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		v.push_back({ cx,cy });
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= 10 || visit[nx][ny]) continue;
			if (mp[nx][ny] != color) continue;
			visit[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

void moveBlock(int n)
{
	for (int i = 0; i < 10; i++)
	{
		int po = n - 1;
		for (int j = n - 1; j >= 0; j--)
		{
			if (mp[j][i] != '0')
				mp[po--][i] = mp[j][i];
		}

		for (int j = po; j >= 0; j--)
			mp[j][i] = '0';
	}
}

void print(int n)
{
	for (int i = 0; i < n; i++)
		printf("%s\n", mp[i]);
}
