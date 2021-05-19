// 출처 : https://yabmoons.tistory.com/152
// 약간 벽을 느낀 문제..
// 기존의 BFS틀만 만들줄 알면 풀리는 문제가 아닌 문제이다.
// 새로운 방법을 배우고, 나중에 다시 풀어보자.
#include <iostream>
#include <queue>
#include <string>
#include <set>

#define MAX_SIZE 1000000 + 1
using namespace std;

string input;
int N, M, K;

// string -> integer
int invert(string s)
{
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		sum = sum + (s[i] - '0');
		if (i != s.length() - 1)
			sum = sum * 10;
	}
	return sum;
}

void bfs()
{
	queue<string> q;
	q.push(input);
	int cur_k = 0;
	int max = 0;

	while (q.empty() == 0 && cur_k < K)
	{
		int q_size = q.size();
		set<string> visited;

		for (int i = 0; i < q_size; i++)
		{
			string cur = q.front();
			q.pop();

			// 1 <= i < j <= M
			// 0 <= i < j <= M-1
			// i와 j를 고른다.
			for (int j = 0; j < M - 1; j++)
			{
				for (int k = j + 1; k < M; k++)
				{
					// 문제의 조건 (바꾼 수가 0으로 시작하면 안된다.)
					if (j == 0 && cur[k] == '0') continue;

					swap(cur[j], cur[k]);
					// 이전에 찾은적이 있는지 확인
					if (visited.find(cur) == visited.end())
					{
						// 연산 횟수가 k-1이면서, 가장 큰 값을 저장
						if (cur_k == K - 1 && max < invert(cur))
							max = invert(cur);

						q.push(cur);
						visited.insert(cur);
					}
					swap(cur[j], cur[k]);
				}
			}
		}
		cur_k++;
	}

	if (cur_k != K)
		cout << -1 << '\n';
	else
		cout << max << '\n';
}

// 핵심은 k번 바꾼 후에 나온 값들 중 최댓값을 찾는 것이 목표다.
int main()
{
	cin >> input >> K;
	M = input.length();

	if (M == 1 || (M == 2 && invert(input) % 10 == 0))
		cout << -1 << '\n';
	else
		bfs();
	
	return 0;
}