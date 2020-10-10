#include <iostream>
using namespace std;

int n, m, card = 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		num = (num == 0) ? 1 : num; // 카드덱을 들고 오지 않았으면 주최측에서 부여
		card = (card * num) % m;    // 답이 매우 클 수 있기 때문에 m으로 나눠준다.
	}

	cout << card % m << '\n';
	return 0;
}