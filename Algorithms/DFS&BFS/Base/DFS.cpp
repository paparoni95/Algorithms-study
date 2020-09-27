#include <bits/stdc++.h>
using namespace std;

// 각 정점을 방문했는지 여부를 판단
bool visited[9];
// 그래프의 인접리스트 : 시간 복잡도 O(V + E)
vector<int> graph[9];

// DFS 함수 정의
void DFS(int x) {
	// 현재 노드를 방문 처리
	visited[x] = true;
	cout << x << ' ';
	// 현재 노드와 연결된 다른 노드를 재귀적으로 방문
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		// 아직 방문한 적 없다면 방문
		if (!visited[y]) DFS(y);
	}
	// 더이상 방문할 정점이 없으니, 재귀 호출을 종료하고 이전 정점으로 돌아간다.
}

int main() {
	// 노드 1에 연결된 노드 정보 저장
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(8);

	// 노드 2에 연결된 노드 정보 저장
	graph[2].push_back(1);
	graph[2].push_back(7);

	// 노드 3에 연결된 노드 정보 저장
	graph[3].push_back(1);
	graph[3].push_back(4);
	graph[3].push_back(5);

	// 노드 4에 연결된 노드 정보 저장
	graph[4].push_back(3);
	graph[4].push_back(5);

	// 노드 5에 연결된 노드 정보 저장
	graph[5].push_back(3);
	graph[5].push_back(4);

	// 노드 6에 연결된 노드 정보 저장
	graph[6].push_back(7);

	// 노드 7에 연결된 노드 정보 저장
	graph[7].push_back(2);
	graph[7].push_back(6);
	graph[7].push_back(8);

	// 노드 8에 연결된 노드 정보 저장
	graph[8].push_back(1);
	graph[8].push_back(7);

	// 데이터의 개수가 N개인 경우 O(N)의 시간이 소요된다.
	DFS(1);
	return 0;
}