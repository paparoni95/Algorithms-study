#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check[100];
vector<int> v[100];
int dist[100]; // dist[i] : 시작 노드 ~ i번째 노드까지의 최단 거리
int main()
{
	queue<int> q;
	q.push(1);
	check[1] = true; dist[1] = 0;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int i = 0; i < v[node].size(); i++)
		{
			int next = v[node][i];
			if (check[next]) continue;
			check[next] = true;
			dist[next] = dist[node] + 1;
			q.push(next);
		}
	}
}