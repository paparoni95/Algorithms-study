// https://11001.tistory.com/23

// 내가 푼 코드보다 더 빠른 시간을 보여준다.
// 아무래도 시간 차이가 나는 경우는 5 경계선의 내부를 어떻게 채우냐에 따라 다른 것 같다.
// 추가적으로 수식을 조금 정리해서 필요없는 부분들을 돌리지 않는 것도

// 재귀함수로 채우는 것보다, for문이 훨씬 더 빠르게 동작한다고 한다.
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int FIVE = 4;

int N, board[21][21], people[5], ans;
bool visited[21][21];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0 ,-1 ,0 };

void select_five_area(int x, int y, int d1, int d2)
{
	int i, j;
	memset(people, 0, sizeof(people));
	memset(visited, 0, sizeof(visited));

	// 2. 5번 선거구 경계선
	for (i = 0; i <= d1; ++i)
	{
		visited[x + i][y - i] = true;
		visited[x + d2 + i][y + d2 - i] = true;
		people[FIVE] += board[x + i][y - i] + board[x + d2 + i][y + d2 - i];
	}
	for (i = 1; i < d2; ++i)
	{
		visited[x + i][y + i] = true;
		visited[x + d1 + i][y - d1 + i] = true;
		people[FIVE] += board[x + i][y + i] + board[x + d1 + i][y - d1 + i];
	}

	// 3. 5번 선거구 내부 탐색
	for (i = 0; i < d1; ++i)
	{
		j = 0;
		while (!visited[x + i + j + 1][y - i])
		{
			visited[x + i + j + 1][y - i] = true;
			people[FIVE] += board[x + i + j + 1][y - i];
			++j;
		}
	}
	for (i = 1; i < d2; ++i)
	{
		j = 0;
		while (!visited[x + i + j + 1][y + i])
		{
			visited[x + i + j + 1][y + i] = true;
			people[FIVE] += board[x + i + j + 1][y + i];
			++j;
		}
	}
	// 4. 1 ~ 4 선거구 선택
	for (i = 1; i <= N; ++i)
	{
		for (j = 1; j <= N; ++j)
		{
			if (visited[i][j] == true) continue;
			if (i < x + d1 && j <= y)                people[0] += board[i][j];
			else if (i <= x + d2 && y < j)           people[1] += board[i][j];
			else if (x + d1 <= i && j < y - d1 + d2) people[2] += board[i][j];
			else if (x + d2 < i && y - d1 + d2 <= j) people[3] += board[i][j];
		}
	}

	// 5. 가장 작은 최대 인구, 최소 인구의 차이로 갱신
	pair<int*, int*> p = minmax_element(people, people + 5);
	ans = min(ans, int(*p.second - *p.first));
}

void divide_area()
{
	int x, y, d1, d2;

	// 1. 가능한 위치에서 d1, d2를 늘여가며 시도
	for (x = 1; x <= N - 2; ++x)
	{
		for (y = 2; y <= N - 1; ++y)
		{
			d1 = 1, d2 = 1;

			while (true)
			{
				if (x + d1 + d2 <= N && 1 <= y - d1 && y + d2 <= N)
					select_five_area(x, y, d1, d2++);
				else
				{
					++d1, d2 = 1;
					if (!(x + d1 + d2 <= N && 1 <= y - d1 && y + d2 <= N))
						break;
				}
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	register int i, j;
	for (i = 1; i <= N; ++i)
		for (j = 1; j <= N; ++j)
			cin >> board[i][j];

	ans = 987654321;
	divide_area();
	cout << ans;
	return 0;
}
