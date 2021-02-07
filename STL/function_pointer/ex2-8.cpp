#include <iostream>
using namespace std;

/* 함수 포인터를 이용한 콜백 메커니즘 구현 */

// 배열의 모든 원소에 반복적인 작업을 수행하게 추상화됨.(구체적인 작업은 없음)
// 서버는 여러 클라이언트에 의해 호출되며 클라이언트의 존재를 알 수 없다.
// 따라서 클라이언트가 서버를 호출할 때 서버에 클라이언트의 정보를 제공해야 한다.
// 여기서는 함수 포인터 매개변수를 이용해 콜백 함수의 주소를 전달하는 방법을 보여준다.
void For_each(int* begin, int* end, void(*pf)(int))
{
	while (begin != end)
	{
		pf(*begin++); // 클라이언트 함수 호출(콜백)
	}
}

// 클라이언트
void Print1(int n)
{
	cout << n << ' ';
}

void Print2(int n)
{
	cout << n * n << ' ';
}

void Print3(int n)
{
	cout << "정수: " << n << endl;
}

int main()
{
	int arr[5] = { 10,20,30,40,50 };

	For_each(arr, arr + 5, Print1); // Print1() 콜백 함수의 주소를 전달
	cout << endl << endl;

	For_each(arr, arr + 5, Print2);
	cout << endl << endl;

	For_each(arr, arr + 5, Print3);
	cout << endl << endl;

	return 0;
}