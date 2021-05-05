#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool prime[50001];
void eratosthenes() {
    prime[0] = true;
    prime[1] = true;
    for (int i = 2; i * i <= 50000; i++) {
        if (!prime[i]) {
            for (int j = i + i; j <= 50000; j += i) {
                prime[j] = true;
            }
        }
    }
}

int solution(vector<int> nums) {
    int answer = 0;

    eratosthenes();

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if (prime[nums[i] + nums[j] + nums[k]] == false) {
                    answer++;
                }
            }
        }
    }

    return answer;
}