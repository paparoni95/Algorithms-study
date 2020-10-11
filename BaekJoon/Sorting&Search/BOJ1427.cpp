#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	while (n) {
		v.push_back(n % 10);
		n /= 10;
	}

	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < v.size(); ++i)
		cout << v[i];
	return 0;
}