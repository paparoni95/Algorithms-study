// https://yabmoons.tistory.com/99 글이 잘 정리되어 있고, 도움을 많이 받은 블로그입니다.

// 왜 공부? : 브루트포스 알고리즘에서 가장 많이 사용되는 방식이며, 순열과 조합으로 모든 경우의 수를 계산해서 원하는 결과 값을 구하는 방법이다.

/* 조합이란?
   
   순서가 상관이 없는 모임을 의미한다.
   순서가 상관이 없기 때문에 {1, 2, 3} {1, 3, 2} {2, 1 ,3}을 모두 같은 것으로 취급한다.

   흔히 알고리즘에서 "5개 중에서 3개 뽑기" 부분이 있는데, 이 때 적용한다.
   {1, 2, 3} {1, 2, 4} {1, 2, 5} {2, 3, 4} {2, 3, 5} {3, 4, 5} ...

   핵심은 재귀로 조합을 구현할 때에는 시작점을 결정한 이후, 그 전의 요소는 다시는 쳐다도 안본다는 것이 중요하다.
   
   시간 복잡도 : O(2^N)

   해당 index에서 해당 원소를 뽑는다, 안 뽑는다  => 2번
   index가 N개라면 => 2 * 2 * 2 * ... * 2 = 2^N
*/

#include <iostream>
using namespace std;

int arr[5];
bool select[5];

void DFS(int index, int cnt)
{
    if (cnt == 3) // 종료조건
    {
        for (int i = 0; i < 5; i++)
        {
            if (select[i] == true) cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = index; i < 5; i++)
    {
        if (select[i] == true) continue; // 선택했다면 그 부분은 넘어간다.
        select[i] = true;
        DFS(i, cnt + 1);
        select[i] = false;
    }
}

int main()
{
    for (int i = 0; i < 5; i++) arr[i] = i + 1;
    DFS(0, 0);
    return 0;
}
