#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<string> v;
bool cmp(string& a, string& b) {
	if (a.size() == b.size()) {
		int a_sum = 0;
		int b_sum = 0;
		for (char c : a) {
			if (isdigit(c)) a_sum += c - '0';
		}
		for (char c : b) {
			if (isdigit(c)) b_sum += c - '0';
		}

		if (a_sum == b_sum) return a < b;
		else return a_sum < b_sum;
	}
	return a.size() < b.size();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	v.reserve(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), cmp);
	for (string s : v) {
		cout << s << '\n';
	}
	return 0;
}