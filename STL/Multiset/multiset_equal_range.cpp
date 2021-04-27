#include <iostream>
#include <set>
using namespace std;

int main()
{
	multiset<int> ms;
	ms.insert(50);
	ms.insert(30);
	ms.insert(80);
	ms.insert(80);
	ms.insert(30);
	ms.insert(70);
	ms.insert(10);

	for (auto iter = ms.begin(); iter != ms.end(); iter++)
		cout << *iter << ' ';
	cout << '\n';

	auto iter = ms.equal_range(30);
	for (auto p = iter.first; p != iter.second; p++)
		cout << *p << ' ';
	cout << '\n';
	return 0;
}