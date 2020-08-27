// https://yabmoons.tistory.com/100

// 순열에 대해서

/* 순열이란?
   
   순서가 존재하는 열이다.
   {1,2,3}과 {1,3,2}의 결과는 다르다는 것.(순서가 다르므로)

   C++ STL에서 next_permutation / prev_permutation을 통해서 쉽게 사용 가능.
   다만, 재귀적으로 짜는 코드의 연습도 중요하다.

   마찬가지로 5개 중에서 3개를 뽑는다고 하면?
   {1,2,3},{1,2,4},{1,2,5},{1,3,4},{1,3,5} ... {1,4,5} ...
   {2,1,3},{2,1,4},{2,1,5} ...
   ...

   {1,2,3} != {2,1,3} 이 핵심

   해당 순번에서 다음 순열을 구할 때에는 시간 복잡도는 O(N)이다.
   다만, 전체 순열을 구하려고 한다면 O(N!)이 걸린다.
   10! = 3,628,800  (3백만)
   11! = 39,916,800 (4천)
   12! = 479,001,600(4억)

   알고리즘을 사용하려면 최대한 10 ~ 11을 넘지 않는 선에서만 가능하다.
   넘어가면 시간 초과
*/

#include <iostream>
#include <vector>
using namespace std;

bool select[5];
vector<int> v;
vector<int> arr;

void DFS(int cnt)
{
	// 3개를 뽑았다면
	if (cnt == 3)
	{
		for (int i = 0; i < v.size(); ++i)
			cout << v[i] << ' ';
		cout << endl;
		return;
	}

	for (int i = 0; i < 5; ++i)
	{
		if (select[i] == true) continue;
		select[i] = true;
		v.push_back(arr[i]);
		DFS(cnt + 1);
		v.pop_back();
		select[i] = false;
	}
}

int main()
{
	arr = { 1,2,3,4,5 };
	DFS(0);
	return 0;
}