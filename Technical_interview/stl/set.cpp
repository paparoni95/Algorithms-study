#include <iostream>
#include <set>
using namespace std;

// set
// 균형잡힌 이진트리
// 원소 삽입, 삭제, 탐색의 연산은 O(logN)을 보장한다.

int main()
{
	// int 자료형을 저장하는 균형잡힌 이진트리 생성
	set<int> s;
	// 원소 삽입
	s.insert(5);
	// 6의 값을 가지는 원소를 찾았으면 해당 원소의 주소 값을 리턴
	// 아니면 s.end() 리턴
	if (s.find(6) != s.end())
		cout << "존재한다." << '\n';
	else
		cout << "존재하지 않는다." << '\n';

	// 저장된 원소의 수를 리턴
	cout << s.size() << '\n';
	// 모든 원소 삭제
	s.clear();
	// 해당 주소의 원소 삭제
	// 2번째 원소 삭제
	s.erase(++s.begin());
	return 0;
}