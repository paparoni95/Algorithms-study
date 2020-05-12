// https://yabmoons.tistory.com/200

// 괄호를 추가하지 않고 계산하는 방법
// 괄호를 씌우는 방법의 구현이 어려웠다.. 나중에 다시 풀어보자.
#include <iostream>
#include <string>
#include <algorithm>

#define MAX 20
using namespace std;

int N, op_num;
int ans = -2147483640;
int num[MAX], op[MAX];

int calculate(int n1, int n2, char c)
{
	if (c == '+') return n1 + n2;
	else if (c == '-') return n1 - n2;
	else if (c == '*') return n1 * n2;
}

// idx : 연산 인덱스
// result : 현재까지의 결과값
void dfs(int idx, int result)
{
	if (idx >= op_num)
	{
		ans = max(ans, result);
		return;
	}

	// 현재 연산자를 기준으로 괄호를 추가하는 경우
	int cur_result = calculate(result, num[idx + 1], op[idx]);
	dfs(idx + 1, cur_result);

	// 현재 연산자에 괄호를 추가하지 않고, 다음 연산자로 괄호를 추가하는 경우
	if (idx + 1 < op_num)
	{
		// 현재 연산기호를 기준으로, 한 칸 더 넘어간 연산기호가 존재한다면,
		// 한 칸 넘어간 연산기호부터 먼저 계산 후에, 그 결과값과 현재의 결과값을 현재 연산기호에 따른 계산 후.
		// 재귀 호출.
		int after_result = calculate(num[idx + 1], num[idx + 2], op[idx + 1]);
		int cur_result = calculate(result, after_result, op[idx]);
		dfs(idx + 2, cur_result);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N;
	int idx = 0;
	int idx2 = 0;

	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (i % 2 == 0) num[idx++] = str[i] - '0';
		else op[idx2++] = str[i];
	}

	op_num = N / 2;

	if (N == 1)
	{
		cout << num[0];
		return 0;
	}
	else if (N == 3)
	{
		cout << calculate(num[0], num[1], op[0]);
		return 0;
	
	}

	dfs(0, num[0]);
	cout << ans;
	return 0;
}