#include <string>
#include <vector>
using namespace std;

bool prime[1000001];
void eratosthenes() {
    prime[0] = true;
    prime[1] = true;
    for (int i = 2; i * i <= 1000000; i++) {
        if (prime[i] == false) {
            for (int j = i + i; j <= 1000000; j += i) {
                prime[j] = true;
            }
        }
    }
}

int solution(int n) {
    int answer = 0;
    eratosthenes();
    for (int i = 1; i <= n; i++) {
        if (prime[i] == false) answer++;
    }
    return answer;
}