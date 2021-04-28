#include <iostream>
#include <map>
using namespace std;

int main()
{
	multimap<int, int> mm;

	mm.insert(pair<int, int>(5, 100));
	mm.insert(pair<int, int>(3, 100));
	mm.insert(pair<int, int>(8, 30));
	mm.insert(pair<int, int>(3, 40));
	mm.insert(pair<int, int>(1, 70));
	mm.insert(pair<int, int>(7, 100));
	mm.insert(pair<int, int>(8, 50));

	for (auto iter = mm.begin(); iter != mm.end(); iter++)
		cout << "(" << iter->first << "," << iter->second << ") ";
	cout << '\n';

	multimap<int, int>::iterator lower_iter = mm.lower_bound(3);
	multimap<int, int>::iterator upper_iter = mm.upper_bound(3);

	cout << "[lower_iter, upper_iter): ";
	for (auto iter = lower_iter; iter != upper_iter; iter++)
		cout << "(" << iter->first << "," << iter->second << ") ";
	cout << '\n';

	auto equal_iter = mm.equal_range(3);
	cout << "[equal_iter.first, equal_iter.second): ";
	for (auto iter = equal_iter.first; iter != equal_iter.second; iter++)
		cout << "(" << iter->first << "," << iter->second << ") ";
	cout << '\n';
	return 0;
}

(1, 70) (3, 100) (3, 40) (5, 100) (7, 100) (8, 30) (8, 50)
[lower_iter, upper_iter): (3, 100) (3, 40)
[equal_iter.first, equal_iter.second): (3, 100) (3, 40)