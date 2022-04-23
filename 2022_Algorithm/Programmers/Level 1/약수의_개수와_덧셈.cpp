#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 약수 개수가 짝수면 더하고
// 약수 개수가 홀수면 빼고
int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i <= right; i++) {
        // 약수의 개수를 구하자.
        int cnt = 0;
        int j = 0;
        for(j = 1; j * j < i; j++) {
            if (i % j == 0) {
                cnt++;
            }
        }
        cnt *= 2;
        if (j * j == i) cnt++;
        answer += (cnt % 2 == 0) ? i : -i;
    }
    return answer;
}
