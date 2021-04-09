#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		q.push(x);
	}

	int target = 1;
	stack<int> st;
	while (!q.empty())
	{
		int now = q.front();

		if (now == target)
		{
			target++;
			q.pop();
		}
		else
		{
			if (!st.empty() && st.top() == target)
			{
				target++;
				st.pop();
			}
			else
			{
				st.push(now);
				q.pop();
			}
		}
	}

	bool ok = true;
	while (!st.empty())
	{
		int now = st.top();
		st.pop();
		if (target == now)
			target++;
		else
		{
			ok = false;
			break;
		}
	}

	if (ok)
		cout << "Nice\n";
	else
		cout << "Sad\n";
	return 0;
}