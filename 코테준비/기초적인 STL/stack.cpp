#include <iostream>
#include <stack>
using namespace std;

// stack
// 먼저 들어간 요소가 마지막에 나온다. (LIFO)
// 삽입하거나 삭제하는 연산은 상수 시간에 가능
// 다만 스택에 i번째에 항목에 바로 접근이 불가능하다.

// 스택의 활용도
// 1. 재귀
// 2. 웹 브라우저 방문기록 뒤로가기
// 3. 실행 취소(undo)
// 4. 역순 문자열 만들기
// 5. 수식의 괄호 검사(VPS, Valid Parenthesis String)
// 6. 후위 표기법 계산

int main()
{
	// int형을 저장하는 스택 생성
	stack<int> st;
	// 원소 4를 삽입
	st.push(4);
	// 맨 위 원소 팝
	st.pop();
	// 맨 위 원소 값 출력
	cout << st.top() << '\n';
	// 스택이 비어있다면 1, 아니면 0
	cout << st.empty() << '\n';
	// 스택에 저장되어 있는 원소의 수 출력
	cout << st.size() << '\n';
	return 0;
}