#include <iostream>
using namespace std;

/* Point 클래스의 일반 포인터 사용

일반 포인터를 사용하면 new 연산 후 delete 연산을 호출하지 않으면 메모리 누수가 발생한다.
또한, 사용 중에 함수가 종료하거나 예외 등이 발생하면 동적으로 할당한 메모리를 해제하지 못하는
문제가 발생한다. 

스마트 포인터를 사용하면 이를 쉽게 해결할 수 있다.*/

class Point
{
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x),y(_y) {}
	void Print() const { cout << x << ',' << y << endl; }
};

int main()
{
	Point* p1 = new Point(2, 3); // 메모리 할당
	Point* p2 = new Point(5, 5); // 메모리 할당

	p1->Print(); // p1의 멤버 함수 호출(서비스 사용)
	p2->Print();

	delete p1; // 메모리 제거
	delete p2;

	return 0;
}