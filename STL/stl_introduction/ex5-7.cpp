/* 함수 객체를 적용한 sort 알고리즘

   함수 객체를 사용하면 STL 구성 요소를 더욱 유연하게 사용할 수 있다.
*/
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(30);

	// sort(b,e,f) f를 정렬 기준으로 정렬한다.

	sort(v.begin(), v.end(), less<int>()); // 오름차순 정렬
	for (auto iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	sort(v.begin(), v.end(), greater<int>()); // 내림차순 정렬
	for (int n : v)
		cout << n << ' ';
	cout << endl;

	return 0;
}