#include <iostream>
#include <vector>
using namespace std;

int n;
bool vis[100001];
int parent[100001];
vector<int> v[100001];

void go(int cur) {
	vis[cur] = true;
	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (!vis[next]) {
			parent[next] = cur; //부모 설정
			go(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	go(1);
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
	return 0;
}