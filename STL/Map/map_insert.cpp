#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, int> m; // (key, value) less <

	// 임시 pair 객체 생성 후 저장
	m.insert(pair<int, int>(5, 100));
	m.insert(pair<int, int>(3, 100));
	m.insert(pair<int, int>(8, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(1, 70));
	m.insert(pair<int, int>(7, 100));

	pair<int, int> pr(9, 50);
	m.insert(pr);

	for (auto iter = m.begin(); iter != m.end(); iter++)
		cout << "(" << (*iter).first << ',' << (*iter).second << ") ";
	cout << '\n';

	// iterator는 -> 연산자 오버로딩되어 있으므로
	// 포인터처럼 멤버를 -> 연산자로 접근이 가능
	for (auto iter = m.begin(); iter != m.end(); iter++)
		cout << "(" << iter->first << ',' << iter->second << ") ";
	cout << '\n';

	pair<map<int, int>::iterator, bool> ret;
	ret = m.insert(pair<int, int>(9, 50));
	if (true == ret.second)
		cout << "key: " << ret.first->first << ", value: " << ret.first->second << " success\n";
	else
		cout << "key: " << ret.first->first << ", value: " << ret.first->second << " failure\n";

	return 0;
}

(1, 70) (3, 100) (4, 40) (5, 100) (7, 100) (8, 30) (9, 50)
(1, 70) (3, 100) (4, 40) (5, 100) (7, 100) (8, 30) (9, 50)
key: 9, value : 50 failure