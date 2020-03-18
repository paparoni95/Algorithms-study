#include <iostream>
#include <map>
using namespace std;

// map
// 딕셔너리 자료구조
// 원소 삽이과 삭제, 탐색 등의 연산은 O(logN)을 보장한다.

int main()
{
	// int자료형을 key로 int자료형을 데이터로 저장하는 딕셔너리 자료구조 생성
	map<int, int> m;
	// (4,5)원소 삽입
	m.insert(make_pair(4, 5));
	// 또는
	m[5] = 6;
	// key와 연관된 원소를 pair<키 자료형, 데이터 자료형> 형태로 리턴한다.
	printf("key : %d, value : %d\n", m.find(4)->first, m.find(4)->second);
	printf("key : %d, value : %d\n", m.find(5)->first, m.find(5)->second);
	// key와 연관된 원소의 개수를 리턴
	printf("count : %d\n", m.count(4));
	// 저장된 원소의 수를 리턴함
	printf("size : %d\n", m.size());
	// 해당 주소의 원소 삭제
	m.erase(++m.begin());

	// map에 저장되어있는 모든 원소 출력
	map<int, int>::iterator iter;
	for(iter = m.begin(); iter != m.end(); iter++)
		printf("key : %d, value : %d\n", iter->first, iter->second);

	// 모든 원소 삭제
	m.clear();
	return 0;
}