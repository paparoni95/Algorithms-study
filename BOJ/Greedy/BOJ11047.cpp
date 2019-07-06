#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> coin;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		coin.push_back(a);
	}
	sort(coin.begin(), coin.end(), greater<int>()); //내림차순
	/*
	int idx = 0, cnt = 0, tmp = 0;
	while (K) {
		if (K >= coin[idx]) {
			tmp = K / coin[idx];
			K = K - tmp * coin[idx];
			cnt += tmp;
		}
		idx++;
	}
	cout << cnt;
	*/
	int cnt = 0;
	for (int i = 0; i < coin.size(); i++) {
		cnt += K / coin[i];
		K %= coin[i];
	}
	cout << cnt;
	return 0;
}