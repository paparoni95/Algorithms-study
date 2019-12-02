#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a(9);
int sum;

void solution()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if ((sum - a[i] - a[j]) == 100)
			{
				a[i] = a[j] = 0;
				return;
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	solution();
	
	sort(a.begin(), a.end());
	for (int i = 2; i < 9; i++)
		cout << a[i] << '\n';
	return 0;
}