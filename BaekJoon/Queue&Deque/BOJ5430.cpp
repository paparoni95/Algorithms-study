#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		string str1, str2;
		int n;
		bool ok = true, dir = false;
		cin >> str1 >> n >> str2;
		deque<int> dq;

		if (n != 0) {
			string num = "";
			// 주어진 입력에서 숫자만 걸러내기
			for (int j = 1; j < str2.length() - 1; ++j) {
				if (str2[j] != ',')
					num += str2[j];
				else {
					dq.push_back(stoi(num));
					num.clear();
				}
			}
			dq.push_back(stoi(num));
		}
		// 명령에 따라 수행
		for (int j = 0; j < str1.length(); ++j) {
			if (str1[j] == 'R')
				dir = !dir;
			
			else if (str1[j] == 'D') {
				if (dq.empty()) {
					ok = false;
					break;
				}

				if (!dir)
					dq.pop_front();
				else
					dq.pop_back();
			}
		}

		// 출력
		if (ok == true && !dq.empty()) {
			if (!dir) {
				cout << "[" << dq[0];
				for (int j = 1; j < dq.size(); ++j) {
					cout << "," << dq[j];
				}
				cout << "]\n";
			}
			else {
				cout << "[" << dq[dq.size() - 1];
				for (int j = dq.size() - 2; j >= 0; --j) {
					cout << "," << dq[j];
				}
				cout << "]\n";
			}
		}
		else if (ok == true && dq.empty()) {
			cout << "[]\n";
		}
		else {
			cout << "error\n";
		}
	}
	return 0;
}