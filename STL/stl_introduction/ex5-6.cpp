/* sort 알고리즘은 임의 접근 반복자를 요구하므로 vector, deque
   는 sort 알고리즘이 가능하지만, 다른 컨테이너는 불가능하다.

   연관 컨테이너는 컨테이너만의 정렬 기준을 가지고 있다.
*/
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(5);
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);

	list<int> lt;
	lt.push_back(50);
	lt.push_back(40);
	lt.push_back(30);
	lt.push_back(20);
	lt.push_back(10);

	sort(v.begin(), v.end()); // 정렬 가능 (vector는 임의 접근 반복자)
	//sort(lt.begin(), lt.end()); // 에러! list는 양방향 반복자

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;

	return 0;
}