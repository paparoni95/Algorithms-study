#include <iostream>
using namespace std;

int n;
int d[22];

int main()
{
	cin >> n;
	d[0] = 0;
	d[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + d[i - 2];
	}

	cout << d[n];
	return 0;
}