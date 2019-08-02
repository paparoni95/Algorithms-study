#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {

		for (int blank = 0; blank < i; ++blank) {
			printf(" ");
		}

		for (int star = i; star < n; ++star) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}