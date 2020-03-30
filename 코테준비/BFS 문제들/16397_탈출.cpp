#include <iostream>
#include <queue>
#define MAX_SIZE 200000
#define LIMIT 99999
using namespace std;

int cnt[MAX_SIZE];
bool check[MAX_SIZE];
int N, T, G;

int operation(int type, int n)
{
	// A버튼
	if (type == 1)
		return n + 1;
	// B버튼
	else
	{
		n *= 2;

		if (n == 0 || n > LIMIT)
			return n;
		if (n <= 9)
			return n - 1;

		int origin = n;
		int cnt = 0;
		while (n >= 10)
		{
			cnt++;
			n /= 10;
		}

		// 가장 높은 자릿수의 숫자가 1 줄어들게 한다.
		n = 1;

		while (cnt--)
			n *= 10;

		origin -= n;

		if (origin > LIMIT)
			return N;
		else
			return origin;
	}
}

int bfs()
{
	queue<int> q;
	q.push(N);
	cnt[N] = 0;
	check[N] = true;
	while (!q.empty())
	{
		int here = q.front();
		q.pop();

		// 탈출 성공
		if (here == G)
		{
			if (cnt[here] <= T)
				return cnt[here];
			else
				return -1;
		}

		// 버튼을 누른다. (A or B)
		for (int i = 1; i <= 2; i++)
		{
			int next = operation(i, here);
			if (next >= 0 && next <= LIMIT)
			{
				if (check[next] == false)
				{
					check[next] = true;
					cnt[next] = cnt[here] + 1;
					q.push(next);
				}
			}
		}
	}

	return -1; // 탈출에 실패
}

int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &N, &T, &G);

	int ret = bfs();

	if (ret == -1)
		printf("ANG\n");
	else
		printf("%d\n", ret);

	return 0;
}