#include <bits/stdc++.h>
using namespace std;

stack<int> s;

int main() {
	// 스택의 삽입 O(1)
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	// 스택의 최상단 원소 확인 O(1)
	cout << "top: " << s.top() << '\n';
	// 스택이 비어있으면 1, 아니면 0, O(1)
	cout << "stack.empty(): " << s.empty() << '\n';
	// 스택에 들어있는 원소의 개수 O(1)
	cout << "stack.size(): " << s.size() << '\n';
	
	// 스택의 삭제 O(1)
	s.pop();

	// 스택의 최상단 원소부터 출력
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}