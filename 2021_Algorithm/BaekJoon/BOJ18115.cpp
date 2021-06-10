#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int card = 1;
	deque<int> dq;
	for (int i = n - 1; i >= 0; i--) {
		if (v[i] == 1) dq.push_front(card);
		else if (v[i] == 2) {
			int memo = dq.front();
			dq.pop_front();
			dq.push_front(card);
			dq.push_front(memo);
		}
		else if (v[i] == 3) dq.push_back(card);
		card++;
	}

	while (!dq.empty()) {
		cout << dq.front() << ' ';
		dq.pop_front();
	}
	return 0;
}