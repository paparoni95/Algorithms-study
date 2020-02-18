#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v[i] = num;
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
		cout << v[i] << '\n';
	
	return 0;
}