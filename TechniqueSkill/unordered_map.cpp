/*
    출처:) https://gracefulprograming.tistory.com/3 [Peter의 우아한 프로그래밍]

	# map vs hash_map(unordered_map)
	일반적으로 데이터의 양이 많은 경우 map < unordered_map (성능)
	map은 O(lgN)
	unordered_map은 O(1)

	'어느 시점부터' hash_map이 좋을까?

	# map
	레드블랙 트리 기반 - 빠른 BST에 Self-Balancing 기능을 추가한 것 [AVL Tree]만큼 엄격하진 않음.
	모든 데이터는 정렬되어 저장된다.
	입력되는 키 값의 분포가 고르지 못할 경우 balancing에 대한 비용이 커져 성능이 저하될 수 있지만,
	최악의 경우에도 O(lgN)이 보장됨.

	# unordered_map
	hash_table 기반으로 데이터 구조의 성능이 해시 함수에 크게 의존된다.
	hash_table 을 통해 참조하므로 각 노드들은 정렬할 필요가 없다. 정렬을 안함
	충분한 hash_table의 크기만 주어진다면 데이터의 양이 많아도 성능을 꾸준하게 보장할 수 있음.

	원소를 삽입하거나 검색하기 위해서 먼저 해시 함수라는 것을 사용 (해싱)
	해시 함수란 임의의 크기의 데이터를 고정된 크기의 데이터로 대응시켜주는 함수
	해시 함수의 가장 중요한 성질은 같은 원소를 해시 함수에 전달하면 같은 해시값을 리턴함.
	해시 함수가 해시값 계산을 상수 시간에 처리한다.
	물론 다른 원소임에도 불구하고 같은 해시값을 갖는 경우 이를 해시 충돌(Hash collision)이라고 함.

	원래 해시 함수는 최대한 1 ~ N 까지 고른 값을 반환하도록 설계되어있다. 그렇지만 운이 나뻐서
	모두 1번 상자에 들어갈 수도 있게 되는데 이러면 탐색이 O(1)이 아니고 O(N, 상자의 개수)가 될 것.
	이럴 때 내부적으로 rehashing이 일어나 이를 방지함.

	또한 처음부터 많은 개수의 상자를 사용할 수 없기 때문에(메모리를 낭비하지 않기 위해서) 상자의 개수는
	삽입되는 원소가 많아짐에 따라 점진적으로 늘어나게 된다.(마치 vector처럼)
	위에서 말했듯이 상자의 개수가 늘어나면 해시 함수를 바꿔야하기 때문에 모든 원소들을 처음부터 끝까지 다시
	insert 하는 과정을 Rehashing라 하며 O(N)이 걸리게 됨.
	이를 방지하기 위해 상자의 개수를 사전에 늘리는 작업을 미리 하는 공간확보를 하면 성능에 유리함.

	# 성능 비교
	키의 데이터 타입이 숫자일 때와 문자열일 때 차이가 있음.
	
	<integer>
	map - O(lgN)
	unordered_map - O(1)

	<string>
	black, blue, cyan, gray, green, lime, magenta, maroon,
	navy, olive, purple, red, silver, teal, white, yellow

	map은 insert 할 때 key를 기반으로 정렬하게 되는데 문자열 비교 함수의 성능은 
	문자열 전체를 hashing 하는 것에 비해 우수하다.
	key value들의 분포가 고르게 형성되어 있어 앞의 몇 글자만 비교해서 우열이 가려질 가능성이 있기 때문

	반면 문자열의 길이가 길어지면 key를 hashing하는 unordered_map의 경우 성능에 영향을 상대적으로 많이 받음.

	abnormal, abnomality, abnomalities, abnormalization


	물론 key의 집합이 접두사가 비슷한 경우라면 map도 문자열의 길이의 영향을 더 크게 받게 됨.

	# 결론
	1. 데이터가 많은 경우에는 unordered_map이 map보다 성능 면에서는 우수
	2. 문자열을 키로 사용하는 경우 문자열이 길어질수록 unordered_map이 map에 비해 성능이 떨어질 수 있음
	3. 유사도가 높은 문자열 집합을 키로 사용하는 경우에 map의 성능이 떨어질 수 있음.
	즉, key를 이용하여 정렬을 해야 하는 경우를 제외하고 대량의 데이터를 저장할 때는 unordered_map 을 사용하는 것이 좋음.

	# 데이터의 개수가 적을 때 unordered_map의 성능이 떨어지는 이유는?
	입력된 key에 대해서 hash value를 계산하는 비용과 hash_table 에서 탐색하는 비용 때문
	=> hashing + search 비용
	데이터의 수가 많아지면 어느 순간부터 hashing비용보다 order 비용이 더 커진다.

	데이터의 존재 유무만 궁금하다면 set
	중복 데이터를 허락할 경우 multiset
	데이터에 대응되는 데이터를 저장하고 싶은 경우 map
	중복 키를 허락할 경우 multiset
	(insert, erase, find 모두 O(lgN) 최악의 경우도 O(lgN)
	속도가 매우매우 중요해서 최적화를 해야하는 경우 unordered_set, unordered_map
	(insert, erase, find 모두 O(1)이지만 최악의 경우 O(N) 그러므로 해시함수와 상자 개수를 잘 설정해야함)
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	unordered_map<string, int> um;

	um["Hello"] = 20;
	um["Premium"] = 10;
	um["Me"] = 5;
	um["H"] = 7;

	for (auto x : um)
		cout << x.first << ' ' << x.second << '\n';
	cout << '\n';
	return 0;
}