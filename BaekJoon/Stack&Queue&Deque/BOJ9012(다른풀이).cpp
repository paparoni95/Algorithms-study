#include <bits/stdc++.h>
using namespace std;

/*
	여는 괄호가 나오면 push
	닫는 괄호가 나오면 다음을 고려해본다.
	스택이 비어있다면 잘못된 문자열,
	스택이 비어있지 않다면 다음을 고려한다.
	스택이 비어있지 않으면 스택의 꼭대기가 여는 괄호라면 pop,
	스택이 비어있지 않으면 스택의 꼭대기가 여는 괄호가 아니라면 잘못된 문자열

	모든 과정을 끝낸 뒤 스택에 문자열이 남아있다면 이 역시 잘못된 문자열이다.
*/

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string query;
		cin >> query;
		stack<int> st;
		for (auto c : query) {
			if (c == '(') st.push(c);
			else { // 닫는 괄호일 경우
				if (st.empty()) {
					st.push('x'); // stack에 쓰레기 값을 채워놓고 탈출
					break;
				}

				if (c == ')') {
					if (st.top() != '(') break;
				}
				st.pop();
			}
		} // end query

		if (st.empty()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}