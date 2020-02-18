#include <iostream>
using namespace std;

int main()
{
	int num, tc;
	int sum = 0;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		scanf("%1d", &num);
		sum += num;
	}

	cout << sum;
	return 0;
}