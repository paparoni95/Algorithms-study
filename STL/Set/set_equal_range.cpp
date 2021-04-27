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

	// equal_range 는 lower_bound() 와 upper_bound() 쌍으로 반환
	auto iter = s.equal_range(30);
	cout << *iter.first << '\n';
	cout << *iter.second << '\n';

	iter = s.equal_range(55);
	if (iter.first != iter.second)
		cout << "55 exist\n";
	else
		cout << "55 not exist\n";

	return 0;
}

10 30 40 50 70 80 90
30
40
55 not exist