#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string s;
	int n = 0;
	int cnt = 0;
	while (getline(cin, s))
	{
		if (s[0] == '-')
			break;

		n++;
		cnt = 0;
		stack<char> st;
		for (int i = 0; i < s.length(); i++)
		{
			if (!st.empty() && st.top() == '{' && s[i] == '}')
				st.pop();
			else
				st.push(s[i]);
		}

		while (!st.empty())
		{
			char c1 = st.top(); st.pop();
			char c2 = st.top(); st.pop();

			if (c1 == c2)
				cnt++;
			else
				cnt += 2;
		}

		cout << n << ". " << cnt << '\n';
	}
	return 0;
}