#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int number = a * b * c;
	int arr[10] = { 0, }; // 0 ~ 9 까지 각 자리의 수
	int remain = 0;
	while (number) {
		remain = number % 10;
		number /= 10;
		arr[remain]++;
	}

	for (int i = 0; i < 10; i++)
		cout << arr[i] << '\n';
	return 0;
}