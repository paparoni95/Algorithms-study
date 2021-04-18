#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, K;
string student[300001];
queue<int> q[21];
int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> student[i];

	long long ret = 0;
	for (int i = 1; i <= N; i++)
	{
		int len = student[i].length();
		while (!q[len].empty() && i - q[len].front() > K)
			q[len].pop();
		ret += q[len].size();
		q[len].push(i);
	}

	cout << ret << '\n';
	return 0;
}