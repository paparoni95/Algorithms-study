#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int, greater<int>> s; // greater >
	// left node > parent node > right node

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
	return 0;
}

90 80 70 50 40 30 10