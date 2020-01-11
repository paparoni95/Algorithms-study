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
	sort(coin.begin(), coin.end(), greater<int>()); //내림차순으로 정렬

	int cnt = 0;
	for (int i = 0; i < coin.size(); i++) { //가장 큰 동전으로부터 나눠본다.
		cnt += K / coin[i];
		K %= coin[i];
	}
	cout << cnt;
	return 0;
}
