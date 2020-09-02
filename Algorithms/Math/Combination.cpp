// https://yabmoons.tistory.com/99

// 브루트포스 알고리즘에서 가장 많이 사용되는 방식이며,
// 모든 경우의 수를 계산해서 원하는 결과 값을 구하는 방법

/* 조합이란?
   
   순서가 상관이 없는 모임을 의미.
   순서가 상관이 없기 때문에 {1,2,3},{1,3,2},{2,1,3}을 모두 같은 것으로 취급
   한마디로 {1,2,3} = {1,3,2} = {2,1,3} 이므로
   {1,2,3}이 등장하면, {1,3,2},{2,1,3}은 등장하지 않는다 중복되기 때문에

   흔히 알고리즘에서 "5개 중에서 3개를 뽑기" 부분에서 적용
   {1,2,3},{1,2,4},{1,2,5} ... {3,4,5} ...

   핵심은 재귀로 조합을 구현할 때에는 시작점을 결정한 이후,
   그 전의 요소는 다시는 쳐다도 안본다는 것이 중요하다.
   
   시간 복잡도 : O(nCr)
   nCr = n! / r! * (n-r)!
   
   5C5 = 1 => 5개 중에서 5개를 뽑기 (조합으로) 1 2 3 4 5 끝
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr = { 1,2,3,4,5 };
bool select[5];

void DFS(int index, int cnt)
{
	// 종료조건
	if (cnt == 3)
	{
		for (int i = 0; i < 5; ++i)
		{
			if (select[i] == true)
				cout << arr[i] << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = index; i < 5; ++i)
	{
		if (select[i] == true) continue;
		select[i] = true;
		DFS(i, cnt + 1);
		select[i] = false;
	}
}

int main()
{
	DFS(0, 0);
	return 0;
}
