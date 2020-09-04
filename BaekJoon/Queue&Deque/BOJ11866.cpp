#include <iostream>
#include <queue>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 0; i < n; ++i)
		q.push(i + 1);

	vector<int> answer;
	while (!q.empty()) {
		for (int i = 0; i < k - 1; ++i) {
			int num = q.front();
			q.pop();
			q.push(num);
		}
		answer.push_back(q.front());
		q.pop();
	}

	cout << "<" << answer[0];
	for (int i = 1; i < answer.size(); ++i) {
		cout << ", " << answer[i];
	}
	cout << ">\n";
	return 0;
}