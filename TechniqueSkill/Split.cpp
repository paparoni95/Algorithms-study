#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

/*
	# C++에서 string 문자열을 받아와 split 하기

	1. istringstreama 과 getline 사용
	2. string의 find 과 substr 사용
*/

int main()
{
	/* 구분자가 있는 경우 split으로 잘라 vector에 넣기 */
	string str = "java c c++ python";
	istringstream ss(str);
	string stringBuffer;
	vector<string> v;

	// 구분자가 ',' 이면 getline(ss, stringBuffer, ',') 로 하면 된다.
	while (getline(ss, stringBuffer, ' '))
	{
		v.push_back(stringBuffer);
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';

	
	/* 다른 예시 */
	cout << endl;
	string as = "this,is,string";
	istringstream ss2(as);
	string stringBuffer2;
	while (getline(ss2, stringBuffer2, ','))
		cout << stringBuffer2 << ' ';
	cout << endl;

	/* string의 find 함수와 substr 활용 */
	cout << endl;
	as = "this,is,string";
	size_t previous = 0, current;
	current = as.find(',');
	// find 함수는 해당 위치부터 문자열을 찾지 못할 경우 npos를 반환한다.
	while (current != string::npos)
	{
		string substring = as.substr(previous, current - previous);
		cout << substring << ' ';
		previous = current + 1;
		// previous부터 ,이 나오는 위치를 찾는다.
		current = as.find(',', previous);
	}

	// 마지막 문자열 출력
	cout << as.substr(previous, current - previous);

	return 0;
}