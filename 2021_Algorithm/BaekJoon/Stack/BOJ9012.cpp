#include <iostream>
#include <stack>
#include <string>
using namespace std;

// vps 판별법
// stack이 비어있고 ) 가 들어오면 false
// stack이 비어있고 ( 가 들어오면 push
// stack이 비어있지 않다면,
// top이 (이고, )이면 pop (이면 push
// 끝난 후, 스택이 비어있지 않다면 false

// 다른 방법
// 여는 괄호라면 push
// 닫는 괄호라면
// 스택이 비어있지 않으면, 짝이 맞으면 pop 다르다면 false
// 스택이 비어있다면 false

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		string s;
		cin >> s;

		stack<char> st;
		bool ok = true;
		for (int i = 0; i < s.length(); i++)
		{
			if (st.empty())
			{
				if (s[i] == ')')
				{
					ok = false;
					break;
				}
				st.push(s[i]);
			}
			else
			{
				if (st.top() == '(' && s[i] == ')')
					st.pop();
				else if (st.top() == '(' && s[i] == '(')
					st.push(s[i]);
				else
				{
					ok = false;
					break;
				}
			}
		}

		if (!st.empty()) ok = false;
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}