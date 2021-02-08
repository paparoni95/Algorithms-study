#include <iostream>
#include <algorithm>
using namespace std;

// 콜백 함수 예제를 함수 객체를 사용하여 변경

struct Functor1
{
	void operator()(int n)
	{
		cout << n << " ";
	}
};

struct Functor2
{
	void operator()(int n)
	{
		cout << n * n << " ";
	}
};

struct Functor3
{
	void operator()(int n)
	{
		cout << "정수 : " << n << endl;
	}
};

int main()
{
	int arr[5] = { 10,20,30,40,50 };

	for_each(arr, arr + 5, Functor1()); // 임시 함수 객체(Functor1())를 만들어 함수로 전달
	cout << endl << endl;

	for_each(arr, arr + 5, Functor2()); // 함수가 아닌 함수 객체를 전달했다는 것이 포인트
	cout << endl << endl;

	for_each(arr, arr + 5, Functor3());
	cout << endl << endl;

	return 0;
}