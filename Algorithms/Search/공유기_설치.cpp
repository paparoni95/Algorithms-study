#include <bits/stdc++.h>
using namespace std;

/*
	특정 기준으로 가능한 위치에 공유기를 설치한다.
	설치를 끝난 후 다음과 같이 판단한다.
	공유기가 더 설치되려면, 간격을 줄인다.
	공유기가 덜 설치되려면, 간격을 늘린다.
*/

int n, c;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	v.reserve(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int left = 1;
	int right = v[n - 1] - v[0];
	int distance = 0;
	int answer = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		int start = v[0];
		int cnt = 1; // 공유기의 설치 수

		// 간격을 distance 기준으로 공유기 설치한다.
		for (int i = 1; i < n; i++) {
			distance = v[i] - start;
			if (mid <= distance) {
				cnt++;
				start = v[i];
			}
		}
		
		// 공유기의 수를 줄이자 => 간격 넓히기
		if (cnt >= c) {
			answer = mid;
			left = mid + 1;
		}
		// 공유기의 수를 늘리자 => 간격 좁히기
		else {
			right = mid - 1;
		}
	}

	cout << answer << '\n';
	return 0;
}