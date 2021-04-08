#include <iostream>
#include <stack>
#include <string>
using namespace std;

// stack이 비어있으면 (,[ push
// ),] 는 false
// stack이 비어있지 않다면 (,[ push
// 짝이 맞는다면 pop
// 아니라면 false
// 끝난 후에 stack이 비어있지 않다면 false

int main()
{
	string s;
	while (getline(cin, s))
	{
		if (s.length() == 1 && s.front() == '.')
		{
			break;
		}

		stack<char> st;
		bool ok = true;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']')
			{
				if (st.empty())
				{
					if (s[i] == '(' || s[i] == '[')
						st.push(s[i]);
					else
					{
						ok = false;
						break;
					}
				}
				else
				{
					if (s[i] == '(' || s[i] == '[')
						st.push(s[i]);
					else if (s[i] == ')' && st.top() == '(')
						st.pop();
					else if (s[i] == ']' && st.top() == '[')
						st.pop();
					else
					{
						ok = false;
						break;
					}
				}
			}
		}

		if (!st.empty()) ok = false;
		if (ok) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}