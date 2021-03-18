#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 모험가 길드
int n;
vector<int> v;

int main()
{
	cin >> n;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int result = 0; // 그룹의 수
	int cnt = 0;    // 현재 그룹에 포함된 모험가의 수

	for (int i = 0; i < n; i++) // 공포도가 낮은 것부터 하나씩 확인하며
	{
		cnt++; // 현재 그룹에 해당 모험가를 포함
		if (cnt >= v[i]) // 현재 그룹에 포함된 모험가의 수가 현재 공포도 이상이라면, 그룹 결성
		{
			result++;
			cnt = 0; // 현재 그룹에 포함된 모험가의 수 초기화
		}
	}

	cout << result << '\n';
	return 0;
}
