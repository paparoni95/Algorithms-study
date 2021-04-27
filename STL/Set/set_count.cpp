#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	s.insert(90);

	for (auto iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << ' ';
	cout << '\n';

	cout << "s.count(50) : " << s.count(50) << '\n';
	cout << "s.count(100) : " << s.count(100) << '\n';
	return 0;
}

10 30 40 50 70 80 90
s.count(50) : 1
s.count(100) : 0