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

	int target = 30;
	auto iter = s.find(target);
	if (iter != s.end())
		cout << target << " exist\n";
	else
		cout << target << " not exist\n";

	target = 100;
	iter = s.find(target);
	if (iter != s.end())
		cout << target << " exist\n";
	else
		cout << target << " not exist\n";
	return 0;
}

10 30 40 50 70 80 90
30 exist
100 not exist