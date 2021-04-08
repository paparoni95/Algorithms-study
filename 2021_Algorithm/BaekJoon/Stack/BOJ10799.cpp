#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string s;
	cin >> s;

	stack<char> st;
	int cnt = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			st.push(s[i]);
		else
		{
			if (s[i - 1] == '(')
			{
				st.pop();
				cnt += st.size();
			}
			else
			{
				st.pop();
				cnt++;
			}
		}
	}

	cout << cnt << '\n';
	return 0;
}