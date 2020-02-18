#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		// full
		if (i == n)
		{
			for (int j = 1; j <= 2 * n - 1; j++)
				cout << '*';
			break;
		}
		// black
		for (int j = 0; j < n - i; j++)
			cout << ' ';

		// first line
		if (i == 1)
		{
			cout << '*';
			cout << '\n';
		}
		// star - jump - star
		else
		{
			cout << '*';
			for (int j = 0; j < (2 * (i - 1)) - 1; j++)
				cout << ' ';
			cout << '*';
			cout << '\n';
		}
	}
	return 0;
}