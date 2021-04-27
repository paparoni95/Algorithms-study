#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s; // less <
	// left node < parent node < right node

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	s.insert(90);

	set<int>::iterator iter; // set의 양방향 반복자 (왼쪽도 갈 수 있고, 오른쪽도 갈 수 있고)
	for (iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << ' ';
	cout << '\n';

	s.insert(50); // 중복된 원소를 삽입하지만 실패.

	auto p = s.insert(50); // pair<iter, boo> 타입
	if (p.second)
		cout << "50 삽입 성공!\n";
	else
		cout << "50 삽입 실패!\n";
	
	for (iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << ' ';
	cout << '\n';
	return 0;
}