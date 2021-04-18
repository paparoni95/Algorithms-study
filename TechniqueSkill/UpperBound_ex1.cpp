#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v = { 0,1,3,4,5 };

	int K = 2;
	int answer = 0;
	// 현재 위치에서 K 이하만큼 차이나는 개수 쌍으로 카운트 하는 방법
	for (auto iter = v.begin(); iter != v.end(); iter++)
	{
		answer += ((upper_bound(iter, v.end(), *iter + K) - iter) - 1);
	}

	cout << answer << endl;
	return 0;
}