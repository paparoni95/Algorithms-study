#include <iostream>
using namespace std;

int n;
char arr[11][11];

/*
별찍기 문제)

n = 3
* *
 *
* *

n = 5
*   *
 * *
  *
 * *
*   *

*/

int main()
{
	// 단, n은 홀수여야 함.
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = ' ';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j || i + j == n - 1)
			{
				arr[i][j] = '*';
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}

	return 0;
}