#include <iostream>
#include <set>
using namespace std;

int main()
{
	multiset<int> ms;
	// less <
	// left node < parent node <= right node
	ms.insert(50);
	ms.insert(30);
	ms.insert(80);
	ms.insert(80);
	ms.insert(30);
	ms.insert(70);
	auto iter = ms.insert(10); // 저장된 위치만 가리키는 반복자 리턴

	cout << "*iter : " << *iter << '\n';

	for (iter = ms.begin(); iter != ms.end(); iter++)
		cout << *iter << ' ';
	cout << '\n';

	// greater >
	// left node >= parent node > right node
	multiset<int, greater<int>> ms2;
	for (iter = ms.begin(); iter != ms.end(); iter++)
		ms2.insert(*iter);

	for (iter = ms2.begin(); iter != ms2.end(); iter++)
		cout << *iter << ' ';
	cout << '\n';

	return 0;
}

*iter : 10
10 30 30 50 70 80 80
80 80 70 50 30 30 10