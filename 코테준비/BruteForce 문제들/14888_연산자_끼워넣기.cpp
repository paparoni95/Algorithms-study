#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	cin >> N;

	vector<int> num(N, 0);
	for (int i = 0; i < N; i++) cin >> num[i];

	// + - x /
	vector<int> oper(4, 0);
	for (int i = 0; i < 4; i++) cin >> oper[i];

	// +를 0, -를 1, *를 2 /를 3으로 command에 넣어준다.
	vector<int> command; int value = 0;
	for (int i = 0; i < oper.size(); i++, value++)
	{
		for (int j = 0; j < oper[i]; j++) command.push_back(value);
	}


	sort(command.begin(), command.end());
	int max_ans = -1000000000, min_ans = 1000000000;
	do
	{
		// 순열을 돌려주면서, 해당 연산자에 맞게 계산해준다.
		int total = num[0];
		for (int i = 0; i < command.size(); i++)
		{
			if (command[i] == 0) total += num[i + 1];
			else if (command[i] == 1) total -= num[i + 1];
			else if (command[i] == 2) total *= num[i + 1];
			else if (command[i] == 3) total /= num[i + 1];
		}

		max_ans = max(max_ans, total);
		min_ans = min(min_ans, total);
	} while (next_permutation(command.begin(), command.end()));

	cout << max_ans << '\n' << min_ans;
	return 0;
}