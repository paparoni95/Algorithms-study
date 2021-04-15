#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	int n;
	queue<int> q;
	cin >> n;
	while (n--)
	{
		int x;
		string s;
		cin >> s;

		if (s == "push")
		{
			cin >> x;
			q.push(x);
		}
		else if (s == "pop")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (s == "size")
		{
			cout << q.size() << '\n';
		}
		else if (s == "empty")
		{
			cout << q.empty() << '\n';
		}
		else if (s == "front")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (s == "back")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}
	return 0;
}