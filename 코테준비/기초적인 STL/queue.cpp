#include <iostream>
#include <queue>
using namespace std;

// queue
// 먼저 들어간 요소가 먼저 나온다. (FIFO)
// 삽입과 삭제하는 연산이 상수시간안에 가능하다.
// stack과 마찬가지로 i번째 접근이 불가능
// 보통 push는 데이터를 뒤로 넣고,
// pop은 데이터를 앞에서 뽑는다.

// 큐에는 보통
// 앞을 표시하는 front와 뒤를 표시하는 rear로 구분한다.

// 큐의 활용도
// 1. BFS 너비우선탐색
// 2. 은행의 번호표대로 일을 처리한다.
// 3. 프린터
// 4. 캐시

int main()
{
	// int형을 저장하는 큐 생성
	queue<int> q;
	// 원소 4 삽입
	q.push(4);
	q.push(5);
	// 맨 위 원소 팝
	q.pop();
	// 맨 위 원소 값 출력
	cout << q.front() << '\n';
	// 큐가 비어 있다면 1 아니면 0
	cout << q.empty() << '\n';
	// 큐에 저장되어 있는 원소의 수 출력
	cout << q.size() << '\n';
	return 0;
}