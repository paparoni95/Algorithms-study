#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	stack<int> st;
	string s;
	int x;
	while (n--)
	{
		cin >> s;
		if (s == "push")
		{
			cin >> x;
			st.push(x);
		}
		else if (s == "top")
		{
			if (!st.empty())
				cout << st.top() << '\n';
			else
				cout << -1 << '\n';
		}
		else if (s == "size")
		{
			cout << st.size() << '\n';
		}
		else if (s == "empty")
		{
			cout << st.empty() << '\n';
		}
		else if (s == "pop")
		{
			if (!st.empty())
			{
				cout << st.top() << '\n';
				st.pop();
			}
			else
				cout << -1 << '\n';
		}
	}
	return 0;
}