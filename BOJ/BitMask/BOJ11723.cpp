#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int s;

void add(int x) {
	// s에 x를 추가한다. (이미 있다면 무시)
	s = s | (1 << x);
}

void remove(int x) {
	// s에서 x를 제거한다. (없는 경우 무시)
	s = s & ~(1 << x);
}

int check(int x) {
	// s에 x가 있으면 1을, 없으면 0을 출력
	int temp = s & (1 << x);
	if (temp == 0)
		return 0;
	else
		return 1;
}

void toggle(int x) {
	// s에 x가 있으면 x를 제거, 없으면 x를 추가
	// 이말은 1 -> 0, 0 -> 1
	s = s ^ (1 << x);
}

void all() {
	// s를 전체 집합으로 한다.
	// 모두 있다고 설정
	s = (1 << 22) - 1;
}

void empty() {
	// s를 공집합으로 바꾼다.
	s = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> m;
	for (int tc = 0; tc < m; tc++) {
		string command;
		int x;
		cin >> command;
		
		if (command[0] == 'a') {
			if (command[1] == 'd') {
				cin >> x;
				add(x);
			}
				
			else {
				all();
			}
				
		}
		else if (command[0] == 'r') {
			cin >> x;
			remove(x);
		}
		else if (command[0] == 'c') {
			cin >> x;
			cout << check(x) << '\n';
		}
		else if (command[0] == 't') {
			cin >> x;
			toggle(x);
		}
		else
			empty();
	}

	return 0;
}