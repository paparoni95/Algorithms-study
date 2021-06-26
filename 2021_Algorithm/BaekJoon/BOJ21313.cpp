#include <iostream>
#include <vector>
using namespace std;

// greedy
// 문어를 톱니바퀴로 생각하면 쉽다.
// 인접한 톱니바퀴는 서로 번호가 달라야 한다.
// 따라서 처음 톱니바퀴와 마지막 톱니바퀴 또한 달라야하므로
// 짝수는 1,2,1,2
// 홀수는 1,2,1,2 하다가 마지막에는 3으로 해주면 사전순으로 제일 빠르다.
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	if (n % 2 == 0) {
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) 
				cout << "1 ";
			else 
				cout << "2 ";
		}
		cout << '\n';
	}
	else {
		for (int i = 0; i < n - 1; i++) {
			if (i % 2 == 0)
				cout << "1 ";
			else
				cout << "2 ";
		}
		cout << "3\n";
	}
	return 0;
}