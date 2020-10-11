#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> card;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	card.reserve(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		card.push_back(x);
	}
	sort(card.begin(), card.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		vector<int>::iterator sIter = lower_bound(card.begin(), card.end(), x);
		vector<int>::iterator eIter = upper_bound(card.begin(), card.end(), x);
		cout << eIter - sIter << ' ';
	}
	return 0;
}