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

	cout << "ms.count(30) : " << ms.count(30) << '\n';
	cout << "ms.count(100) : " << ms.count(100) << '\n';

	auto iter = ms.find(30);
	if (iter != ms.end())
		cout << "30 exist\n";
	else
		cout << "30 not exist\n";

	iter = ms.find(100);
	if (iter != ms.end())
		cout << "100 exist\n";
	else
		cout << "100 not exist\n";

	multiset<int>::iterator lower_iter;
	multiset<int>::iterator upper_iter;

	lower_iter = ms.lower_bound(30);
	upper_iter = ms.upper_bound(30);
	cout << "lower_iter : " << *lower_iter << '\n';
	cout << "upper_iter : " << *upper_iter << '\n';

	cout << "[lower_iter, upper_iter) -> ";
	for (iter = lower_iter; iter != upper_iter; iter++)
		cout << *iter << ' ';
	cout << '\n';
	return 0;
}

10 30 30 50 70 80 80
ms.count(30) : 2
ms.count(100) : 0
30 exist
100 not exist
lower_iter : 30
upper_iter : 50
[lower_iter, upper_iter) -> 30 30