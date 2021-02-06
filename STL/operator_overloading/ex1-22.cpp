#include <iostream>
using namespace std;

/* (* 연산자 오버로딩) */

class Point
{
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	void Print() const { cout << x << ',' << y << endl; }
};

class PointPtr
{
	Point* ptr;
public:
	PointPtr(Point* p) : ptr(p) {}
	~PointPtr()
	{
		delete ptr;
	}

	Point* operator->()const
	{
		return ptr;
	}

	Point& operator*()const
	{
		return *ptr;
	}
};

int main()
{
	Point* p1 = new Point(2, 3);   // 일반 포인터
	PointPtr p2 = new Point(5, 5); // 스마트 포인터

	p1->Print(); // p1->Print()
	p2->Print(); // p2.operator->()->Print()
	cout << endl;

	/* p1은 일반 포인터이고, *p1은 객체 자체이므로 멤버 함수를 호출한다. 
	   p2는 스마트 포인터로, *p2가 객체를 반환하게 p2.operator*()를 호출하고
	   객체 참조를 반환받아 멤버 함수를 호출한다. */
	(*p1).Print();
	(*p2).Print(); // p2.operator*().Print()

	delete p1;
	// p2의 소멸자에서 Point 동적 객체를 자동으로 메모리에서 제거한다
	return 0;
}