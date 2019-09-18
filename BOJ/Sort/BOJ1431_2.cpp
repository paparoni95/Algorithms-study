#include <iostream>
#include <algorithm>
using namespace std;

string a[1001];
int n;

int get_sum(string a) {
	int length = a.length();
	int sum = 0;
	for (int i = 0; i < length; i++) {
		// 숫자인 경우에만 더하자.
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0)
			sum += (a[i] - 48);
	}
	return sum;
}

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
		int a_sum = get_sum(a);
		int b_sum = get_sum(b);
		// 두 문자열의 숫자의 합을 비교해서
		if (a_sum != b_sum)
			return a_sum < b_sum; // 더 작은 순서로
		else
			return a < b; // 사전순
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