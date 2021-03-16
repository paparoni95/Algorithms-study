#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	# unique
	범위에서 연속 중복을 제거한다. [first, last)
*/

int main()
{
	vector<int> v = { 10, 20, 20, 20, 30, 30, 20, 20, 10 };

	vector<int>::iterator it;
	it = unique(v.begin(), v.end()); // 10 20 30 20 10 ? ? ? ?
	                                 //                ^

	v.resize(distance(v.begin(), it)); // 10 20 30 20 10

	cout << "v contains: ";
	for (it = v.begin(); it != v.end(); ++it) cout << *it << ' ';
	cout << "\n\n";

	vector<int> v2 = { 10,20,20,20,30,30,20,20,10 };
	sort(v2.begin(), v2.end());     // 10 10 20 20 20 20 20 30 30
	v2.erase(unique(v2.begin(), v2.end()), v2.end()); // 10 20 30
	cout << "v2 contains: ";
	for (int i : v2) cout << i << ' ';
	cout << "\n\n";
	return 0;
}