#include <iostream>
#include <vector>
using namespace std;

// 그래프의 인접리스트 : 시간 복잡도 O(V + E)
vector<vector<int>> adj(7);
// 각 정점을 방문했는지 여부를 판단
vector<bool> visited;
// 깊이 우선 탐색을 구현
void DFS(int here) {
	cout << "DFS visits " << here << endl;
	visited[here] = true;
	// 모든 인접 정점을 순회하면서
	for (int i = 0; i < adj[here].size(); ++i) { // O(E)
		int there = adj[here][i];
		// 아직 방문한 적 없다면 방문
		if (!visited[there])
			DFS(there);
	}
	// 더이상 방문할 정점이 없으니, 재귀 호출을 종료하고 이전 정점으로 돌아간다.
}

void DFSAll() {
	// visited를 모두 false로 초기화
	visited = vector<bool>(adj.size(), false);
	// 모든 정점을 순회하면서, 아직 방문한 적 없으면 방문
	for (int i = 0; i < adj.size(); ++i)  // O(V)
		if (!visited[i])
			DFS(i);
}

int main()
{
	adj[1].push_back(2);
	adj[1].push_back(4);
	adj[2].push_back(3);
	adj[4].push_back(5);
	adj[5].push_back(6);

	DFSAll();

	return 0;
}