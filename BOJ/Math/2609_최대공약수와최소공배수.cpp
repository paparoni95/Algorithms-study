#include <iostream>
using namespace std;

// O(logN), 재귀
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
	int a, b, g;
	cin >> a >> b;
	g = gcd(a, b);
	cout << g << '\n';    // 최대공약수 (Greatest Common Divisor)
	cout << lcm(a, b, g); // 최소공배수 (Least Common Multiple)
	return 0;
}