#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 20001;
int k, v, e;
int color[MAX]; // 0: 방문x, 1: A그룹, 2: B그룹
void DFS(const vector<vector<int>>& adj, int start, int c) {
	color[start] = c;
	for (int i = 0; i < adj[start].size(); ++i) {
		int next = adj[start][i];
		if (color[next] == 0) {
			DFS(adj, next, 3 - c);
		}
	}
}

// 해당 그래프가 이분 그래피인지 판별
bool CheckBipartiteGraph(const vector<vector<int>>& adj) {
	for (int i = 1; i <= v; ++i) {
		for (int j = 0; j < adj[i].size(); ++j) {
			int node = adj[i][j];
			if (color[i] == color[node])
				return false;
		}
	}
	return true;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> k;
	for (int test_case = 0; test_case < k; ++test_case) {
		cin >> v >> e;
		vector<vector<int>> adj(v + 1);
		memset(color, 0, sizeof(color));
		for (int i = 0; i < e; ++i) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		for (int i = 1; i <= v; ++i) {
			if (color[i] == 0) {
				DFS(adj, i, 1);
			}
		}

		cout << (CheckBipartiteGraph(adj) == true ? "YES" : "NO") << '\n';
	}
	return 0;
}