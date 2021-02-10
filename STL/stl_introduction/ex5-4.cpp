// deque 컨테이너 역시 배열 기반 컨테이너
#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);
	dq.push_back(50);

	deque<int>::iterator iter = dq.begin(); // 시작 원소를 가리키는 반복자
	cout << iter[0] << endl; // [] 연산자
	cout << iter[1] << endl;
	cout << iter[2] << endl;
	cout << iter[3] << endl;
	cout << iter[4] << endl << endl;

	iter += 2; // += 연산
	cout << *iter << endl << endl;

	deque<int>::iterator iter2 = iter + 2; // + 연산
	cout << *iter2 << endl;
	return 0;
}