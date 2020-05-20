// https://yabmoons.tistory.com/161

// 2시간 풀다가 결국 몰라서, 봤다....
// vector<int> map[MAX][MAX]로 하면 쉽게 풀리는.. 나중에 다시 풀자.
// 추가적으로 같은 칸에 여러 개의 나무를 심을 수도 있으니, 이점 유의하자.
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 11
using namespace std;

int N, M, K;
int energe[MAX][MAX];        // 현재 양분
int insert_energe[MAX][MAX]; // 겨울에 추가 되는 양분

vector<int> a[MAX][MAX];

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1,  0,  1 ,-1,1,-1, 0, 1 };

void SpringAndSummer()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (a[i][j].size() == 0) continue;

			int die_tree_energe = 0;
			vector<int> temp;

			// 어린 나무부터 양분을 먹어야 하므로 오름차순으로 정렬해놓고,
			sort(a[i][j].begin(), a[i][j].end());
			for (int k = 0; k < a[i][j].size(); k++)
			{
				int age = a[i][j][k];

				if (energe[i][j] >= age)
				{
					energe[i][j] -= age;
					temp.push_back(age + 1);
				}
				else
				{
					// 양분이 부족하다는 의미는 결국 죽는다는 의미
					// 나중에 죽은 나무 나이 / 2 만큼을 보충
					die_tree_energe += (age / 2);
				}
			}

			a[i][j].clear();
			for (int k = 0; k < temp.size(); k++)
			{
				a[i][j].push_back(temp[k]);
			}
			energe[i][j] += die_tree_energe;
		}
	}
}

void Fall()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (a[i][j].size() == 0) continue;

			for (int k = 0; k < a[i][j].size(); k++)
			{
				int age = a[i][j][k];

				// 번식하려는 나무의 나이는 5의 배수여야 하며,
				if (age % 5 == 0)
				{
					// 인접한 8칸에 나이가 1인 나무를 생성한다.
					for (int dir = 0; dir < 8; dir++)
					{
						int nx = i + dx[dir];
						int ny = j + dy[dir];
						if (nx >= 1 && ny >= 1 && nx <= N && ny <= N)
						{
							// 한 칸에 여러 개의 나무를 심어도 되니까 가능하다.
							a[nx][ny].push_back(1);
						}
					}
				}
			}
		}
	}
}

// 양분 리필해주기.
void Winter()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			energe[i][j] += insert_energe[i][j];
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> insert_energe[i][j];
			energe[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int x, y, year;
		cin >> x >> y >> year;
		a[x][y].push_back(year);
	}

	for (int i = 0; i < K; i++)
	{
		SpringAndSummer();
		Fall();
		Winter();
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			ans += a[i][j].size();
		}
	}

	cout << ans;
	return 0;
}