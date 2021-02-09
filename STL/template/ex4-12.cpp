/* 클래스 템플릿 Array 

   Array<int> 클래스,
   Array<double> 클래스,
   Array<string> 클래스 생성

   템플릿은 클래스의 메타 코드일 뿐이며,
   컴파일러는 클래스 템플릿(클래스 메타 코드)를 이용해
   실제 클래스(클래스 정의 코드)를 생성한다.
*/
#include <iostream>
#include <string>
using namespace std;

template<typename T> // 클래스 템플릿 Array 정의
class Array
{
	T* buf;
	int size;
	int capacity;
public:
	explicit Array(int cap = 100) : buf(0), size(0), capacity(cap)
	{
		buf = new T[capacity];
	}

	~Array()
	{
		delete[] buf;
	}

	void Add(T data)
	{
		buf[size++] = data;
	}

	T operator[](int idx) const
	{
		return buf[idx];
	}

	int GetSize() const
	{
		return size;
	}
};

int main()
{
	Array<int> iarr; // 정수(클라이언트가 T 타입 결정) Array 객체
	iarr.Add(10);
	iarr.Add(20);
	iarr.Add(30);

	for (int i = 0; i < iarr.GetSize(); ++i)
		cout << iarr[i] << " ";
	cout << endl;

	Array<double> darr;
	darr.Add(10.12);
	darr.Add(20.12);
	darr.Add(30.12);

	for (int i = 0; i < darr.GetSize(); ++i)
		cout << darr[i] << " ";
	cout << endl;

	Array<string> sarr;
	sarr.Add("abc");
	sarr.Add("ABC");
	sarr.Add("Hello!");

	for (int i = 0; i < sarr.GetSize(); ++i)
		cout << sarr[i] << " ";
	cout << endl;

	return 0;
}