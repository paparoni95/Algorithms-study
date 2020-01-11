#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, v;
	cin >> a >> b >> v;
	
	if (a == v) {
		cout << 1;
	}
	else {
		// n+1 번째 날에 나무 위에 달팽이가 도달한다고 가정하면,
		// n번째 까지의 이동거리는 n * (a - b)
		// n+1 번째 낮에 이동거리는 a
		// n * (a - b) + a >= v이면 등반할 수 있다.
		// 위의 n은 n+1일 까지로 구한것이므로 n-1을 대입한다.
		// 그리고 n에 대해서 정리하면 다음과 같다.
		double d1 = v - a;
		double d2 = a - b;
		cout << static_cast<int>(ceil(d1 / d2) + 1);
	}
	return 0;
}