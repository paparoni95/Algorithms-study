#include <iostream>
#include <queue>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	queue<int> q;
	for (int i = 0; i < n; ++i)
		q.push(i + 1);

	while (q.size() != 1) {
		q.pop();
		int kard = q.front();
		q.pop();
		q.push(kard);
	}

	cout << q.front();
	return 0;
}