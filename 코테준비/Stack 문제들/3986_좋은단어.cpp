#include <iostream>
#include <stack>
#include <string>
using namespace std;

int N, ans;

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;
	for (int tc = 0; tc < N; tc++)
	{
		string str;
		cin >> str;

		stack<char> st;
		for (int i = 0; i < str.length(); i++)
		{
			char ch = str[i];

			if (st.empty()) st.push(ch);
			else if (st.top() == ch) st.pop();
			else st.push(ch);
		}
		
		if (st.empty()) ans++;
	}

	cout << ans;
	return 0;
}