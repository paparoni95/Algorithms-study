#include <string>
#include <vector>
using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for (int n = left; n <= right; n++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) cnt++;
        }
        if (cnt % 2 == 0) answer += n;
        else answer -= n;
    }
    return answer;
}