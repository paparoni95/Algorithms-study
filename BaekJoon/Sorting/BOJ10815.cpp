#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, x;
vector<int> card;

void binarySearch(int start, int end, int target) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (card[mid] == target) {
			cout << 1 << ' ';
			return;
		}
		else if (card[mid] > target) end = mid - 1;
		else start = mid + 1;
	}
	cout << 0 << ' ';
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	card.reserve(n);
	for (int i = 0; i < n; i++) {
		cin >> x;
		card.push_back(x);
	}
	sort(card.begin(), card.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		binarySearch(0, card.size() - 1, x);
	}
	return 0;
}