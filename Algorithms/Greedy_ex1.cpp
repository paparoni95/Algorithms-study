#include <iostream>
using namespace std;

int n = 1260;
int cnt;
int coinTypes[] = { 500,100,50,10 };

int main()
{
	for (int i = 0; i < 4; i++)
	{
		int coin = coinTypes[i];
		cnt += n / coin;
		n %= coin;
	}

	cout << cnt << '\n';
	return 0;
}