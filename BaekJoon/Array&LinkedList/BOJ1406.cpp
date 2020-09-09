#include <bits/stdc++.h>
using namespace std;

// 문제에서 문장 중간에 삭제와 삽입이 빈번하게 일어난다면 list를 사용하자.
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	string init;
	cin >> init;

	list<char> lt;
	for (auto c : init)
		lt.push_back(c);
	auto cursor = lt.end();

	int n;
	cin >> n;
	string temp;
	getline(cin, temp); // 입력 버퍼에 남아있는 개행문자 제거
	while (n--) {
		string op;
		getline(cin, op);
		if (op[0] == 'P') {
			lt.insert(cursor, op[2]); // cursor 앞에 삽입
		}
		else if (op[0] == 'L') {
			if (cursor != lt.begin())
				cursor--;
		}
		else if (op[0] == 'D') {
			if (cursor != lt.end())
				cursor++;
		}
		else {
			if (cursor != lt.begin()) {
				cursor--;
				cursor = lt.erase(cursor); // cursor는 다음 원소를 가리키게 됨
			}
		}
	}

	for (auto c : lt)
		cout << c;
	return 0;
}