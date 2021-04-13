#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s;
int vis[50];

int getLength(int start, int end)
{
	int cnt = 0;
	for (int i = start; i < end; i++)
	{
		if (s[i] == '(')
		{
			int prefix = s[i - 1] - '0';
			cnt += prefix * getLength(i + 1, vis[i]) - 1;
			i = vis[i];
		}
		else
			cnt++;
	}
	return cnt;
}

int main()
{
	cin >> s;
	stack<int> st;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			st.push(i);
		else if (!st.empty() && s[i] == ')')
		{
			vis[st.top()] = i;
			st.pop();
		}
	}

	cout << getLength(0, s.length()) << '\n';
	return 0;
}