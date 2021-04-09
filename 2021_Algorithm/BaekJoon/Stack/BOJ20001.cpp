#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);

	stack<string> st;
	while (getline(cin, s))
	{
		if (s == "문제")
			st.push(s);
		else if(s == "고무오리")
		{
			if (st.empty())
			{
				st.push("문제");
				st.push("문제");
			}
			else
				st.pop();
		}
	}

	if (st.empty())
		cout << "고무오리야 사랑해\n";
	else
		cout << "힝구\n";

	return 0;
}