// https://machine-geon.tistory.com/140 
// 나중에 다시 풀어보기.
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int h, w, answer;
vector<int> v;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		int x; cin >> x;
		v.push_back(x);
	}

	for (int i = 1; i < w - 1; i++) {
		int left = 0;
		int right = 0;

		// 왼쪽에서 가장 높은 건물의 높이
		for (int j = 0; j < i; j++) left = max(left, v[j]);
		// 오른쪽에서 가장 높은 건물의 높이
		for (int j = i + 1; j < w; j++) right = max(right, v[j]);
		// 더 낮은 건물을 기준으로 현재 인덱스에 모이는 빗물
		if (v[i] < left && v[i] < right) answer += min(left, right) - v[i];
	}

	cout << answer << '\n';
	return 0;
}