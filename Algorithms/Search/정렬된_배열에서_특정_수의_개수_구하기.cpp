#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> v;

// 값이 [left_value, right_value]인 데이터의 개수를 반환하는 함수
int countByRange(vector<int>& v, int leftValue, int rightValue) {
	vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
	vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
	return rightIndex - leftIndex;
}

int main() {
	cin >> n >> x;
	v.reserve(n);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	// 값이 [x, x] 범위에 있는 데이터의 개수 계산
	int cnt = countByRange(v, x, x);

	// 값이 x인 원소가 존재하지 않는다면
	if (cnt == 0) cout << -1 << '\n';
	else cout << cnt << '\n';
	return 0;
}