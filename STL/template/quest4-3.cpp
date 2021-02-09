#include <iostream>
using namespace std;

template<typename T>
class Queue
{
	enum {CAP = 100};
	T buf[CAP];
	int front;
	int rear;
public:
	Queue():front(0),rear(0){}
	void Push(const T& data)
	{
		buf[rear = (rear + 1) % CAP] = data;
	}
	const T& Pop()
	{
		return buf[front = (front + 1) % CAP];
	}
	bool Empty() const
	{
		return rear == front;
	}
};

int main()
{
	Queue<int> q;

	q.Push(10);
	q.Push(20);
	q.Push(30);

	if (!q.Empty())
		cout << q.Pop() << endl;
	if (!q.Empty())
		cout << q.Pop() << endl;
	if (!q.Empty())
		cout << q.Pop() << endl;

	return 0;
}