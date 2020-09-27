#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main() {
	// 큐의 삽입 O(1)
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	// 큐의 삭제 O(1)
	q.pop();

	// 큐의 크기 O(1)
	cout << "q.size(): " << q.size() << '\n';
	// 큐의 앞, 뒤 확인 O(1)
	cout << "q.front(): " << q.front() << '\n';
	cout << "q.back(): " << q.back() << '\n';

	// 먼저 들어온 원소부터 추출
	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop();
	}
	return 0;
}