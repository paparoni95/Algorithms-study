#include <iostream>
using namespace std;

int arr[31];

int main()
{
	for (int i = 1; i <= 28; ++i)
	{
		int x;
		cin >> x;
		++arr[x];
	}

	int cnt = 0;
	for (int i = 1; i <= 30; ++i)
	{
		if (arr[i] == 0)
		{
			--cnt;
			cout << i << '\n';
			if (cnt == 2) 
				break;
		}
	}

	return 0;
}