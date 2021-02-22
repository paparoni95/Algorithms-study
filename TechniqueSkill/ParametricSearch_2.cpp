#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x;
vector<int> v;

int countByRange(vector<int>& v, int leftValue, int rightValue)
{
	vector<int>::iterator rightIdx = upper_bound(v.begin(), v.end(), rightValue);
	vector<int>::iterator leftIdx = lower_bound(v.begin(), v.end(), leftValue);
	return rightIdx - leftIdx;
}

int main()
{
	// 데이터의 개수 n, 찾고자 하는 값 x
	cin >> n >> x;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	// 값이 [x, x] 범위에 있는 데이터의 개수 계산
	int answer = countByRange(v, x, x);

	if (answer == 0) cout << -1;
	else cout << answer;
	return 0;
}