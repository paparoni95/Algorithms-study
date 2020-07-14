#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
	{
		stack<char> s;
		string str;
		bool ok = true; // 합격 테스트

		cin >> str;

		for (int i = 0; i < str.length(); i++)
		{
			// 여는 괄호는 push
			if (str[i] == '(')
			{
				s.push(str[i]);
			}
			// 닫는 괄호라면?
			else
			{
				// 스택에 비어있지 않으면
				if (!s.empty())
				{
					// 짝이 맞으면 pop
					if (s.top() == '(')
					{
						s.pop();
					}
					// 짝이 맞지 않다면 틀린 답
					else
					{
						ok = false;
						break;
					}
				}
				// 애초에 처음부터 ')'이 들어온다면 마찬가지로 틀린 답
				else
				{
					ok = false;
					break;
				}
			}
		}

		// 짝을 다 맞췄는데, 그래도 스택이 비어있지 않다면?
		if (!s.empty())
			ok = false;

		if (ok)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}