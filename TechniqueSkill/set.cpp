#include <iostream>
#include <set>
using namespace std;

/*
	# set의 특징들
	1. 숫자든 문자든 중복을 없앤다.
	2. 삽입하는 순서에 상관없이 정렬되서 입력된다.
	3. balanced tree (R-B Tree)

	# set 용량
	empty() : 비어있다면 true, 아니면 false
	size() : set 저장된 원소의 수
	max_size() : set이 가질 수 있는 최대 크기

	# set 삽입,삭제
	insert() : set에 삽입
	erase() : set에 저장된 요소 삭제
	swap() : set1, set2 스왑
	clear() : 요소들 전부 삭제
	emplace() : move()를 사용해 객체를 저장
	emplace_hint() : 삽입될 위치에 대한 힌트를 토대로 삽입

	# set 기능들
	find() : 찾는 값이 있다면 해당 위치의 iterator를 반환, 아니면 end() 반환
	count() : set에 저장된 요소 개수 반환
	lower_bound() : set 요소의 위치에 대한 iterator를 반환, 그 값과 같거나 이상인 부분
	upper_bound() : set 요소의 위치에 대한 iterator를 반환, 그 값을 초과하는 부분
	equal_range() : 해당 요소에 대한 범위 iterator를 반환

	# set 반복자
	begin() : 시작되는 주소
	end() : 마지막 뒤 주소
	rbegin() : 마지막 부분을 시작 주소
	rend() : 첫번째 부분을 마지막 주소
	cbegin() : begin()과 동일하지만 const로 설정
    cend() : end()와 동일하지만 const로 설정
	crbegin() : rbegin()과 동일하지만 const로 설정
    crend() : rend()와 동일하지만 const로 설정
*/

int main()
{
	set<int> s{ 1,2,3,4,5 };

	s.insert(3); // 1 2 3 4 5
	s.insert(5); // 1 2 3 4 5
	s.insert(7); // 1 2 3 4 5 7
	s.insert(-1);// -1 1 2 3 4 5 7

	if (s.find(7) != s.end())
		cout << "7 found!\n";
	else
		cout << "7 not found!\n";

	cout << "s.empty() : " << s.empty() << endl;
	cout << "s.size() : " << s.size() << endl;
	cout << "s.max_size() : " << s.max_size() << endl << endl;

	set<int> s2 = { 1,2,3,4,5,6,7,8,9,10 };
	pair<set<int>::iterator, set<int>::iterator> iter = s2.equal_range(4);
	cout << "s2.equal_range(4) : " << *iter.first << ' ' << *iter.second << endl;

	set<int>::iterator lower_iter = s2.lower_bound(3);
	set<int>::iterator upper_iter = s2.upper_bound(3);
	cout << "lower_iter : " << *lower_iter << endl;
	cout << "upper_iter : " << *upper_iter << endl;

	// 3 ~ 7 삭제
	lower_iter = s2.lower_bound(3);
	upper_iter = s2.upper_bound(7);
	s2.erase(lower_iter, upper_iter);
	for (int n : s2) cout << n << ' ';
	cout << endl << endl;

	set<int> s3;

	s3.emplace(10);
	s3.emplace(20);
	s3.emplace(-1);
	s3.emplace(-5);
	s3.emplace(7);

	set<int>::iterator s3_iter = s3.emplace_hint(s3.end(), 21); // 삽입 속도 빠름
	s3.emplace_hint(s3_iter, 1); // 삽입 속도 느림
	for (int n : s3) cout << n << ' ';
	cout << endl << endl;

	// insert와 emplace 반환값은 pair<iterator, bool>
	// pair.first 삽입한 위치에 대한 iterator
	// pair.second 삽입 성공 여부에 대한 bool
	set<int> s4;
	pair<set<int>::iterator, bool> chk = s4.insert(10);
	if (chk.second)
		cout << "10 insert success!\n";
	else
		cout << "10 insert failure!\n";

	set<pair<int, int>> s5;
	s5.insert({ 2,3 });
	s5.insert({ 1,5 });
	s5.insert({ 1,2 });
	s5.emplace(5, 6);
	for (auto n : s5) cout << n.first << ' ' << n.second << endl;

	return 0;
}