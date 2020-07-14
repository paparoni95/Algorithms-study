// https://yabmoons.tistory.com/100

// 순열에 대해서 공부

/* 순열이란?

	말 그대로, 순서가 존재하는 열이다.
	{1, 2, 3} 과 {1, 3, 2}의 결과는 다르다는 것!

	C++ STL에서 next_permutation / prev_permutation을 통해서 쉽게 구현이 가능.

	하지만, 재귀적으로 짜는 코드도 중요하다고 생각된다.

	마찬가지로 5개중에서 3개를 뽑는다고 하면?
	{1,2,3} {1,2,4} {1,2,5} {1,3,4} {1,3,5} ... {1,4,5}...
	{2,1,3} {2,1,4} {2,1,5} {2,3,4} {2,3,5} {2,4,5}...
	...

    {1,2,3} != {2,1,3} 이 핵심
*/

#include <iostream>
#include <vector>
using namespace std;

int arr[5];
bool select[5];
vector<int> v;

void DFS(int cnt)
{
	if (cnt == 3)
	{
		for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
		cout << endl;
		return;
	}

	for (int i = 0; i < 5; i++)
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
	for (int i = 0; i < 5; i++) arr[i] = i + 1;
	DFS(0);
	return 0;
}