#include <iostream>
#include <algorithm>
using namespace std;

string a[20000];
int n;

bool compare(string a, string b) {
	// 길이가 짧은 순서 우선
	if (a.length() < b.length()) {
		return 1; // 우선순위를 높게 부여
	}
	else if (a.length() > b.length()) {
		return 0;
	}
	else {
		// 길이가 같은 경우
		return a < b; // 사전순으로 정렬한다.
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, compare);
	for (int i = 0; i < n; i++) {
		// 동일한 문자열에 대해서는 무시한다. (출력은 한 번만)
		if (i > 0 && a[i] == a[i - 1])
			continue;
		else
			cout << a[i] << '\n';
	}
	return 0;
}