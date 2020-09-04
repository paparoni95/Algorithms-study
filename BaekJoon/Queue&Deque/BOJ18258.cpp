#include <iostream>
#include <queue>
using namespace std;

// 아래에 나와있는 연산들은 모두 O(1) 시간복잡도

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	queue<int> q;
	int n;
	cin >> n;

	string str;
	int x;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		if (str == "push") {
			cin >> x;
			q.push(x);
		}
		else if (str == "pop") {
			if (q.empty())
				cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (str == "size") {
			cout << q.size() << "\n";
		}
		else if (str == "empty") {
			cout << q.empty() << "\n";
		}
		else if (str == "front") {
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.front() << "\n";
		}
		else if (str == "back") {
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.back() << "\n";
		}
	}

	return 0;
}
