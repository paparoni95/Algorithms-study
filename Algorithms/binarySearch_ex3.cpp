#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, x;
vector<int> v;

int main()
{
	cin >> N >> x;
	v.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		v.push_back(n);
	}

	int ret = upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x);
	cout << ret << endl;
	if (ret > 0) cout << ret;
	else cout << -1;

	return 0;
}