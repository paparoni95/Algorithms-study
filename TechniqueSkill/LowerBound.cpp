#include <iostream>
#include <vector>
using namespace std;

int lowerBound(const vector<int>& v, int left, int right, const int& val)
{
	int ans = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (v[mid] >= val)
		{
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v = { 1,1,2,2,3,3,4 };
	int idx = lowerBound(v, 0, v.size() - 1, 2);
	cout << idx << endl;
	return 0;
}