#include <iostream>
#include <vector>
using namespace std;

int upperBound(const vector<int>& v, int left, int right, const int& val)
{
	int ans = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		// 찾은 원소가 val보다 작거나 같을 때
		// 같은 수 중에서 더 뒤에 있는 인덱스가 있는지 확인해본다.
		if (v[mid] <= val)
		{
			left = mid + 1;
			ans = mid;
		}
		else
			right = mid - 1;
	}

	return ans + 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v = { 1,1,2,2,3,3,4 };
	int idx = upperBound(v, 0, v.size() - 1, 2);
	cout << idx << endl;
	return 0;
}