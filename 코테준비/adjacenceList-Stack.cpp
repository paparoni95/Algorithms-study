// https://blog.naver.com/kks227/220781557098
#include <iostream>
#include <cstdlib>
using namespace std;

// 연결리스트로 스택을 구현해보자.
// 기본적으로는 C++ STL 라이브러리에 stack을 지원한다.
// 스택을 구현할 때는 배열 or 연결리스트이지만,
// 가끔은 top이 아닌 다른 내용이 필요할 때도 있다고 하니, 그 때는 배열로 구현하면 좋다.
// 배열 대신에 STL에서 지원하는 vector를 사용하는 것도 좋은 방법이다.

class UnderflowException{};

template<typename T>
class ListNode
{
public:
	T value;
	ListNode<T>* next;

	ListNode<T>() : next(nullptr) {}
	ListNode<T>(T value1, ListNode<T>* next1) : value(value1), next(next1) {}
};

template<typename T>
class Stack
{
public:
	// 멤버 변수
	int size;
	ListNode<T>* tail;

	// 생성자와 소멸자
	Stack<T>() : size(0), tail(nullptr){}
	~Stack<T>()
	{
		ListNode<T>* t1 = tail, * t2;
		while (t1 != nullptr)
		{
			t2 = t1->next;
			delete t1;
			t1 = t2;
		}
	}

	// 멤버 함수

	// 맨 위에 새 원소를 삽입
	void push(T value)
	{
		tail = new ListNode<T>(value, tail);
		size++;
	}

	// 맨 위의 원소 반환
	T top()
	{
		
		try // 예외 처리 : 스택이 비어 있음
		{
			if (size == 0) throw UnderflowException();

			return tail->value;
		}
		catch (UnderflowException e)
		{
			cerr << "스택이 비어 있는데 top 연산을 시도했습니다." << endl;
			exit(1);
		}
	}

	// 맨 위의 원소 제거
	void pop()
	{
		try // 예외 처리 : 스택이 비어 있음
		{
			if (size == 0) throw UnderflowException();

			ListNode<T>* temp = tail->next;
			delete tail;
			tail = temp;
			size--;
		}
		catch (UnderflowException e)
		{
			cerr << "스택이 비어 있는데 pop 연산을 시도했습니다." << endl;
			exit(2);
		}
	}
};

template<typename T>
ostream& operator<<(ostream& out, const Stack<T>& LL)
{
	// 원소들을 한 줄에 차례대로 출력
	ListNode<T>* temp = LL.tail;
	out << "top [";
	for (int i = 0; i < LL.size; i++)
	{
		out << temp->value;
		temp = temp->next;
		if (i < LL.size - 1)
			out << ", ";
	}
	out << "] bottom";
	return out;
}

int main()
{
	Stack<int> S;
	S.push(0); cout << S << endl;
	S.push(1); cout << S << endl;
	S.push(2); cout << S << endl;
	S.push(3); cout << S << endl;
	S.pop(); cout << S << endl;
	S.push(4); cout << S << endl;
	S.pop(); cout << S << endl;
	S.pop(); cout << S << endl;
	S.push(5); cout << S << endl;
	S.pop(); cout << S << endl;
	S.pop(); cout << S << endl;
	S.pop(); cout << S << endl;
	return 0;
}