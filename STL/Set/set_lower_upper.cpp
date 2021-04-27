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

	set<int>::iterator iter_lower = s.lower_bound(30);
	set<int>::iterator iter_upper = s.upper_bound(30);
	cout << *iter_lower << '\n';
	cout << *iter_upper << '\n';

	iter_lower = s.lower_bound(55);
	iter_upper = s.upper_bound(55);
	// lower_bound() == upper_bound() 이면
	// 찾는 원소가 존재하지 않는다는 것을 의미함.
	if (iter_lower != iter_upper)
		cout << "55 exist\n";
	else
		cout << "55 not exist\n";

	return 0;
}

10 30 40 50 70 80 90
30
40
55 not exist