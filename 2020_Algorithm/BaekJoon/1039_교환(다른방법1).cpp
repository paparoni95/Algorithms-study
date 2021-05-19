// 출처 : https://blog.naver.com/kks227/220613889973
// 이 코드가 훨씬 가독성이 좋은 것 같다.
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	string N, result = "0";
	int K;
	cin >> N >> K;
	queue<string> q;
	q.push(N);

	// K번 연산하기
	for (int i = 0; i < K; i++)
	{
		int qSize = q.size();
		set<string> visited;
		// string이기 때문에 배열 대신에 set을 사용
		for (int j = 0; j < qSize; j++)
		{
			string cur = q.front();
			q.pop();

			if (visited.count(cur)) continue;
			visited.insert(cur); // 방문체크
			// 모든 가능한 쌍 시도
			for (int k = 0; k < cur.size() - 1; k++)
			{
				for (int l = k + 1; l < cur.size(); l++)
				{
					if (k > 0 || cur[l] != '0')
					{
						swap(cur[k], cur[l]);
						q.push(cur);
						swap(cur[k], cur[l]);
					}
				}
			}
		}
	}

	// 가장 큰 값 고르기
	while (!q.empty())
	{
		result = max(result, q.front());
		q.pop();
	}

	if (result[0] == '0') cout << -1 << '\n';
	else cout << result << '\n';
	return 0;
}