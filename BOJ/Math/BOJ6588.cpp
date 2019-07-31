#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX_SIZE 1000000
using namespace std;

bool check[MAX_SIZE]; //소수가 아닌 수는 지움 (false는 소수, true는 소수가 아닌 수)

//에라토스테네스의 체
void eratosthenes() {
	check[1] = true;
	for (int i = 2; i * i < MAX_SIZE; i++) {
		if (check[i] == false) {
			for (int j = i * i; j < MAX_SIZE; j += i) {
				check[j] = true;
			}
		}
	}
}

void goldBach(int n) {
	for (int i = 0, j = n; i <= n / 2; i++, j--) {
		//두 수는 홀수이면서, 동시에 소수여야 한다.
		if (i % 2 == 1 && j % 2 == 1 && !check[i] && !check[j]) {
			printf("%d = %d + %d\n", n, i, j);
			return;
		}
	}
	printf("Goldbach's conjecture is wrong.\n");
}

int main() {
	eratosthenes(); //100만까지의 수 중에서 소수를 찾는다.

	while (true) { //문제를 해결한다.
		int n;
		scanf("%d", &n);
		if (n == 0) break;
		goldBach(n);
	}
	return 0;
}
