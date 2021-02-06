#include <iostream>
using namespace std;

/* 스마트 포인터 예시 + (-> 연산자 오버로딩)

   동적으로 생성한 Point 객체를 소멸자에서 자동으로 삭제하므로
   프로그램 중에 예외가 발생하거나 delete 호출을 빼먹어 발생하는
   동적 메모리 누수 현상을 방지할 수 있다. */

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
	PointPtr(Point* p): ptr(p){}
	~PointPtr()
	{
		delete ptr;
	}
	
	Point* operator->()const
	{
		return ptr;
	}
};

int main()
{
	PointPtr p1 = new Point(2, 3); // 메모리 할당
	PointPtr p2 = new Point(5, 5);

	p1->Print(); // p1.operator->()->Print() 호출
	p2->Print();

	// p1 소멸자에서 Point 동적 개체를 자동으로 메모리에서 제거한다.
	// p2 마찬가지.
	return 0;
}