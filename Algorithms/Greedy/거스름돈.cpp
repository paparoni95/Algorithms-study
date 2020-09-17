#include <bits/stdc++.h>
using namespace std;

int n = 1260;
int cnt = 0;
int coinTypes[] = { 500,100,50,10 };

// 가장 큰 단위가 작은 단위의 배수 형태이므로, 그리디 가능

int main() {
	// '가장 큰 화폐 단위부터' 돈을 거슬러 주는 것
	for (int i = 0; i < 4; i++) {
		int coin = coinTypes[i];
		cnt += n / coin;
		n %= coin;
	}
	cout << cnt << '\n';
	return 0;
}