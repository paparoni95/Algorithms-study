#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
vector<int> v;
stack<int> st1, st2;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (int i = n - 1; i >= 0; i--) st1.push(v[i]);
	int ticket = 1;
	bool ok = true;
	while (ticket != n) {
		if (!st1.empty() && st1.top() == ticket) {
			ticket++;
			st1.pop();
		}
		else if (!st2.empty() && st2.top() == ticket) {
			ticket++;
			st2.pop();
		}
		else if (!st1.empty()) {
			st2.push(st1.top());
			st1.pop();
		}
		else {
			ok = false;
			break;
		}
	}

	if (ok)
		cout << "Nice\n";
	else
		cout << "Sad\n";
	return 0;
}