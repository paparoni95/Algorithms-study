#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int n;
stack<int> st;
queue<int> q;
vector<char> ret;
// stack에 push하는 순서는 반드시 오름차순
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		q.push(x);
	}

	int num = 1;
	bool ok = true;
	while (!q.empty())
	{
		int now = q.front();

		if (!st.empty() && st.top() > now)
		{
			ok = false;
			break;
		}
		if (st.empty())
		{
			st.push(num++);
			ret.push_back('+');
		}
		else
		{
			if (st.top() == now)
			{
				st.pop();
				ret.push_back('-');
				q.pop();
			}
			else
			{
				st.push(num++);
				ret.push_back('+');
			}
		}
	}

	if (ok)
	{
		for (int i = 0; i < ret.size(); i++)
			cout << ret[i] << '\n';
	}
	else
		cout << "NO\n";

	return 0;
}