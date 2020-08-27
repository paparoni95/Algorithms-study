// https://yabmoons.tistory.com/122

/* 중복조합

   조합에서 중복을 허용하는 것이 중복 조합이다.

   {1,2,3}에서 2개를 뽑는다면
   {1,1},{1,2},{1,3},{2,2},{2,3},{3,3}

   {1,2,3}에서 3개를 뽑는다면
   {1,1,1},{1,1,2},{1,1,3},{1,2,2},{1,2,3},{1,3,3}
   {2,2,2},{2,2,3},{2,3,3},{3,3,3}

   핵심은 재귀로 조합을 구현할 때 시작점을 결정한 이후,
   그 전의 요소는 다시는 쳐다도 안 본다는 것이 중요하다.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr = { 1,2,3 };
vector<int> select(3);

void DFS(int index, int cnt)
{
	if (cnt == 2)
	{
		for (int i = 0; i < 2; ++i)
			cout << select[i] << " ";
		cout << endl;
		return;
	}

	for (int i = index; i < 3; ++i)
	{
		select[cnt] = arr[i]; // cnt번째 뽑은 카드는 arr[i]
		DFS(i, cnt + 1);
	}
}

int main()
{
	DFS(0, 0);
	return 0;
}