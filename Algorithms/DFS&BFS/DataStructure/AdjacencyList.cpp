#include <bits/stdc++.h>
using namespace std;

// 인접 리스트 방식
// 연결된 정보만을 저장하기 때문에 메모리를 효율적으로 사용
// 특정한 두 노드가 연결되어 있는지에 대한 정보를 얻는 속도는 O(E), E는 간선
// 이는 연결된 데이터를 하나씩 확인해야 하기 때문이다.


// 행이 3개인 인접 리스트 표현
vector<pair<int, int>> graph[3];

int main() {
	// 노드 0에 연결된 노드 정보 저장 {노드, 거리}
	graph[0].push_back({ 1,7 });
	graph[0].push_back({ 2,5 });

	// 노드 1에 연결된 노드 정보 저장 {노드, 거리}
	graph[1].push_back({ 0,7 });

	// 노드 2에 연결된 노드 정보 저장 {노드, 거리}
	graph[2].push_back({ 0,5 });

	// 그래프 출력
	for (int i = 0; i < 3; i++) {
		// 노드 i와 연결된 다른 노드들의 정보를 탐색
		cout << "node " << i << ": ";
		for (int j = 0; j < graph[i].size(); j++) {
			cout << '(' << graph[i][j].first << ',' << graph[i][j].second << ')' << ' ';
		}
		cout << '\n';
	}
	return 0;
}