#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 8MB까지만 허용
// int는 4바이트를 차지
// 1MB = 1,000,000 BYTE
// 8MB = 8,000,000 BYTE = 2,000,000 * 4 BYTE
// 그래서 메모리 초과 발생,
// 카운팅 소트 이용
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int n;
	const int MAX = 10001;
	cin >> n;
	vector<int> v(MAX, 0);
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		++v[num];
	}
	// 1 ~ 10000
	// 1/2 2/2 3/2 4/1 5/2 7/1
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == 0) continue;
		for (int j = 0; j < v[i]; ++j) {
			cout << i << '\n';
		}
	}
	return 0;
}