/* 배열 출력 함수 템플릿 

   함수 템플릿의 매개변수로 타입뿐만 아니라 정수 등도 가능하다.
   단, PrintArray<int, 5>(arr1) 처럼 명시적으로 호출해야 한다.
   함수 인자가 arr1이라는 정보만 제공하므로 5는 추론할 수 없기 때문
*/
#include <iostream>
using namespace std;

template<typename T, int size>
void PrintArray(T* arr)
{
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i << "]: " << arr[i] << endl;
	}
	cout << endl;
}

int main()
{
	int arr1[5] = { 10,20,30,40,50 };
	PrintArray<int, 5>(arr1); // 명시적 호출

	double arr2[3] = { 1.1,2.2,3.3 };
	PrintArray<double, 3>(arr2);

	return 0;
}