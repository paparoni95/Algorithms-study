// 정방향 반복자와 역방향 반복자가 가리키는 값
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

	// 40 원소를 가리키는 정방향 반복자
	vector<int>::iterator normal_iter = v.begin() + 3;
	// normal_iter의 역방향 반복자
	vector<int>::reverse_iterator reverse_iter(normal_iter);

	cout << "정방향 반복자의 값: " << *normal_iter << endl;
	cout << "역방향 반복자의 값: " << *reverse_iter << endl;
	cout << endl;

	// -- 연산자를 사용하지 않고 ++ 연산자만으로 정방향, 역방향의 순회가 모두 가능
	for (vector<int>::iterator iter = v.begin(); iter != normal_iter; ++iter)
		cout << *iter << ' ';
	cout << endl;

	for (vector<int>::reverse_iterator riter = reverse_iter; riter != v.rend(); ++riter)
		cout << *riter << ' ';
	cout << endl;

	return 0;
}