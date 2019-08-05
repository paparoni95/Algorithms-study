#include <iostream>
#define SIZE 1000001
using namespace std;

bool check[SIZE]; //소수이면 false, 아니면 true

void Eratosthenes() {
	check[0] = true;
	check[1] = true;

	for (int i = 2; i * i < SIZE; ++i) {
		if (!check[i]) {
			for (int j = i + i; j < SIZE; j += i) {
				check[j] = true;
			}
		}
	}
}

int main() {
	int M, N;
	cin >> M >> N;
	Eratosthenes(); //에라토스테네스의 체 적용
	for (int i = M; i <= N; ++i) {
		if (!check[i]) {
			cout << i << '\n';
		}
	}
	return 0;
}