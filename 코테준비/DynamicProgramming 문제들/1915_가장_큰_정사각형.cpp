// https://yabmoons.tistory.com/158

// 처음에 완전탐색으로 풀었는데 시간초과가 뜸!!
// 이유는 1000 * 1000 * 1000을 하니 10억 => 이는 1 ~ 2초로 풀 수 없다는 결론.
// 다이나믹 프로그래밍으로 풀어야 되는 문제.
#include <iostream>
#include <string>

#define MAX 1010
using namespace std;

int N, M;
int stage[MAX][MAX];

// 굳이 헤더파일<algorithm>에 있는 min을 쓰지 않아도 이렇게 구현이 가능하다.
int Min(int a, int b) { if (a < b) return a; return b; }

void Solution()
{
	int max_len = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (stage[i][j] != 0)
			{
				stage[i][j] = Min(stage[i - 1][j - 1], Min(stage[i - 1][j], stage[i][j - 1])) + 1;
				if (max_len < stage[i][j]) max_len = stage[i][j];
			}
		}
	}

	cout << max_len * max_len << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		// 이렇게 문자열로 입력을 받는 경우도 있다.
		string input; cin >> input;
		for (int j = 0; j < input.size(); j++)
		{
			stage[i][j + 1] = input[j] - '0'; // char의 문자에 - '0' = integer !!
		}
	}

	Solution();
	return 0;
}