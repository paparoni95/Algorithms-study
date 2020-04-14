// https://mygumi.tistory.com/181
// 개념을 알고 풀었으나, 구현이 미숙해서 결국 검색했다...
// switch를 썼다면 더 간편했다는 것을 배운다.

// 중위 표기식 -> 후위 표기식

// 피연산자는 출력

// 연산자이면
// 스택이 비어있거나, top이 여는 괄호, 이번 연산자가 스택의 top연산자보다 우선순위 높으면 push
// 아니라면, 앞의 조건을 만족할 때까지 차례차례 pop, 그리고나서 push

// 여는 괄호라면 push

// 닫는 괄호면 여는 괄호가 나올 때까지 pop하고, 마지막에 여는 괄호도 pop

// 모든 처리가 끝난 후에 마지막으로 스택이 빌 때까지 pop
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int priority(char now)
{
	switch (now)
	{
	case '*': 
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	case '(':
	case ')':
		return 0;
	}
	return -1;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	string str;
	cin >> str;

	stack<char> s;
	for (int i = 0; i < str.length(); i++)
	{
		char ch = str[i];
		int p = priority(str[i]);

		switch (ch)
		{
	    // 연산자이면
		case '+':
		case '-':
		case '*':
		case '/':
			// 스택의 top과 현재 연산자의 우선순위를 비교하여
			// 스택의 top이 크면, 출력한다.
			while (!s.empty() && priority(s.top()) >= p)
			{
				cout << s.top();
				s.pop();
			}
			s.push(ch);
			break;
		case '(':
			s.push(ch);
			break;
		case ')':
			// 여는 괄호가 나올 때까지 찾아본다.
			while (!s.empty() && s.top() != '(')
			{
				cout << s.top();
				s.pop();
			}
			s.pop();
			break;
		default:
			// 피연산자는 출력
			cout << ch;
		}
	}

	// 모든 처리가 끝난 후에, 스택에 있는 모든 연산자들을 pop하면서 출력
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}

	return 0;
}