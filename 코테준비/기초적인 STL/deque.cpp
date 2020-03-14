#include <iostream>
#include <deque>
using namespace std;

// deque
// 동적배열이다.
// 벡터와 마찬가지로 임의의 위치에 원소 접근과
// 앞과 뒤에서 원소를 추가하는 연산은 O(1)을 보장한다.

int main()
{
	// int형 저장하는 동적배열 생성
	deque<int> dq;
	// 배열의 맨 앞에 원소 5 추가
	dq.push_front(5);
	// 배열 맨 뒤에 원소 5 추가
	dq.push_back(5);
	// 배열 맨 앞의 원소 삭제
	dq.pop_front();
	// 배열 맨 뒤의 원소 삭제
	dq.pop_back();

	// 크기
	cout << dq.size() << '\n';
	// 비어있으면 1 아니면 0
	cout << dq.empty() << '\n';
	return 0;
}