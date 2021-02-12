// 컨테이너 기본 할당기
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	// vector<typename T, typename Alloc = allocator<T>>
	vector<int, allocator<int>> v;
	v.push_back(10);
	cout << *v.begin() << endl;

	// set<typename T, typename Pred = less<T>,
	// typename Alloc = allocator<T>>
	set<int, less<int>, allocator<int>> s;
	s.insert(10);
	cout << *s.begin() << endl;
	return 0;
}