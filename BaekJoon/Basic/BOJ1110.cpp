#include <iostream>
using namespace std;

int new_number;
int temp;
int old_first, old_second;

int PlusCycle(int target) {
	// 10보다 작으면 앞에 0을 붙여준다.
	if (target < 10) {
		// 만약에 1이면 01이 된다.
		// 이 때 target은 일의 자리이므로
		old_first = 0;
		old_second = target;

		temp = old_first + old_second;
		new_number = old_second * 10 + temp % 10;
	}
	else {
		// 계산을 한 번 해주고 반복문에 들어간다.
		// 주어진 수의 각 자리 숫자를 구한다.
		old_first = target / 10;
		old_second = target % 10;

		temp = old_first + old_second;
		// 새로운 수는  주어진 수의 일의 자리와, 각 자리의 숫자의 합을 이어붙인다.
		new_number = old_second * 10 + temp % 10;
	}

	return new_number;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cycle_length = 1;
	int target;
	cin >> target;

	new_number = PlusCycle(target);

	//cout << new_number << endl;

	while (new_number != target) {
		cycle_length++; // 더하기 사이클의 수를 늘린다.

		new_number = PlusCycle(new_number);
		//cout << new_number << endl;
	}
	cout << cycle_length;
	return 0;

}