#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;

	deque<int> dq;
	while (n--)
	{
		string str;
		int x;

		cin >> str;
		if (str == "push_front")
		{
			cin >> x;
			dq.push_front(x);
		}
		else if (str == "push_back")
		{
			cin >> x;
			dq.push_back(x);
		}
		else if (str == "pop_front")
		{
			if (dq.empty()) printf("-1\n");
			else
			{
				x = dq.front();
				dq.pop_front();
				printf("%d\n", x);
			}
		}
		else if (str == "pop_back")
		{
			if (dq.empty()) printf("-1\n");
			else
			{
				x = dq.back();
				dq.pop_back();
				printf("%d\n", x);
			}
		}
		else if (str == "size")
		{
			printf("%d\n", dq.size());
		}
		else if (str == "empty")
		{
			printf("%d\n", dq.empty());
		}
		else if (str == "front")
		{
			if (dq.empty()) printf("-1\n");
			else printf("%d\n", dq.front());
		}
		else
		{
			if (dq.empty()) printf("-1\n");
			else printf("%d\n", dq.back());
		}
	}

	return 0;
}