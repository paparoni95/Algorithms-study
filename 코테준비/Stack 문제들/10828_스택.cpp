#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	int N;
	cin >> N;

	stack<int> s;
	while (N--)
	{
		string command;
		int num;

		cin >> command;
		if (command[0] == 'e')
			cout << s.empty() << endl;
		else if (command[0] == 's')
			cout << s.size() << endl;
		else if (command[0] == 't')
		{
			if (s.size() == 0)
				cout << -1 << endl;
			else
				cout << s.top() << endl;
		}
		else if (command[0] == 'p')
		{
			if (command[1] == 'o')
			{
				if (s.size() == 0)
					cout << -1 << endl;
				else
				{
					num = s.top();
					s.pop();
					cout << num << endl;
				}
			}
			else
			{
				cin >> num;
				s.push(num);
			}
		}
	}
	return 0;
}