// https://yabmoons.tistory.com/123

/* 중복순열
   
   기존의 순열은 순서가 존재하는 순열이며, 그 순서가 중요하다.
   동시에 {1,2} != {2,1}은 다르기 때문에 둘다 보여준다.

   여기서 중복이 허용되었다는 점이 추가된 것이 중복 순열이다.

   {1,2,3}에서 2개를 뽑을 때
   {1,1},{1,2},{1,3},{2,1},{2,2},{2,3},{3,1},{3,2},{3,3}
   
   말그대로 중복이 허용된 것이 중복순열이다.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr = { 1,2,3,4,5 };
vector<int> select(5);

void DFS(int cnt)
{
	if (cnt == 3)
	{
		for (int i = 0; i < 3; ++i)
		{
			cout << select[i] << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < 5; ++i)
	{
		select[cnt] = arr[i];
		DFS(cnt + 1);
	}
}

int main()
{
	DFS(0);
	return 0;
}