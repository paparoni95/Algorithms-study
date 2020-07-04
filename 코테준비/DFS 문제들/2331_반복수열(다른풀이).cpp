// https://jaimemin.tistory.com/946
// DFS 로도 풀리는 것을 알았다.
// visited[num]이 왜 3에서 끝나게 하셨을까?
// 궁금증 해결 : visited[num] == 2에서 끝나게 되버리면, 해당 문제 예시에서 37만
//               중첩되고 나머지는 중첩인지 아닌지 확인할 방도가 나타나지 않는다.
//               따라서 두 번째 반복하는 시점 즉, visited[num] == 3일 때 재귀함수
//               를 탈출하여서 문제를 해결하는 방안이다.

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 300000 + 1;

int A, P;
int visited[MAX];

void DFS(int num)
{
	visited[num]++;
	// 반복구간이 한 번 반복되었다는 것을 의미
	if (visited[num] == 3) return;

	int sum = 0;
	while (num)
	{
		sum += (int)pow((num % 10), P);
		num /= 10;
	}

	DFS(sum);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> A >> P;

	DFS(A);
	int result = 0;
	//한 번만 등장한 숫자들이 반복구간에 속하지 않은 숫자들
	for (int i = 0; i < MAX; i++)
	{
		if (visited[i] == 1) result++;
	}

	cout << result;
	return 0;
}
