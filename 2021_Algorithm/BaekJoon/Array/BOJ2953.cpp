#include <iostream>
#include <algorithm>
using namespace std;

int arr[5][4];

int main()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4; j++)
			cin >> arr[i][j];

	pair<int, int> ret = { 0,0 };
	for (int i = 0; i < 5; i++)
	{
		int point = 0;
		for (int j = 0; j < 4; j++)
		{
			point += arr[i][j];
		}

		if (ret.second < point)
		{
			ret.first = i;
			ret.second = point;
		}
	}

	cout << ret.first + 1 << ' ' << ret.second << endl;
	return 0;
}