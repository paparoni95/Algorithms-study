#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;
	pair<set<int>::iterator, bool> pr;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	pr = s.insert(90);

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << ' ';
	cout << '\n';

	s.insert(pr.first, 85); // 해당 위치에 빠르게 원소를 넣을 수 있다.
	for (iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << ' ';
	cout << '\n';
	return 0;
}

10 30 40 50 70 80 90
10 30 40 50 70 80 85 90