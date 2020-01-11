#include <iostream>
#include <string>
using namespace std;

int main() {
	string ox;
	int tc;

	cin >> tc;

	int total_point = 0; // 누적 합산
	int stack_point = 1; // 쌓이는 포인트

	for (int test_case = 0; test_case < tc; test_case++) {
		cin >> ox;
		total_point = 0;
		stack_point = 1;

		int length = ox.length();
		for (int i = 0; i < length; i++) {
			if (ox[i] == 'O') {
				total_point += stack_point;
				stack_point++;
			}
			else {
				stack_point = 1;
			}
		}
		cout << total_point << '\n';
	}
	return 0;
}