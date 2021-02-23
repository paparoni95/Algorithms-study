#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// V 정점, E 간선
// 시간 복잡도 O(VE)

vector<int> v[100];
int dist[100]; // dist[i] : 시작 노드 ~ i번째 노드까지의 최단 거리

void dfs(int node)
{
	for (int i = 0; i < v[node].size(); i++)
	{
		int next = v[node][i];
		// 아직 방문하지 않았거나, 이미 구한 경로보다 더 빠른 경로를 찾았다면
		if (dist[next] == -1 || dist[next] > dist[node] + 1)
		{
			dist[next] = dist[node] + 1;
			dfs(next);
		}
	}
}

int main() // 양의 가중치만 생각
{
	memset(dist, -1, sizeof(dist)); // 초기화
	dfs(1);
	return 0;
}