#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[1000][1000];

// DFS로 특정 노드를 방문하고 연결된 모든 노드들도 방문
bool DFS(int x, int y) {
	// 주어진 범위를 벗어나는 경우에는 즉시 종료
	if (x <= -1 || x >= n || y <= -1 || y >= m) {
		return false;
	}

	// 현재 노드를 아직 방문하지 않았다면
	if (graph[x][y] == 0) {
		// 해당 노드 방문 처리
		graph[x][y] = 1;
		// 상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
		DFS(x - 1, y);
		DFS(x + 1, y);
		DFS(x, y - 1);
		DFS(x, y + 1);
		return true;
	}
	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	
	cin >> n >> m;
	// 2차원 리스트의 맵 정보 입력 받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	//모든 위치에 대하여 음료수 채우기
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (DFS(i, j)) {
				result += 1;
			}
		}
	}
	cout << result << '\n';
	return 0;
}