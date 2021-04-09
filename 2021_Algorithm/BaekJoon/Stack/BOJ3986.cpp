#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int cnt = 0;
	while (n--)
	{
		string s;
		cin >> s;

		stack<char> st;
		for (int i = 0; i < s.length(); i++)
		{
			if (!st.empty() && st.top() == s[i])
				st.pop();
			else
				st.push(s[i]);
		}

		if (st.empty())
			cnt++;
	}
	cout << cnt << '\n';
	return 0;
}