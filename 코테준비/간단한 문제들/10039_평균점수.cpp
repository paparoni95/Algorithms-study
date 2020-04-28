#include <iostream>
#include <vector>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	vector<int> v(5);
	for (int i = 0; i < 5; i++)
	{
		int n;
		cin >> n;
		if (n < 40) n = 40;
		v[i] = n;
	}

	int total = 0;
	for (int i = 0; i < 5; i++) total += v[i];
	cout << total / 5;
	return 0;
}