#include <iostream>
#include <vector>
using namespace std;

vector<int> a[20001];
int check[200001];

// 방문하지 않았으면 0
// 그룹 A는 1로 색칠
// 그룹 B는 2로 색칠
void dfs(int node, int color) {
	check[node] = color;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == 0) {
			dfs(next, 3 - color);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int v, e;
		cin >> v >> e;
		// 초기화
		for (int i = 1; i <= v; i++) {
			a[i].clear();
			check[i] = 0;
		}
		// 그래프 연결표시
		for (int i = 0; i < e; i++) {
			int u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		// 색칠하기
		for (int i = 1; i <= v; i++) {
			if (check[i] == 0) {
				dfs(i, 1);
			}
		}

		// 이 그래프가 이분그래프인지 확인
		// 정점 a에서 다음 정점은 a와 색이 달라야한다.
		// 만약에 같으면 이 그래프는 이분그래프가 아니다.
		bool ok = true;
		for (int i = 1; i <= v; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				int next_node = a[i][j];
				if (check[i] == check[next_node]) {
					ok = false;
				}
			}
		}

		if (ok)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}