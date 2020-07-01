// https://jaimemin.tistory.com/946
// DFS 로도 풀리는 것을 알았다.
// visited[num]이 왜 3에서 끝나게 하셨을까?

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