#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check[100];    // 방문 배열
vector<int> v[100]; // 인접 리스트

int main()
{
	queue<int> q;
	q.push(1); // 시작 노드 삽입
	check[1] = true;
	while (!q.empty()) // 큐가 비어있을 때 -> 더 이상 갈 곳이 없을 때 종료
	{
		int node = q.front(); // 큐의 맨 앞 원소
		q.pop();
		for (int i = 0; i < v[node].size(); i++)
		{
			int next = v[node][i];
			if (check[next]) continue; // 이미 방문한 노드라면 스킵
			check[next] = true; // 방문 체크
			q.push(next);
		}
	}

	return 0;
}