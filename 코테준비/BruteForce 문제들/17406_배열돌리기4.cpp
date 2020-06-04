#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 51;
int N, M, K, ans = 987654321;
int stage[MAX][MAX];
int copy_stage[MAX][MAX];

struct Info
{
	int r, c, s;
};
vector<int> order;
vector<Info> command;
bool check[6];


void show()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << stage[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void Initialize()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			copy_stage[i][j] = stage[i][j];
}

void Simulation(int r, int c, int s)
{
	int s1 = r - s, e1 = c - s;
	int s2 = r + s, e2 = c + s;
	int arr_length = s2 - s1 + 1;

	// 가장 바깥쪽부터 배열돌리기를 시작.
	while (arr_length >= 3)
	{
		/* 가장 윗 부분 up을 temp 배열에 저장해놓는다. */
		int x1 = s1, y1 = e1;
		vector<int> temp(arr_length - 1, 0);
		for (int i = 0; i < arr_length - 1; i++)
		{
			temp[i] = copy_stage[x1][y1++];
		}

		/* left -> down -> right -> up 순으로 배열을 돌린다. */

		int x = s1, y = e1, nx = s2 - (arr_length - 2), ny = e1;
		for (int i = 0; i < arr_length - 1; i++)
		{
			copy_stage[x][y] = copy_stage[nx][ny];
			x += 1;
			nx += 1;
		}

		x = s2, y = e1, nx = s2, ny = e2 - (arr_length - 2);
		for (int i = 0; i < arr_length - 1; i++)
		{
			copy_stage[x][y] = copy_stage[nx][ny];
			y += 1;
			ny += 1;
		}

		x = s2, y = e2, nx = s2 - 1, ny = e2;
		for (int i = 0; i < arr_length - 1; i++)
		{
			copy_stage[x][y] = copy_stage[nx][ny];
			x -= 1;
			nx -= 1;
		}

		x = s1, y = e2;
		for (int i = temp.size() - 1; i >= 0; i--)
		{
			copy_stage[x][y] = temp[i];
			y -= 1;
		}

		s1++;
		e1++;
		s2--;
		e2--;
		arr_length -= 2;
	}
}

void Calculate()
{
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		for (int j = 1; j <= M; j++) sum += copy_stage[i][j];

		ans = min(ans, sum);
	}
}

// 순열 구현 (순서가 중요하므로)
void SelectRotation(int cnt)
{
	if (cnt == K)
	{
		Initialize();

		// 순서를 정했다면, 그 순서대로 배열을 돌려보자.
		for (int i = 0; i < order.size(); i++)
		{
			int index = order[i];
			Info info = command[index];
			Simulation(info.r, info.c, info.s);
		}

		// 계산
		Calculate();
		return;
	}

	for (int i = 0; i < K; i++)
	{
		if (check[i] == true) continue;
		check[i] = true;
		order.push_back(i);
		SelectRotation(cnt + 1);
		order.pop_back();
		check[i] = false;
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> stage[i][j];
		}
	}

	command.resize(K);
	for (int i = 0; i < K; i++)
	{
		Info info;
		cin >> info.r >> info.c >> info.s;
		command[i] = info;
	}

	SelectRotation(0);

	cout << ans;
	return 0;
}