#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	queue<int> q;
	cin >> n;
	while (n--)
	{
		int x;
		string s;
		cin >> s;

		if (s[0] == 'p' && s[1] == 'u')
		{
			cin >> x;
			q.push(x);
		}
		else if (s[0] == 'p' && s[1] == 'o')
		{
			if (q.empty())
				cout << -1 << '\n';
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (s.front() == 's')
		{
			cout << q.size() << '\n';
		}
		else if (s.front() == 'e')
		{
			cout << q.empty() << '\n';
		}
		else if (s.front() == 'f')
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (s.front() == 'b')
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}
	return 0;
}