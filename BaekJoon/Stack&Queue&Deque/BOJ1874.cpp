#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;

	stack<int> st;   // 숫자를 담을 공간
	vector<char> op; // +,-를 담을 공간
	queue<int> q;    // 입력 받은 숫자를 담을 공간(동시에 만들어야 하는 수)

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		q.push(x);
	}

	// 초기 작업
	int cur = 1;
	int size = q.front();
	for (int i = 0; i < size; i++) {
		st.push(cur++);
		op.push_back('+');
	}
	q.pop();
	st.pop();
	op.push_back('-');

	bool ok = true;
	while (!q.empty()) {
		int now = q.front();

		if (st.empty()) {
			st.push(cur++);
			op.push_back('+');
		}

		// 불가능한 경우(스택으로 해당 숫자를 만들 수 없는 경우)
		else if (st.top() > now) {
			ok = false;
			break;
		}

		else if (st.top() == now) {
			st.pop();
			q.pop();
			op.push_back('-');
		}
		
		else {
			st.push(cur++);
			op.push_back('+');
		}
	}

	if (ok) {
		for (auto c : op)
			cout << c << '\n';
	}
	else cout << "NO\n";
	return 0;
}