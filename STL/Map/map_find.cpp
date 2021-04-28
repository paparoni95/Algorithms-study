#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, int> m;

	m[5] = 100;
	m[3] = 100;
	m[8] = 30;
	m[4] = 40;
	m[1] = 70;
	m[7] = 100;
	m[9] = 50;

	for (auto iter = m.begin(); iter != m.end(); iter++)
		cout << "(" << iter->first << ',' << iter->second << ") ";
	cout << '\n';

	// key를 기준으로 찾는다.
	auto iter = m.find(5);
	if (iter != m.end())
		cout << "key 5에 매핑된 value: " << iter->second << '\n';
	else
		cout << "key 5가 없습니다.\n";

	map<int, int>::iterator lower_iter = m.lower_bound(5);
	map<int, int>::iterator upper_iter = m.upper_bound(5);

	cout << "[lower_iter, upper_iter): ";
	for (auto iter = lower_iter; iter != upper_iter; iter++)
		cout << "(" << iter->first << "," << iter->second << ") ";
	cout << '\n';

	auto iter2 = m.equal_range(5);
	cout << "[iter2.first, iter.second): ";
	for (auto iter = iter2.first; iter != iter2.second; iter++)
		cout << "(" << iter->first << "," << iter->second << ") ";
	cout << '\n';
	return 0;
}

(1, 70) (3, 100) (4, 40) (5, 100) (7, 100) (8, 30) (9, 50)
key 5에 매핑된 value : 100
[lower_iter, upper_iter): (5, 100)
[iter2.first, iter.second): (5, 100)