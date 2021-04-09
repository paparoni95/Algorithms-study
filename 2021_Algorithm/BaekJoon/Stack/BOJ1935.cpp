#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n;
string s;
double arr[26];
stack<double> st;
int main()
{
	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < s.length(); i++)
	{
		if (isalpha(s[i]))
			st.push(arr[s[i] - 'A']);
		else
		{
			// 뽑는 순서가 중요
			double b = st.top(); st.pop();
			double a = st.top(); st.pop();
			char op = s[i];

			if (op == '+')
				st.push(a + b);
			else if (op == '/')
				st.push(a / b);
			else if (op == '-')
				st.push(a - b);
			else if (op == '*')
				st.push(a * b);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << st.top() << '\n';
	return 0;
}