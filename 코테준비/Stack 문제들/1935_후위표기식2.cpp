#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

// 후위 표기식을 계산하는 법

int N;
string str;
stack<double> st;
vector<double> v;

void calc(double a, double b, char op)
{
	switch (op)
	{
	case '+':
		st.push(a + b);
		break;
	case '-':
		st.push(a - b);
		break;
	case '*':
		st.push(a * b);
		break;
	case '/':
		st.push(a / b);
		break;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> str;
	v.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < str.length(); i++)
	{
		char ch = str[i];
		double a = 0, b = 0;

		switch (ch)
		{
		case '+':
		case '-':
		case '*':
		case '/':
			b = st.top(); st.pop();
			a = st.top(); st.pop();
			calc(a, b, ch);
			break;
		default:
			st.push(v[ch - 'A']);
		}
	}
	
	printf("%.2f", st.top());
	return 0;
}