#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	string ret;
	stack<char> st;
	for (int i = 0; i < s.length(); i++)
	{
		if (isalpha(s[i]))
			ret += s[i];
		else
		{
			if (s[i] == '(')
				st.push(s[i]);
			// 현재 연산자보다 우선순위가 높거나 같은 연산자들은 전부 결과에 출력한다.
			else if (s[i] == '*' || s[i] == '/')
			{
				while (!st.empty() && (st.top() == '*' || st.top() == '/'))
				{
					ret += st.top();
					st.pop();
				}
				st.push(s[i]);
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				while (!st.empty() && st.top() != '(')
				{
					ret += st.top();
					st.pop();
				}
				st.push(s[i]);
			}
			else if (s[i] == ')')
			{
				while (!st.empty() && st.top() != '(')
				{
					ret += st.top();
					st.pop();
				}
				st.pop();
			}
		}
	}

	while (!st.empty())
	{
		ret += st.top();
		st.pop();
	}

	cout << ret << '\n';
	return 0;
}