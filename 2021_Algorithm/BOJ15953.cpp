// implementation
#include <iostream>
using namespace std;

int festival1[6] = { 500,300,200,50,30,10 };
int festival2[5] = { 512,256,128,64,32 };

int func(int a, int b)
{
	int total = 0;

	if (a == 1) total += festival1[0];
	else if (a > 1 && a <= 3) total += festival1[1];
	else if (a > 3 && a <= 6) total += festival1[2];
	else if (a > 6 && a <= 10) total += festival1[3];
	else if (a > 10 && a <= 15) total += festival1[4];
	else if (a > 15 && a <= 21) total += festival1[5];

	if (b == 1) total += festival2[0];
	else if (b > 1 && b <= 3) total += festival2[1];
	else if (b > 3 && b <= 7) total += festival2[2];
	else if (b > 7 && b <= 15) total += festival2[3];
	else if (b > 15 && b <= 31) total += festival2[4];

	return total * 10000;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T, a, b;
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		cout << func(a, b) << '\n';
	}
	return 0;
}