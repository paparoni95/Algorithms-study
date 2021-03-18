#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int n, m, k;
vector<int> v;

int main()
{
	cin >> n >> m >> k;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	int first = v[n - 1];  // 가장 큰 수
	int second = v[n - 2]; // 두 번째로 큰 수

	// 가장 큰 수가 더해지는 횟수 계산
	int cnt = (m / (k + 1)) * k;
	cnt += m % (k + 1);

	int result = 0;
	result += cnt * first; // 가장 큰 수 더하기
	result += (m - cnt) * second; // 두 번째로 큰 수 더하기
	cout << result << '\n';
	return 0;
}