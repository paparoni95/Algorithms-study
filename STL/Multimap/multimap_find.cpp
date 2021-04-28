#include <iostream>
#include <map>
using namespace std;

int main()
{
	// less <
	// left child key < parent key <= right child key
	multimap<int, int> mm;

	//multimap은 [] operator를 제공하지 않는다.
	//mm[5] = 100;
	mm.insert(pair<int, int>(5, 100));
	mm.insert(pair<int, int>(3, 100));
	mm.insert(pair<int, int>(8, 30));
	mm.insert(pair<int, int>(3, 40));
	mm.insert(pair<int, int>(1, 70));
	mm.insert(pair<int, int>(7, 100));
	mm.insert(pair<int, int>(8, 50));

	for (auto iter = mm.begin(); iter != mm.end(); iter++)
		cout << "(" << iter->first << "," << iter->second << ") ";
	cout << '\n';

	cout << "mm.count(3): " << mm.count(3) << '\n';
	cout << "mm.count(9): " << mm.count(9) << '\n';
	cout << "mm.count(5): " << mm.count(5) << '\n';

	auto iter = mm.find(3);
	if (iter != mm.end())
		cout << "첫 번째 key 3에 매핑된 value: " << iter->second << '\n';
	else
		cout << "key 3이 multimap에 없습니다.\n";
	return 0;
}

(1, 70) (3, 100) (3, 40) (5, 100) (7, 100) (8, 30) (8, 50)
mm.count(3) : 2
mm.count(9) : 0
mm.count(5) : 1
첫 번째 key 3에 매핑된 value : 100