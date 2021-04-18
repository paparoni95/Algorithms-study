#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<pair<int, int>> v(9);
	for (int i = 1; i <= 9; i++)
	{
		int x;
		cin >> x;
		v.push_back({ x, i });
	}

	pair<int, int> ret = *max_element(v.begin(), v.end());
	cout << ret.first << endl << ret.second << endl;
	return 0;
}