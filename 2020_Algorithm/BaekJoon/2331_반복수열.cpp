#include <iostream>
#include <vector>
using namespace std;

const int MAX = 295246; // 1 ~ 295245

int A, P;
vector<int> D;
int visited[MAX];

int Calculate(int n)
{
	int result = 0, digit, sum = 1;
	while (n)
	{
		sum = 1;

		digit = n % 10;

		for (int i = 0; i < P; i++)
			sum *= digit;

		n /= 10;

		result += sum;
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> P;

	D.push_back(0);

	// D[1]
	D.push_back(A);
	visited[A] = 1;

	// D[2] ~ (각 자리 숫자의 최대가 나오는 값은 295245까지)
	int index = 2, next_num = 1;
	while (index <= MAX)
	{
		// D[n] = D[n - 1]의 각 자리의 숫자를 p번 곱한 수
		next_num = Calculate(D[index - 1]);
		D.push_back(next_num);

		if (visited[next_num] == 0)
		{
			visited[next_num]++;
		}
		else
		{
			visited[next_num]++;
		}
		index++;
	}

	int cnt = 0;
	for (int i = 1; i < MAX; i++)
	{
		if (visited[D[i]] == 1)
		{
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}