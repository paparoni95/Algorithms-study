#include <iostream>
#include <deque>
#include <queue>
using namespace std;

void MoveLeft(deque<int>& dq) {
	if (dq.empty()) return;
	int temp = dq.front();
	dq.pop_front();
	dq.push_back(temp);
}

void MoveRight(deque<int>& dq) {
	if (dq.empty()) return;
	int temp = dq.back();
	dq.pop_back();
	dq.push_front(temp);
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	deque<int> dq;
	queue<int> q;

	for (int i = 0; i < n; ++i)
		dq.push_back(i + 1);
	for (int i = 0; i < m; ++i) {
		int num;
		cin >> num;
		q.push(num);
	}

	int l = 0, r = 0, answer = 0;
	while (!q.empty()) {
		int find = q.front();
		int find_idx = 0;
		q.pop();

		for (int i = 0; i < dq.size(); ++i)
			if (find == dq[i])
				find_idx = i;

		if (find_idx == 0) {
			dq.pop_front();
			continue;
		}

		l = find_idx;
		r = dq.size() - find_idx;
		if (l > r) {
			answer += r;
			for (int i = 0; i < r; ++i) {
				MoveRight(dq);
			}
		}
		else {
			answer += l;
			for (int i = 0; i < l; ++i) {
				MoveLeft(dq);
			}
		}

		dq.pop_front();
	}

	cout << answer;
	return 0;
}
