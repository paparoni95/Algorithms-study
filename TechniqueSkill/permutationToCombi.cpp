#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// next_permutation을 이용해 조합 만들기

int main()
{
	vector<int> v(9);
	for (int i = 0; i < 9; i++) cin >> v[i]; // 9C7 (9개중에서 7개를 뽑아 쓰겠다고 하면)
	vector<int> comb;

	// 9C7
	for (int i = 0; i < 2; i++) comb.push_back(0); 
	for (int i = 0; i < 7; i++) comb.push_back(1); // 선택하는 애들을 1로 넣어준다.

	do
	{
		for (int i = 0; i < 9; i++)
		{
			if (comb[i]) cout << v[i] << ' '; // 1인 애들만 골라 출력한다.
		}
		cout << '\n';
	} while (next_permutation(comb.begin(), comb.end()));
	return 0;
}
