#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	// greater >
	map<int, string, greater<int>> m;

	// [] operator
	m[2] = "two";
	m[5] = "five";
	m[3] = "three";
	m[8] = "eight";
	m[4] = "four";
	m[6] = "six";
	m[1] = "one";
	m[7] = "seven";
	m[9] = "nine";

	for (auto iter = m.begin(); iter != m.end(); iter++)
		cout << "(" << iter->first << "," << iter->second << ") ";
	cout << '\n';

	for (int i = 0; i < m.size(); i++)
		cout << m[i] << ' ';
	cout << '\n';
	return 0;
}

(9, nine) (8, eight) (7, seven) (6, six) (5, five) (4, four) (3, three) (2, two) (1, one)
one two three four five six seven eight nine