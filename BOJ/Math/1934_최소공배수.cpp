#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

int lcm(int a, int b, int g)
{
	return g * (a / g) * (b / g);
}

int main()
{
	int a, b, g, tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		cin >> a >> b;
		g = gcd(a, b);
		cout << lcm(a, b, g) << '\n';
	}

	return 0;
}