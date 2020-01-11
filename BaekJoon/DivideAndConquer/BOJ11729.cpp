#include <iostream>
#include <cmath>
using namespace std;

// 참조 링크 : https://m.blog.naver.com/PostView.nhn?blogId=puri8467&logNo=221440092130&proxyReferer=https%3A%2F%2Fwww.google.com%2F

// from 현재의 위치, by는 거쳐가는 위치, to는 도착 위치
// n은 옮겨야하는 원반의 개수
// 재귀로 구현하면
void HanoiTower(int from, int by, int to, int n) {
	// 옮겨야하는 원반의 개수가 0이면 다 옮긴것이므로 (종료 조건)
	if (n == 0) return;

	// n개의 원반이 있을 때, n-1개의 원반은 1 -> 2 이동
	HanoiTower(from, to, by, n - 1);
	// 가장 밑에있는 1개의 원반을 1 -> 3 이동
	cout << from << " " << to << '\n';
	// n-1개의 원반을 2 -> 3 이동
	HanoiTower(by, from, to, n - 1);
}



int main() {
	int k;
	cin >> k;
	// N 개의 탑을 옮기기 위해서는 최소한 몇번?
	// 가장 큰 N+1의 원반을 옮기기 위해서는 N개의 원판을 다른 곳으로 옮긴다.
	// N개의 원판을 1 -> 2로 옮기는 수를 F(n)번이라고 하면,
	// N+1의 원판을 1 -> 3로 옮기는 수는 1번이다.
	// N개의 원판을 2 -> 3로 옮기는 수는 F(n)번이다.

	// 따라서 다음과 같은 점화식을 만들 수 있다.
	// F(n+1) = 2 * F(n) + 1
	// F(n)의 일반항을 구하기 위해서는 계차 수열을 이용해서 해결한다.
	// An = A1(첫째항) + (1 ~ N - 1)까지의 등비수열의 합을 이용한다.
	// F(n) = 2^N - 1

	cout << ((int)pow(2.0, (float)k)) - 1 << '\n';
	HanoiTower(1, 2, 3, k);
	return 0;
}