#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int N, M;
deque<int> dq;
queue<int> q;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) dq.push_back(i);
	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		q.push(x);
	}

	int cnt = 0;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();


		int s = 0, e = 1;
		for (int i = 0; i < dq.size(); i++)
		{
			if (dq[i] == now)
				break;
			else
				s++;
		}

		for (int i = dq.size() - 1; i >= 0; i--)
		{
			if (dq[i] == now)
				break;
			else
				e++;
		}

		if (s <= e)
		{
			cnt += s;
			while (s--)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else
		{
			cnt += e;
			while (e--)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}

		dq.pop_front();
	}
	cout << cnt << '\n';
	return 0;
}