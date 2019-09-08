#include <iostream>
#include <queue>
using namespace std;

int n, k;
int dist[100001];
bool check[100001];
const int MAX = 100000; // 최대로 갈 수 있는 위치

void bfs(int start) {
	queue<int> q;
	q.push(start);
	check[start] = true;
	dist[start] = 0;
	while (!q.empty()) {
		int pos = q.front();
		q.pop();

		// x + 1 이동
		if (pos + 1 <= MAX) {
			if (check[pos + 1] == false) {
				dist[pos + 1] = dist[pos] + 1;
				check[pos + 1] = true;
				q.push(pos + 1);
			}
		}
		// x - 1 이동
		if (pos - 1 >= 0) {
			if (check[pos - 1] == false) {
				dist[pos - 1] = dist[pos] + 1;
				check[pos - 1] = true;
				q.push(pos - 1);
			}
		}
		// x * 2 이동
		if (pos * 2 <= MAX) {
			if (check[pos * 2] == false) {
				dist[pos * 2] = dist[pos] + 1;
				check[pos * 2] = true;
				q.push(pos * 2);
			}
		}
	}
}

int main() {
	cin >> n >> k;
	bfs(n);
	cout << dist[k];
	return 0;
}