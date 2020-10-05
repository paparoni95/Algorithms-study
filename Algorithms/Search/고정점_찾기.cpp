#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int binarySearch(int start, int end) {
	if (start > end) return -1;
	int mid = (start + end) / 2;
	// 고정점을 찾은 경우 중간점 인덱스 반환
	if (v[mid] == mid) return mid;
	// 중간점의 값보다 중간점이 작은 경우 왼쪽 확인
	else if (v[mid] > mid) return binarySearch(start, mid - 1);
	// 중간점의 값보다 중간점이 큰 경우 오른쪽 확인
	else return binarySearch(mid + 1, end);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	int index = binarySearch(0, n - 1);
	cout << index << '\n';
	return 0;
}