#include <iostream>
#include <deque>
using namespace std;

int N, K, M;
deque<int> dq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K >> M;
	for (int i = 1; i <= N; i++) dq.push_back(i);

	bool right = true;
	int cnt = 0;
	while (!dq.empty())
	{
		if (right)
		{
			for (int i = 0; i < K - 1; i++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
			cout << dq.front() << '\n';
			dq.pop_front();
		}
		else
		{
			for (int i = 0; i < K - 1; i++)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
			cout << dq.back() << '\n';
			dq.pop_back();
		}

		cnt++;
		if (cnt == M)
		{
			right = !right;
			cnt = 0;
		}
	}
	return 0;
}