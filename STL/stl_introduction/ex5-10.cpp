// 역방향 반복자 reverse_iterator
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (auto iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	// 일반 반복자 iterator를 역방향 반복자 reverse_iterator로 변환
	reverse_iterator<vector<int>::iterator> riter(v.end());
	reverse_iterator<vector<int>::iterator> end_riter(v.begin());
	for (; riter != end_riter; ++riter)
		cout << *riter << ' ';
	cout << endl;

	// STL 모든 컨테이너는 반복자 어댑터 reverse_iterator를 typedef 타입으로 정의하여
	// rbegin(), rend() 로 컨테이너의 역방향 반복자를 반환
	for (auto iter = v.rbegin(); iter != v.rend(); ++iter)
		cout << *iter << ' ';
	cout << endl;
	return 0;
}