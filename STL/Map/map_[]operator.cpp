#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, int> m;

	m[5] = 100; // key 5, value 100 insert
	m[3] = 100;
	m[8] = 30;
	m[4] = 40;
	m[1] = 70;
	m[7] = 100;
	m[9] = 50;

	for (auto iter = m.begin(); iter != m.end(); iter++)
		cout << "(" << iter->first << "," << iter->second << ") ";
	cout << '\n';

	m[5] = 200; // update;

	for (auto iter = m.begin(); iter != m.end(); iter++)
		cout << "(" << iter->first << "," << iter->second << ") ";
	cout << '\n';
	return 0;
}

(1, 70) (3, 100) (4, 40) (5, 100) (7, 100) (8, 30) (9, 50)
(1, 70) (3, 100) (4, 40) (5, 200) (7, 100) (8, 30) (9, 50)