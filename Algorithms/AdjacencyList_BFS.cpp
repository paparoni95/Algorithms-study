#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool check[8];
vector<int> a[8]; // 노드의 시작을 1부터

void bfs(int start) {
	queue<int> q;
	q.push(start);
	check[start] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (int i = 0; i < a[cur].size(); i++) {
			int next = a[cur][i];
			if (!check[next]) {
				q.push(next);
				check[next] = true;
			}
		}
	}
}

int main() {
	a[1].push_back(2);
	a[2].push_back(1);

	a[1].push_back(3);
	a[3].push_back(1);

	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[4].push_back(5);
	a[5].push_back(4);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	a[6].push_back(7);
	a[7].push_back(6);

	bfs(1);
	return 0;
}