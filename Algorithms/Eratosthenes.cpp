#include <iostream>
using namespace std;

// 소수를 대량으로 빠르고 정확하게 구하는 알고리즘
// O(NloglogN)
bool prime[100001];

void eratosthenes() {
	prime[1] = true;
	
	// 아직 지워지지 않은 수 중에서 가장 작은 수를 찾고,
	for (int i = 2; i <= 1000000; i++) {
		// 그 수가 소수라면
		if (prime[i] == false){
			// 그 수의 배수들을 모두 지운다.
			for(int j = i + i; j <= 1000000; j += i){
				prime[j] = true;
			}
		}
	}
	
	/* 출력 */
	for (int i = 2; i <= 100000; i++) {
		if (prime[i])
			cout << prime[i] << ' ';
	}
}

int main() {
	eratosthenes();
	return 0;
}
