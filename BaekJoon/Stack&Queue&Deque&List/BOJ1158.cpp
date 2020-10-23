#include <iostream>
#include <queue>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k, cnt = 0;
	cin >> n >> k;
	queue<int> q;
	for (int i = 0; i < n; i++) q.push(i + 1);
	cout << "<";
	while (q.size() >= 2) {
		int cur = q.front();
		q.pop();
		cnt++;
		if (cnt == k) {
			cnt = 0;
			cout << cur << ", ";
		}
		else q.push(cur);
	}
	cout << q.front() << ">\n";
	return 0;
}