// https://yabmoons.tistory.com/123

// 중복 순열

/*
	순열이라는 것은 순서가 존재하는 수열이며,
	동시에 {1,2} != {2,1}은 다른 경우이다. (순서가 매우 중요)

	여기서 중복이 허용되었다는 점이 추가된 것이 중복 순열

	{1,2,3}에서 2개를 뽑을 때
	{1,1}{1,2}{1,3}{2,1}{2,2}{2,3}{3,1}{3,2}{3,3}
*/

#include <iostream>

#define MAX 5
using namespace std;

int arr[MAX];
int select[MAX];

// 순열에서는 index가 필요가 없으므로, cnt만 사용한다.
void DFS(int cnt)
{
	if (cnt == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << select[i] << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < MAX; i++)
	{
		select[cnt] = arr[i];
		DFS(cnt + 1);
	}
}

int main()
{
	for (int i = 0; i < MAX; i++) arr[i] = i + 1;
	DFS(0);
	return 0;
}