#include <iostream>
using namespace std;

int d[1001];
int n;

int main()
{
	cin >> n;

	// ╧ьюш╬В
	d[1] = 1;
	d[2] = 2;
	d[3] = 3;
	for (int i = 4; i <= n; i++)
	{
		d[i] = (d[i - 2] + d[i - 1]) % 10007;
	}

	cout << d[n];
	return 0;
}