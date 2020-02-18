#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		if (i <= n)
		{
			for (int j = 1; j <= i; j++)
				cout << '*';
			for (int j = 2 * n - 2 * i; j > 0; j--)
				cout << ' ';
			for (int j = 1; j <= i; j++)
				cout << '*';
		}
		else
		{
			for (int j = 2 * n - i; j > 0; j--)
				cout << '*';
			for (int j = 0; j < i - n; j++)
				cout << ' ';
			for (int j = 0; j < i - n; j++)
				cout << ' ';
			for (int j = 2 * n - i; j > 0; j--)
				cout << '*';
		}
		cout << '\n';
	}
	return 0;
}