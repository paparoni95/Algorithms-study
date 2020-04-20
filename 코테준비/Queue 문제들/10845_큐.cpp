#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;

	queue<int> q;
	while (n--)
	{
		string str;
		int num;
		cin >> str;
		if (str[0] == 'p')
		{
			if (str[1] == 'u')
			{
				cin >> num;
				q.push(num);
			}
			else
			{
				if (q.empty())
					cout << -1 << '\n';
				else
				{
					num = q.front();
					q.pop();
					cout << num << '\n';
				}
			}
		}
		else if (str[0] == 's')
		{
			cout << q.size() << '\n';
		}
		else if (str[0] == 'e')
		{
			cout << q.empty() << '\n';
		}
		else if (str[0] == 'f')
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}

	return 0;
}