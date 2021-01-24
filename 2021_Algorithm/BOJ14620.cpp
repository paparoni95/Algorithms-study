#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 모두 꽃이 피게하면서 가장 싼 가격에 화단을 대여하고 싶다
// 꽃 하나당 5평의 땅을 대여 200 * 15 = 3000
int N, answer = 3000;
int grass[11][11];
bool visited[11][11];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

vector<pair<int, int>> pos;

void init()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visited[i][j] = false;
}

int calculate(const vector<pair<int, int>>& v)
{
	init();
	int cnt = 0, total = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int x = v[i].first;
		int y = v[i].second;

		visited[x][y] = true;
		for (int j = 0; j < 4; j++)
		{
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N)
			{
				visited[nx][ny] = true;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j])
			{
				cnt++;
				total += grass[i][j];
			}
		}
	}

	if (cnt != 15) return -1;
	else return total;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> grass[i][j];
			pos.push_back({ i,j });
		}

	// 세 개의 꽃의 씨앗 위치를 구한다
	for (int i = 0; i < pos.size(); i++)
	{
		for (int j = i + 1; j < pos.size(); j++)
		{
			for (int k = j + 1; k < pos.size(); k++)
			{
				vector<pair<int, int>> select;
				select.push_back(pos[i]);
				select.push_back(pos[j]);
				select.push_back(pos[k]);

				int ret = calculate(select);
				if (ret != -1)
				{
					answer = min(answer, ret);
				}
					
			}
		}
	}

	cout << answer;
	return 0;
}