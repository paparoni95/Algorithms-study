#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	// # 작은 따옴표와 큰 따옴표 차이
	char buffer;
	(cin >> buffer).get(); // 이렇게 해도 개행을 지워줄 수 있다.
	//if (buffer == "a") cout << "에러 코드" << endl;
	if (buffer == 'a') cout << "맞는 코드" << endl;

	// # cin.get()
	// 앞에서 cin을 통해 값을 받은 뒤 남은 입력값 즉, 개행 문자는 입력 버퍼에 남게 되므로
	// 다음에 cin을 호출했을 경우 값을 입력하지 않아도 입력버퍼에 남아있던 값을 가져오게 된다.
	// 표준 입력 버퍼에서 문자를 하나만 가져옴
	// 공백, 개행 포함
	// 문자만 입력 받음
	cin.get();

	// # 문장 전체를 입력 받을 때
	string str;
	getline(cin, str);

	// # 제한시간에 걸릴 때
	// 1. 현재 알고리즘의 복잡도를 확인한다.
	// 2. 문제가 없다면 입출력 함수를 바꾸자
	// 3. 반복적으로 endl을 쓴다면 개행문자('\n')로 바꾸자

	// # C++ stack의 유의점
	// pop이 어떠한 것도 반환하지 않는다.
	// 또한 top은 비어있을 때 접근하면 에러가 난다.

	// # C++ 배열 초기화
	int arr[5] = { 0, }; // 모두 0으로 초기화
	int arr2[5][5];
	fill(arr2[0], arr2[0] + 5 * 5, 7);
}