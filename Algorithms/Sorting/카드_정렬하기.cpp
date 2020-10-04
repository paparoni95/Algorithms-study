#include <bits/stdc++.h>
using namespace std;

int n, result;
priority_queue<int> pq;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(-x);
	}

	while (pq.size() != 1) {
		// 가장 작은 2개의 카드 묶음 꺼내기
		int one = -pq.top();
		pq.pop();
		int two = -pq.top();
		pq.pop();
		// 카드 묶음을 합쳐서 다시 삽입
		int summary = one + two;
		result += summary;
		pq.push(-summary);
	}

	cout << result << '\n';
	return 0;
}