#include <iostream>
using namespace std;

int n, r, c;

int z(int n, int r, int c) {
	if (n == 0) return 0;
	int half = 1 << (n - 1); // 한 변의 길이 반
	if (r < half && c < half) return z(n - 1, r, c);
	if (r < half && c >= half) return half * half + z(n - 1, r, c - half);
	if (r >= half && c < half) return 2 * half * half + z(n - 1, r - half, c);
	return 3 * half * half + z(n - 1, r - half, c - half);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> r >> c;
	cout << z(n, r, c);
	return 0;
}
