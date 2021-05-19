#include <iostream>
#include <string>
#include <stack>
#include <deque>
using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;

	stack<char> st;

	for (int i = 0; i < s.size(); i++) st.push(s[i]);

	int cnt = 0;
	deque<char> dq;
	while (!st.empty())
	{
		cnt++;
		dq.push_front(st.top());
		st.pop();

		if (cnt == 3)
		{
			cnt = 0;
			dq.push_front(',');
		}
	}

	if (n % 3 == 0) dq.pop_front();

	for (char ch : dq)
	{
		cout << ch;
	}
	return 0;
}