#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 태그일 때 ('<' , '>' 사이) 그냥 출력
// 태그가 아닐 때, stack에 넣고 태그를 만날 때 stack에서 꺼낸다.

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	getline(cin, s);
	s += '\n';
	stack<char> st;
	bool isTag = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '<')
		{
			while (!st.empty())
			{
				cout << st.top();
				st.pop();
			}
			cout << s[i];
			isTag = true;
		}
		else if (s[i] == '>')
		{
			cout << s[i];
			isTag = false;
		}
		else if (isTag) // 태그 중일 경우 그냥 출력
			cout << s[i];
		else if (s[i] == ' ' || s[i] == '\n')
		{
			while (!st.empty())
			{
				cout << st.top();
				st.pop();
			}
			cout << s[i];
		}
		else st.push(s[i]);
	}
	return 0;
}