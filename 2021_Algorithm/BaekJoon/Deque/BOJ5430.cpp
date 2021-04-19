#include <iostream>
#include <deque>
#include <string>
using namespace std;

int tc, n;
string p, input;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> tc;
	while (tc--)
	{
		deque<int> dq;

		cin >> p >> n >> input;

		if (input.length() > 2) // []
		{
			string make;
			for (int i = 1; i < input.length() - 1; i++)
			{
				if (input[i] == ',')
				{
					dq.push_back(stoi(make));
					make = "";
				}
				else if (isdigit(input[i]))
				{
					make += input[i];
				}
			}
			dq.push_back(stoi(make));
		}

		bool left = true;
		bool ok = true;
		for (int i = 0; i < p.length(); i++)
		{
			if (p[i] == 'R')
				left = !left;
			else
			{
				if (dq.empty())
				{
					ok = false;
					break;
				}

				if (left)
					dq.pop_front();
				else
					dq.pop_back();
			}
		}

		if (!ok)
			cout << "error\n";
		else if (dq.empty())
			cout << "[]\n";
		else
		{
			cout << "[";
			if (left)
			{
				if (!dq.empty())
				{
					cout << dq.front();
					dq.pop_front();
				}

				while (!dq.empty())
				{
					cout << ",";
					cout << dq.front();
					dq.pop_front();
				}
			}
			else
			{
				if (!dq.empty())
				{
					cout << dq.back();
					dq.pop_back();
				}

				while (!dq.empty())
				{
					cout << ",";
					cout << dq.back();
					dq.pop_back();
				}
			}
			cout << "]\n";
		}
	}
	return 0;
}