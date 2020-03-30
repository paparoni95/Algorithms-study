// 출처 : https://jaimemin.tistory.com/979
// B 버튼을 연산하는 과정이 더 간편하고, 메모리 효율성을 잘한 것 같다.
#include <iostream>
#include <queue>
#define MAX_SIZE 100000
using namespace std;

int N, T, G;
bool visited[MAX_SIZE];

int bfs()
{
	queue<pair<int, int>> q; // (숫자, 시도횟수)
	q.push({ N, 0 });
	visited[N] = true;
	while (!q.empty())
	{
		int here = q.front().first;
		int cost = q.front().second;
		q.pop();

		// 최대 시도횟수를 초과하면 탈출 불가
		if (cost > T) break;

		// 목표치인 G에 도달하면 출력
		if (here == G) return cost;

		// 두 가지 버튼을 사용하자.
		// A 버튼
		int A = here + 1;
		if (A < MAX_SIZE && !visited[A])
		{
			visited[A] = true;
			q.push({ A, cost + 1 });
		}

		// B 버튼
		int next = here * 2;
		if (next >= MAX_SIZE) continue;
		int B = next;
		int digit = 1; // 최대 자릿수
		while (next)
		{
			next /= 10;
			digit *= 10;
		}
		digit /= 10;
		B -= digit;
		if (B < MAX_SIZE && !visited[B])
		{
			visited[B] == true;
			q.push({ B, cost + 1 });
		}
	}

	return -1; // 탈출에 실패한 경우
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> T >> G;

	int ret = bfs();
	if (ret == -1)
		cout << "ANG\n";
	else
		cout << ret << '\n';

	return 0;
}