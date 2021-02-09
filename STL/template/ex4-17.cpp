/* 함수 템플릿 For_each() */
#include <iostream>
#include <string>
using namespace std;

template<typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func pf) // 함수 템플릿
{
	while (begin != end)
	{
		pf(*begin++);
	}
}

template<typename T>
void Print(T data) // 함수 템플릿
{
	cout << data << " ";
}

int main()
{
	int arr[5] = { 10,20,30,40,50 };
	For_each(arr, arr + 5, Print<int>); // Print<int>는 명시적으로 해줘야 한다. 유추할 수 없으므로
	cout << endl;

	string sarr[3] = { "abc","ABCDE","Hello!" };
	For_each(sarr, sarr + 3, Print<string>);
	cout << endl;

	// 명시적으로 호출
	For_each<int*, void(*)(int)>(arr, arr + 5, Print<int>);
	cout << endl;

	For_each<string*, void(*)(string)>(sarr, sarr + 3, Print<string>);
	cout << endl;

	return 0;
}