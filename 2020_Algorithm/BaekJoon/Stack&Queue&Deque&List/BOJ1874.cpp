#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	stack<int> s;
	vector<char> answer;
	int num = 1;
	bool ok = true;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		
		if (!s.empty() && s.top() == x) {
			s.pop();
			answer.push_back('-');
			continue;
		}
		if (!s.empty() && s.top() > x) {
			ok = false;
			break;
		}

		while (num <= x) {
			s.push(num++);
			answer.push_back('+');
		}
		s.pop();
		answer.push_back('-');
	}

	if (!ok) cout << "NO\n";
	else {
		for (auto c : answer) {
			cout << c << '\n';
		}
	}

	return 0;
}