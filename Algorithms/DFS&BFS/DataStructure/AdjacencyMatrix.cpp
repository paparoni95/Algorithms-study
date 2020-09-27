#include <bits/stdc++.h>
#define INF 1e9 // 무한의 비용 선언
using namespace std;

// 인접 행렬 방식은
// 모든 관계를 저장하므로 노드의 개수가 많을수록 메모리가 불필요하게 낭비
// 특정한 두 노드가 연결되어 있는지에 대한 정보는 O(1)로 찾을 수 있다.
// ex) graph[1][2] = 1(연결), 0(연결x)
// 한 노드에서 다른 노드와 연결되어 있는지 확인은 O(V), V는 노드의 수

// 2차원 배열을 이용해 인접 행렬 표현
int graph[3][3] = {
	{0,7,5},
	{7,0,INF},
	{5,INF,0}
};

int main() {
	// 그래프 출력
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}