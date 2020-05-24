// https://yabmoons.tistory.com/122

// 중복 조합

/*
	중복 조합: 조합에서 중복을 허용한다.

	{1,2,3}에서 2개를 뽑는다면
	{1,1}{1,2}{1,3}{2,2}{2,3}{3,3}

									   DFS(0,0)
	     
			 DFS(0,1)                  DFS(1,1)               DFS(2,1)
	DFS(0,2) DFS(1,2)  DFS(2,2)     DFS(1,2) DFS(2,2)         DFS(2,2)
      {1,1}   {1,2}      {1,3}        {2,2}   {2,3}            {3,3}

	핵심은 재귀로 조합을 구현할 때에는 시작점을 결정한 이후, 그 전의 요소는 다시는 쳐다도 안본다는 것이 중요하다.
*/

#include <iostream>

#define MAX 3
using namespace std;

int arr[MAX];
int select[MAX];

void DFS(int index, int cnt)
{
	//cout << "DFS(" << index << "," << cnt << ")" << endl;
	if (cnt == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			cout << select[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = index; i < MAX; i++)
	{
		select[cnt] = arr[i]; // cnt번째 뽑은 카드는 arr[i]입니다.
		DFS(i, cnt + 1);
	}
}

int main()
{
	for (int i = 0; i < MAX; i++) arr[i] = i + 1;
	DFS(0, 0);
	return 0;
}