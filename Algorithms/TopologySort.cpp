#include <iostream>
#include <vector>
#include <queue>
#define MAX 10
using namespace std;

// 위상 정렬의 시간복잡도 O(V+E)
// 정점의 개수 + 간선의 개수만큼
// 그래프의 간선을 2중 벡터형태로 구현했기 때문에,
// 2차원 배열과는 달리 연결된 간선 즉, E만큼만 탐색하기 때문이다.
// 보통 vector는 인접 리스트의 효과를 볼 수 있다.

int n, inDegree[MAX]; // 진입차수를 의미
vector<int> a[MAX];

void topologySort() {
	int result[MAX];
	queue<int> q;
	// 진입 차수가 0인 노드를 큐에 삽입한다.
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}
	// 위상 정렬이 완전히 수행되려면 정확히 N개의 노드를 방문한다.
	for (int i = 1; i <= n; i++) {
		// N개를 방문하기 전에 큐가 빈다면 사이클이 발생한 것
		if (q.empty()) {
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x; // 경로를 저장하기 위해서
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i]; // 정점 x와 연결되어있는 노드
			// 연결되어있는 모든 정점들의 진입차수를 -1 감소시킨다.
			// 이는 간선 제거 역할을 대신해준다.
			--inDegree[y];
			if (inDegree[y] == 0) {
				q.push(y);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] << ' ';
	}
}

int main() {
	n = 7;
	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;
	a[2].push_back(3);
	inDegree[3]++;
	a[3].push_back(4);
	inDegree[4]++;
	a[4].push_back(6);
	inDegree[6]++;
	a[5].push_back(6);
	inDegree[6]++;
	a[6].push_back(7);
	inDegree[7]++;
	topologySort();
	return 0;
}