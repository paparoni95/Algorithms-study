#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };
const int MAX = 25;

int N;
int stage[MAX][MAX];

int FindHouse(int x, int y)
{
	int house_cnt = 1;

	stage[x][y] = 0;
	for (int d = 0; d < 4; d++)
	{
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx >= 0 && ny >= 0 && nx < N && ny < N)
		{
			if (stage[nx][ny])
			{
				house_cnt += FindHouse(nx, ny);
			}
		}
	}

	return house_cnt;
}

void Solution()
{
	int cnt = 0;
	vector<int> vec;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (stage[i][j])
			{
				cnt = FindHouse(i, j);
				vec.push_back(cnt);
			}
		}
	}

	sort(vec.begin(), vec.end());

	cout << vec.size() << '\n';
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << '\n';
	}

	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &stage[i][j]);
		}
	}

	Solution();
	return 0;
}