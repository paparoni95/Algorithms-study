// https://blog.naver.com/kks227/220781851401
#include <iostream>
#include <cstdlib>
using namespace std;

class UnderflowException {};

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
class Queue
{
public:
	int size;
	ListNode<T>* head, * tail;

	Queue<T>() : size(0), head(nullptr), tail(nullptr) {}
	~Queue<T>()
	{
		ListNode<T>* t1 = head, * t2;
		while (t1 != nullptr)
		{
			t2 = t1->next;
			delete t1;
			t1 = t2;
		}
	}

	void push(T value)
	{
		if (size == 0)
			head = tail = new ListNode<T>(value, nullptr);
		else
		{
			tail->next = new ListNode<T>(value, nullptr);
			tail = tail->next;
		}
		size++;
	}

	T front()
	{
		try
		{
			if (size == 0) throw UnderflowException();

			return head->value;
		}
		catch (UnderflowException e)
		{
			cerr << "큐가 비어 있는데 front 연산을 시도했다." << endl;
			exit(1);
		}
	}

	void pop()
	{
		try
		{
			if (size == 0) throw UnderflowException();

			ListNode<T>* temp = head;
			head = head->next;
			delete temp;
			if (head == nullptr) tail = nullptr;
			size--;
		}
		catch (UnderflowException e)
		{
			cerr << "큐가 비어 있는데 pop 연산을 시도했다. " << endl;
			exit(2);
		}
	}
};

template<typename T>
ostream& operator <<(ostream& out, const Queue<T>& LL)
{
	ListNode<T>* temp = LL.head;
	out << "front [";
	for (int i = 0; i < LL.size; i++)
	{
		out << temp->value;
		temp = temp->next;
		if (i < LL.size - 1) out << ", ";
	}
	out << "] rear";
	return out;
}

int main()
{
	Queue<int> Q;
	Q.push(0); cout << Q << endl;
	Q.push(1); cout << Q << endl;
	Q.push(2); cout << Q << endl;
	Q.push(3); cout << Q << endl;
	Q.pop(); cout << Q << endl;
	Q.push(4); cout << Q << endl;
	Q.pop(); cout << Q << endl;
	Q.pop(); cout << Q << endl;
	Q.push(5); cout << Q << endl;
	Q.pop(); cout << Q << endl;
	Q.pop(); cout << Q << endl;
	Q.pop(); cout << Q << endl;
	return 0;
}